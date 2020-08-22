#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgbit = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            newRed =  round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            newGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            newBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            if (newRed > 255)
            {
                image[i][j].rgbtRed  = 255;
            }
            else
            {
                image[i][j].rgbtRed = newRed;
            }


            if (newGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = newGreen;
            }

            if (newBlue > 255)
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
    for (int i = 0; i < height; i++)
    {
        int mid = floor(width / 2);
        int temp;
        for (int j = 0; j < mid; j++)
        {
            //have to alter the code below because the image is a struc and you have to access the individual RGB values
            temp = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = temp;

            //Green
            temp = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = temp;

            //Blue
            temp = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = temp;
        }
    }
    return;
}

// Blur image
// this function has a problem because I am changing pixel values and calculations are being perfromed on these changes values
//I believe a workaround is to create a copy of the image from where the calculations are done and then changing the acutal picture
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //lets start by making a copy of the image
    RGBTRIPLE *imageCopy = malloc(height * width * 3);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            imageCopy[i][j].rgbtRed = image[i][j].rgbtRed;
            imageCopy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            imageCopy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }



    //old solution
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // what is the average red value for all the surrounding pixels?
            int count_pixels = 0;
            //image[i][j]
            int total_red = image[i][j].rgbtRed;
            count_pixels++;

            if (0 <= j - 1 && j - 1 < width)
            {
                total_red += image[i][j - 1].rgbtRed;
                count_pixels++;
            }

            if (0 <= j+1 && j+1 < width)
            {
                total_red += image[i][j+1].rgbtRed;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j+1 && j+1 < width))
            {
                total_red += image[i-1][j+1].rgbtRed;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j-1 && j-1 < width))
            {
                total_red += image[i-1][j-1].rgbtRed;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j < width))
            {
                total_red += image[i-1][j].rgbtRed;
                count_pixels++;
            }

            if ((0 <= i+1 && i+1 < height) && (0 <= j < width))
            {
                total_red += image[i+1][j].rgbtRed;
                count_pixels++;
            }

            if ((0 <= i+1 && i+1 < height) && (0 <= j-1 && j-1 < width))
            {
                total_red += image[i+1][j-1].rgbtRed;
                count_pixels++;
            }

            if ((0 <= i+1 && i+1 < height) && (0 <= j+1 && j+1 < width))
            {
                total_red += image[i+1][j+1].rgbtRed;
                count_pixels++;
            }

            int avgRed = round(total_red / count_pixels);
            image[i][j].rgbtRed = avgRed;

            //Green
            count_pixels = 0;
            int total_green = image[i][j].rgbtGreen;
            count_pixels++;

            if (0 <= j-1 && j-1 < width)
            {
                total_green += image[i][j-1].rgbtGreen;
                count_pixels++;
            }

            if (0 <= j+1 && j+1 < width)
            {
                total_green += image[i][j+1].rgbtGreen;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j+1 && j+1 < width))
            {
                total_green += image[i-1][j+1].rgbtGreen;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j+1 && j+1 < width))
            {
                total_green += image[i-1][j+1].rgbtGreen;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j < width))
            {
                total_green += image[i-1][j].rgbtGreen;
                count_pixels++;
            }

            if (0 <= i+1 && i+1 < height)
            {
                total_green += image[i+1][j].rgbtGreen;
                count_pixels++;
            }

            if ((0 <= i+1 && i+1 < height) && (0 <= j-1 && j-1 < width))
            {
                total_green += image[i+1][j-1].rgbtGreen;
                count_pixels++;
            }

            if ((0 <= i+1 && i+1 < height) && (0 <= j+1 && j+1 < width))
            {
                total_green += image[i+1][j+1].rgbtGreen;
                count_pixels++;
            }

            int avgGreen = round(total_green / count_pixels);
            image[i][j].rgbtGreen = avgGreen;

            //Blue
            count_pixels = 0;
            int total_blue = image[i][j].rgbtBlue;
            count_pixels++;

            if (0 <= j-1 && j-1 < width)
            {
                total_blue += image[i][j-1].rgbtBlue;
                count_pixels++;
            }

            if (0 <= j+1 && j+1 < width)
            {
                total_blue += image[i][j+1].rgbtBlue;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j+1 && j+1 < width))
            {
                total_blue += image[i-1][j+1].rgbtBlue;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j-1 && j-1 < width))
            {
                total_blue += image[i-1][j-1].rgbtBlue;
                count_pixels++;
            }

            if ((0 <= i-1 && i-1 < height) && (0 <= j < width))
            {
                total_blue += image[i-1][j].rgbtBlue;
                count_pixels++;
            }

            if ((0 <= i+1 && i+1 < height) && (0 <= j < width))
            {
                total_blue += image[i+1][j].rgbtBlue;
                count_pixels++;
            }

            if ((0 <= i+1 && i+1 < height) && (0 <= j-1 && j-1 < width))
            {
                total_blue += image[i+1][j-1].rgbtBlue;
                count_pixels++;
            }

            if ((0 <= i+1 && i+1 < height) && (0 <= j+1 && j+1 < width))
            {
                total_blue += image[i+1][j+1].rgbtBlue;
                count_pixels++;
            }

            int avgBlue = round(total_blue / count_pixels);
            image[i][j].rgbtBlue = avgBlue;


        }
    }
    return;
}
