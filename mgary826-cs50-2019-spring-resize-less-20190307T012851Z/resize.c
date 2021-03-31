// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Needs 4 arguments!\n");
        return 1;
    }
    
    // Make sure that the factor is a number between 0 and 100.
    
    
    // remember filenames
    int factor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];
    
    if (factor < 1 || factor > 100)
    {
        printf("Please input an integer between 1 and 100!");
        return 1;
    }
    
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
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
        return 4;
    }
    
    
    //Set the new width and height and the old width and height.
    int old_biWidth = bi.biWidth;
    int old_biHeight = bi.biHeight;
    bi.biWidth  = bi.biWidth * factor;
    bi.biHeight = bi.biHeight * factor;
    
    // determine padding for scanlines
    int padding = (4 - (old_biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // determine new padding
    int new_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // New bfSize and bfSixeImage
    bi.biSizeImage = (((sizeof(RGBTRIPLE) * bi.biWidth) + new_padding) * abs(bi.biHeight)); 
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, absheight = abs(old_biHeight); i < absheight; i++)
    {
        // This copies each scanline and repeats it underneath "factor" number of times
        for (int y = 0; y < factor; y++)
        {
            // This loop expands an entire line.
            for (int j = 0; j < old_biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write RGB triple to outfile
                    
                // This Loop for x to writes the new pixel.    
                for (int x = 0; x < factor; x++) 
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            //then add it back (to demonstrate how)
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }
            if (y < factor - 1)
            {
                fseek(inptr, -old_biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }
        }
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
