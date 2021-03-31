#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Needs 1 argument, card.raw!\n");
        return 1;
    }
    //unsigned char in C gives you the positive value of the array
    unsigned char buffer[512];
    
    //photo represents the array of the raw file 
    char photo[8];
    
    // Input file   
    FILE *raw = fopen(argv[1], "r");
    
    // Output file image pointer
    FILE *image = NULL;
    
    //This is the counter that will keep track of the photos
    int counter = 0;
    
    //fread takes 4 arguments the array, the bytes of the array, the number of files and the raw data.
    while (fread(buffer, 512, 1, raw))
    {
        //jpg files begin with these hexidecimal
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //If there is an image close it.
            if (image)
            {
                fclose(image);
            }
            sprintf(photo, "%03i.jpg", counter);
            image = fopen(photo, "w");
            counter++;
        }
        //If there is an image write to the new file called image
        if (image)
        {
            fwrite(buffer, 512, 1, image);
        }
    }
    //Clase image, close raw data and exit program.
    fclose(image);
    fclose(raw);
    return 0;
}
