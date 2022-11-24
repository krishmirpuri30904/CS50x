#include <math.h>
#include "helpers.h"

int cap255(int color)
{
    if (color > 255)
    {
        return 255;
    }
    else
    {
        return color;
    }
}

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    float averageColors;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            averageColors = round((originalRed +
                                   originalGreen +
                                   originalBlue) /
                                  3.0);

            image[i][j].rgbtRed = averageColors;
            image[i][j].rgbtGreen = averageColors;
            image[i][j].rgbtBlue = averageColors;
        }
    }
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp_row[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_row[j] = image[i][j];
        }
        for (int j = 0; j < width; j++)
        {

            image[i][j].rgbtRed = temp_row[width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = temp_row[width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = temp_row[width - 1 - j].rgbtBlue;
        }
    }
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp_image[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            temp_image[h][w] = image[h][w];
        }
    }

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }

                    sumRed += temp_image[i + k][j + l].rgbtRed;
                    sumGreen += temp_image[i + k][j + l].rgbtGreen;
                    sumBlue += temp_image[i + k][j + l].rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = (int)round(sumRed / count);
            image[i][j].rgbtGreen = (int)round(sumGreen / count);
            image[i][j].rgbtBlue = (int)round(sumBlue / count);
        }
    }
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE tempImage[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            tempImage[h][w] = image[h][w];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            float GxRed = 0;
            float GxBlue = 0;
            float GxGreen = 0;
            float GyRed = 0;
            float GyBlue = 0;
            float GyGreen = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    GxRed += tempImage[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    GxGreen += tempImage[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    GxBlue += tempImage[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                    GyRed += tempImage[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    GyGreen += tempImage[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    GyBlue += tempImage[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                }
            }
            image[i][j].rgbtRed = cap255(round(sqrt(GxRed * GxRed + GyRed * GyRed)));
            image[i][j].rgbtGreen = cap255(round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen)));
            image[i][j].rgbtBlue = cap255(round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue)));
        }
    }
}