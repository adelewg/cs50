#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int avgbit = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3);
            image[i][j].rgbtRed = avgbit;
            image[i][j].rgbtBlue = avgbit;
            image[i][j].rgbtGreen = avgbit;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed;
    int originalGreen;
    int originalBlue;

    int newRed;
    int newGreen;
    int newBlue;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++ )
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtBlue;
            originalBlue = image[i][j].rgbtGreen;

            newRed =  round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            newGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            newBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            if(newRed > 255)
            {
                image[i][j].rgbtRed  = 255;
            }
            else
            {
                image[i][j].rgbtRed = newRed;
            }


            if(newGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = newGreen;
            }

            if(newBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = newBlue;
            }


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        int mid = floor(width/2);
        int temp;
        for(int j = 0; j < mid; j++)
        {
            //have to alter the code below because the image is a struc and you have to access the individual RGB values
            temp = image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
