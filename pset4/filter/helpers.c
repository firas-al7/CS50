#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <cs50.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int e; // an extra integer;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0); // get the average;
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg; // equality to get gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int e;
    int sepiaRed; // integer for the Red equation
    int sepiaGreen; // integer for the Green equation
    int sepiaBlue; // integer for Blue equation

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // the equation to get sepia
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed <= 255) // statment to show that the maximum hexa is 255;
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            if (sepiaGreen <= 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (sepiaBlue <= 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE e; // a RGBTRIPLE struct called e
    int e2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // we divide by 2 because we are swapping the half of the width by other half
        {
            // in  swapping we need another variable to save the other variables.
            e = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - 1 - j] = e;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE AVG; // the final answer in this variable
    RGBTRIPLE image2[height][width]; // a 2D array just to get the final answer and add to the main image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Green = 0; // integer to get average for Green colour;
            int Red = 0; // an integer to get average for Red colour;
            int Blue = 0; // an integer to get average for Blue colour;
            int N = 0; // for getting the number to get AVG of the pixels
            for (int k = -1; k <= 1; k++) // a for loop to determine the pixels behind and around the current pixel
            {
                for (int p = -1; p <= 1; p++)
                {
                    int i2 = i + k;
                    int j2 = j + p;
                    // an statment to show that i and j variables shouldnt be less than 0 or be nagative in other word
                    if (i2 >= 0 && i2 < height && j2 >= 0 && j2 < width)
                    {
                        N++; // showing the numbers of pixels concluding the main pixel, around the main pixel
                        Red = Red + image[i2][j2].rgbtRed; // adding the pixels
                        Green = Green + image[i2][j2].rgbtGreen; // adding the pixels
                        Blue = Blue + image[i2][j2].rgbtBlue; // adding the pixels
                    }
                }
            }
            AVG.rgbtRed = round((float) Red / N); // AVG for red
            AVG.rgbtGreen = round((float) Green / N); // AVG for Green
            AVG.rgbtBlue = round((float) Blue / N); //  AVG for Blue
            image2[i][j] = AVG; // saving the AVG into the secondary image
        }
    }
    // a for loop to save the secondary image to the main image;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image2[i][j];
        }
    }
}
