/**
 * Copies a BMP piece by piece, just because.
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
    double factor=atof(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    if(factor<0.0 || factor>100.0)
    {
        fprintf(stderr,"resizing factor incorrect");
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
    int padding1 = (4 - (inWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding2 = (4 - (bi.biWidth* sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage=(bi.biWidth*sizeof(RGBTRIPLE)+padding2)*abs(bi.biHeight);
    bf.bfSize=bi.biSizeImage+sizeof(BITMAPINFOHEADER)+sizeof(BITMAPFILEHEADER);
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    if(factor>=1.0)
    {
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(inHeight); i < biHeight; i++)
    {
        for(int z=1;z<=(int)factor;z++)
        {
        // iterate over pixels in scanline
        for (int j = 0; j < inWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            for(int l=0;l<(int)factor;l++)
            {
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }
        if((z%(int)factor)!=0)
            fseek(inptr,-(inWidth*sizeof(RGBTRIPLE)),SEEK_CUR);

        for (int k = 0; k < padding2; k++)
        {
            fputc(0x00, outptr);
        }
        }
        // skip over padding, if any
        fseek(inptr, padding1, SEEK_CUR);
    }
    }
    else if(factor<1.0)
    {
        for(int a=0;a<abs(bi.biHeight);a++)
        {
            for(int b=0;b<bi.biWidth;b++)
            {
                RGBTRIPLE triple2;
                fread(&triple2,sizeof(RGBTRIPLE),1,inptr);
                fwrite(&triple2,sizeof(RGBTRIPLE),1,inptr);
                fseek(inptr,(bi.biWidth*sizeof(RGBTRIPLE)),SEEK_CUR);
            }
            for(int k=0;k<padding2;k++)
            {
                fputc(0x00,outptr);
            }
            fseek(inptr,-(inWidth*sizeof(RGBTRIPLE)),SEEK_CUR);
            for(int c=0;c<abs(bi.biHeight);c++)
            {
                fseek(inptr,(inWidth*sizeof(RGBTRIPLE)),SEEK_CUR);
                fseek(inptr,padding1,SEEK_CUR);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
