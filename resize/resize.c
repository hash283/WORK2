/**
 * resizes a bmp image by an integer factor
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    int factor=atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    if(factor<0 || factor>100)
    {
        fprintf(stderr,"resizing factor incorrect\n");
        return 2;
    }
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    int inWidth=bi.biWidth;
    int inHeight=bi.biHeight;
    bi.biWidth=bi.biWidth*factor;
    bi.biHeight=bi.biHeight*factor;
    // determine padding for scanlines
    int padding1 = (4 - (inWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding2 = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage=((sizeof(RGBTRIPLE)*bi.biWidth)+padding2)*abs(bi.biHeight);
    bf.bfSize=bi.biSizeImage+sizeof(BITMAPINFOHEADER)+sizeof(BITMAPFILEHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, beHeight = abs(inHeight); i <beHeight; i++)
    {
        for(int z=1;z<=factor;z++)
        {
            // iterate over pixels in scanline
        for (int j = 0; j < inWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            for(int l=0;l<factor;l++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding2; k++)
        {
            fputc(0x00, outptr);
        }
        if(z!=factor)
            fseek(inptr,-(inWidth*sizeof(RGBTRIPLE)),SEEK_CUR);
        }
           // skip over padding, if any
        fseek(inptr, padding1, SEEK_CUR);
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
