#include "helpers.h"
#include "math.h"
#include "cs50.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) //greyscale é a media das cores (forma uma escala de cinza)
        {
            RGBTRIPLE pixel = image[i][j];
            int average =  round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}

int cap(int value)//formula para substituir valores maiores que 255 em 255, o max possivel na escala de cores
{
    if (value > 255)
    {
        value = 255;
    }
    return value;
    //return value > 255 ? 255 : value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) //interage na linhas e colunas seguindo as formulas para transformar as cores originais em sepia
        {
            RGBTRIPLE pixel = image[i][j];

            int sepiaRed =  cap(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));

            int sepiaGreen =  cap(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));

            int sepiaBlue =  cap(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)//formula para o swap respeitando pointers (video da aula: lecture 4)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}

bool isvalidpixel(int i, int j, int height, int width)//testa se o pixel é de canto ou borda
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE blurpixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])//efetivamente borra o pixel
{
    int redvalue, bluevalue, greenvalue;
    redvalue = bluevalue = greenvalue = 0;
    int maxp = 0;
    for (int di = -1; di < 2; di++)
    {
        for (int dj = -1; dj < 2; dj++)
        {
            int newi = i + di;
            int newj = j + dj;
            if (isvalidpixel(newi, newj, height, width))
            {
                maxp ++;
                redvalue += image[newi][newj].rgbtRed;
                bluevalue += image[newi][newj].rgbtBlue;
                greenvalue += image[newi][newj].rgbtGreen;

            }
        }
    }
    RGBTRIPLE blurpixel;
    blurpixel.rgbtRed = round((float) redvalue / maxp);
    blurpixel.rgbtBlue = round((float) bluevalue / maxp);
    blurpixel.rgbtGreen = round((float) greenvalue / maxp);

    return blurpixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
// copia a imagem numa nova para usar para os calculos de media das bordas
{
    RGBTRIPLE newimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newimage[i][j] = blurpixel(i, j, height, width, image);
        }
    }

    for (int i = 0; i < height; i++)//recopia a imagem
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = newimage[i][j];
        }
    }
}
