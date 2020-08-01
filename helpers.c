#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // For loop to set the value of i, rows or height
    for (int i = 0; i < height; i++)
    {
        // For loop to set the value of j, columns or width
        for (int j = 0; j < width; j++)
        {
            float avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0); // Gets the average
            image[i][j].rgbtBlue = avg; // Replaces the original color with the average
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // For loop to set the value of i, rows or height
    for (int i = 0; i < height; i++)
    {
        // For loop to set the value of j, columns or width. Since it's reflected, width goes until half of the picture
        for (int j = 0; j < width / 2; j++)
        {
            int tmpRed = image[i][j].rgbtRed; // Declare temporary integers to store original color
            int tmpBlue = image[i][j].rgbtBlue;
            int tmpGreen = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed; // Switch original pixel to reflected pixel (-1 because j starts at 0)
            image[i][width - j - 1].rgbtRed = tmpRed;

            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = tmpGreen;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = tmpBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width]; // Declares temporary structure to avoid overwriting of original values while running loops

    // For loop to set the value of i, rows or height
    for (int i = 0; i < height; i++)
    {
        // For loop to set the value of j, columns or width
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            // For loop to set the value of k, to get surrounding pixels
            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    if ((i + k) >= 0 && (i + k) < height && (j + m) >= 0 && (j + m) < width)
                    {
                        sumRed = sumRed + image[i + k][j + m].rgbtRed; // Adds the value of verified pixel to the sum
                        sumGreen = sumGreen + image[i + k][j + m].rgbtGreen;
                        sumBlue = sumBlue + image[i + k][j + m].rgbtBlue;
                        counter++; // To get the average
                    }
                }
            }
            // Sets new color based on average of surrounding pixels
            sumRed = round((double) sumRed / counter);
            tmp[i][j].rgbtRed = (sumRed < 255) ? sumRed : 255;

            sumGreen = round((double) sumGreen / counter);
            tmp[i][j].rgbtGreen = (sumGreen < 255) ? sumGreen : 255;

            sumBlue = round((double) sumBlue / counter);
            tmp[i][j].rgbtBlue = (sumBlue < 255) ? sumBlue : 255;
        }
    }

    // Start new loops to switch original values with temp values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width]; // Declares temporary structure to avoid overwriting of original values while running loops

    int gx_matrix[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1}; // to be used in the Gx matrix
    int gy_matrix[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1}; // to be used in the Gy matrix
    int counter = 0; // to loop through the matrixes
    float gx_red_calc = 0;
    float gx_green_calc = 0;
    float gx_blue_calc = 0;
    float gy_red_calc = 0;
    float gy_green_calc = 0;
    float gy_blue_calc = 0;
    double newRed = 0;
    double newGreen = 0;
    double newBlue = 0;

    // For loop to set the value of i, rows or height
    for (int i = 0; i < height; i++)
    {
        // For loop to set the value of j, columns or width
        for (int j = 0; j < width; j++)
        {
            // For loop to set the value of k, to get surrounding pixels
            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    // Checks if pixel is out of bounds
                    if ((i + k) < 0 || (i + k) >= height || (j + m) < 0 || (j + m) >= width)
                    {
                        continue;
                    }
                    else
                    {
                        // Apply Gx to valid pixel
                        gx_red_calc = gx_red_calc + (gx_matrix[counter] * image[i + k][j + m].rgbtRed);
                        gx_green_calc = gx_green_calc + (gx_matrix[counter] * image[i + k][j + m].rgbtGreen);
                        gx_blue_calc = gx_blue_calc + (gx_matrix[counter] * image[i + k][j + m].rgbtBlue);

                        // Apply Gy to valid pixel
                        gy_red_calc = gy_red_calc + (gy_matrix[counter] * image[i + k][j + m].rgbtRed);
                        gy_green_calc = gy_green_calc + (gy_matrix[counter] * image[i + k][j + m].rgbtGreen);
                        gy_blue_calc = gy_blue_calc + (gy_matrix[counter] * image[i + k][j + m].rgbtBlue);
                    }
                    // counter goes +1 to switch element in the matrix array
                    counter++;
                }
            }
            // Sets new RGB values of the pixel using the Gx² + Gy² calculation
            newRed = round(sqrt((gx_red_calc * gx_red_calc) + (gy_red_calc * gy_red_calc)));
            tmp[i][j].rgbtRed = (newRed < 255) ? newRed : 255;

            newGreen = round(sqrt((gx_green_calc * gx_green_calc) + (gy_green_calc * gy_green_calc)));
            tmp[i][j].rgbtGreen = (newGreen < 255) ? newGreen : 255;

            newBlue = round(sqrt((gx_blue_calc * gx_blue_calc) + (gy_blue_calc * gy_blue_calc)));
            tmp[i][j].rgbtBlue = (newBlue < 255) ? newBlue : 255;

            counter = 0; // resets counter to zero

            // resets all variables to zero after usage
            gx_red_calc = 0;
            gx_green_calc = 0;
            gx_blue_calc = 0;
            gy_red_calc = 0;
            gy_green_calc = 0;
            gy_blue_calc = 0;
        }
    }

    // Start new loops to swap original values with temp values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }
    return;
}
//check50 cs50/problems/2020/x/filter/more