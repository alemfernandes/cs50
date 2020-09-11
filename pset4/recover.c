#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("use: ./recover filename.XXX\n");
        return 1;
    }

    //open memorycard
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Cannot open file, input a valid file!\n");
        return 1;
    }

    //define buffer size
    unsigned char buffer[BUFFER_SIZE];

    //create file counter
    int counter = 0;

    FILE *pic = NULL;

    //create a boolean for found jpg
    int foundjpg = false;

    //reading the card
    while (fread(buffer, BUFFER_SIZE, 1, input) == 1)
    {
        //checking the first bytes to match a jgp file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (foundjpg)
            {
                fclose(pic);
            }
            else
            {
                foundjpg = true;
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", counter);
            pic = fopen(filename, "a");
            counter++;

        }

        if (foundjpg)
        {
            fwrite(&buffer, BUFFER_SIZE, 1, pic);
        }

    }

    //close files
    fclose(input);
    fclose(pic);

    return 0;
}
