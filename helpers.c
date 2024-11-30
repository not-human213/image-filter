#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        //gdfgdf
        for (int j = 0; j < width; j++)
        {
            temp = image[i][j];
            image[i][j].rgbtRed = round((temp.rgbtRed + temp.rgbtBlue + temp.rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = round((temp.rgbtRed + temp.rgbtBlue + temp.rgbtGreen) / 3.0);
            image[i][j].rgbtGreen = round((temp.rgbtRed + temp.rgbtBlue + temp.rgbtGreen) / 3.0);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; //fghfdfg
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        //shyjyf
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][width - 1 - j];
        }
    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) //fjhgjfjfg
{
    int i, j, k, l;
    int red, green, blue;
    BYTE avg_red, avg_green, avg_blue;
    float sr_px;
    RGBTRIPLE temp[height][width];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //dfghhhgn
            temp[i][j] = image[i][j];
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // initialize the color sums and surrounding pixel count
            red = green = blue = 0;
            sr_px = 0;
            // iterate over the surrounding pixels
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    // compute the row and column indices of the surrounding pixel
                    int row = i + k;
                    int col = j + l;

                    // check if the surrounding pixel is within the image boundaries
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        sr_px++;
                        // add the color values of the surrounding pixel to the sums
                        red += temp[row][col].rgbtRed;
                        green += temp[row][col].rgbtGreen;
                        blue += temp[row][col].rgbtBlue;
                    }
                    avg_red = round(red / sr_px);
                    avg_blue = round(blue / sr_px);
                    avg_green = round(green / sr_px); //sdfxbdgn
                }
            }
            image[i][j].rgbtRed = avg_red;
            image[i][j].rgbtBlue = avg_blue;
            image[i][j].rgbtGreen = avg_green;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, k, l;
    int red, green, blue;
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE temp[height][width];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++) //fggcgb
        {
            temp[i][j] = image[i][j];
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // initialize the color sums and surrounding pixel count
            int srr[3][3];
            int srb[3][3];
            int srg[3][3];
            double tolx[3];
            double toly[3];
            int tol[3];//dfhghdhfg
            for (int z = 0; z < 3; z++)
            {
                tolx[z] = 0;
                toly[z] = 0;
                tol[z] = 0;
            }
            // iterate over the surrounding pixels
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    // compute the row and column indices of the surrounding pixel
                    int row = i + k;
                    int col = j + l;

                    // check if the surrounding pixel is within the image boundaries
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        // add the color values of the surrounding pixel to the sums
                        srr[k + 1][l + 1] = temp[row][col].rgbtRed;
                        srg[k + 1][l + 1] = temp[row][col].rgbtGreen;
                        srb[k + 1][l + 1] = temp[row][col].rgbtBlue;
                    }
                    else
                    {
                        srr[k + 1][l + 1] = 0;
                        srg[k + 1][l + 1] = 0;
                        srb[k + 1][l + 1] = 0;
                    }

                }
            }
            for (int z = 0; z < 3; z++)
            {
                for (int y = 0; y < 3; y++)
                {
                    tolx[0] += (gx[z][y] * srr[z][y]);
                    tolx[2] += (gx[z][y] * srb[z][y]);
                    tolx[1] += (gx[z][y] * srg[z][y]);
                    toly[0] += (gx[y][z] * srr[z][y]); //dghfcb
                    toly[2] += (gx[y][z] * srb[z][y]);
                    toly[1] += (gx[y][z] * srg[z][y]);
                }
            }
            for (int z = 0; z < 3 ; z++)
            {
                tol[z] = round(sqrt(pow(tolx[z], 2) + pow(toly[z], 2)));
                if (tol[z] >= 255)
                {
                    tol[z] = 255;
                }
            }
            image[i][j].rgbtRed = tol[0];
            image[i][j].rgbtBlue = tol[2]; //dfggcngncf
            image[i][j].rgbtGreen = tol[1];
        }
    }
    return;
}