#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    //Ensure that the user ran the program with two words
    if (argc != 2)
    {
        printf("command line is incorrect/n");
        return 1;
    }

    //open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        return 1;
    }

    int count = 0;
    char imagename[8];
    bool iswriting = false;


    //read from the memory card in 512 byte chunks - read it into a buffer
    unsigned char buffer[512];
    //initializing the pointer to the image
    FILE *img;

    while (fread(buffer, 512, 1, card) > 0)
    {


        //check the first 4bytes to see if its the start of a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {


            //make a new jpeg file if we are not currently writing to a jpeg file
            //this is the first ever jpeg we are writing
            if (iswriting == false)
            {
                sprintf(imagename, "%03i.jpg", count);
                count ++;
                img = fopen(imagename, "w");
                fwrite(buffer, 512, 1, img);
                iswriting = true;
            }

            //lets check if we are already wrting to a jpeg in which case we need to close the file we are currently writing to, iswriting == true
            //if (iswriting == true)
            else
            {
                fclose(img);
                //open a new jpg and start writing to it
                sprintf(imagename, "%03i.jpg", count);
                count ++;
                img = fopen(imagename, "w");
                fwrite(buffer, 512, 1, img);
                iswriting = true;
            }

        }

        //if its not the start of a new image and we are currently writing to a jpeg file, we need to keep writing until we find a new jpeg file. So I think I need to add
        //another condition here to check that we have not found the start of a new jpeg file
        else
        {
            if (iswriting == true)
            {
                //we need to continue writing to the current opened jpeg file
                fwrite(buffer, 512, 1, img);
            }

        }

    }



    fclose(card);
    fclose(img);



}
