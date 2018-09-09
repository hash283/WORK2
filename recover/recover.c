#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include "bmp.h"
int main(int argc,char *argv[])
{
    char outfile[8];
    int n=0;
    if(argc!=2)
    {
        fprintf(stderr,"usage ./recover filename\n");
        return 1;
    }
    char *infile=argv[1];
    FILE *input=fopen(infile,"r");
    if(input==NULL)
    {
        fprintf(stderr,"Could not find file\n");
        return 2;
    }
    BYTE *buffer=malloc(512);
    if(buffer == NULL)
        fprintf(stderr,"Cannot allocate memory\n");
    while(fread(buffer,512,1,input)==1)
    {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0)
            {
                sprintf(outfile,"%03i.jpg",n);
                FILE *output=fopen(outfile,"w");
                while(true)
                {
                    fwrite(buffer,512,1,output);
                    if(fread(buffer,512,1,input)==1)
                    {
                        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0)
                         {
                          n++;
                          fclose(output);
                          fseek(input,-512,SEEK_CUR);
                          break;
                         }
                    }
                    else
                    {
                        fclose(output);
                        break;
                    }
                }
            }
    }
    free(buffer);
    fclose(input);
    return 0;
}

