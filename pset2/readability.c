#include <cs50.h>
#include <stdio.h>
#include <string.h> // for string lenght
#include <ctype.h> // for types
#include <math.h> // for round


int main(void)
{
    // Prompt for user's text
    string text = get_string("Text: ");

    //setting counters for LETTERS, WORDS and SENTENCES
    int L = 0;
    int W = 1;
    int S = 0;

    //Checking and counting the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            L++;
        }

        if (isalpha(text[i + 1]) && isspace(text[i]))
        {
            W++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == ':')
        {
            S++;
        }
    }

    //
    float lperw = 100 * (float) L / (float) W; //finding letters per 100 words
    float sperw = 100 * (float) S / (float) W; //finding sentences per 100 words
    float index = 0.0588 * (float) lperw - 0.296 * (float) sperw - 15.8; //finding Coleman-Liau index


    //printf("%i letters(s)\n", L);
    //printf("%i word(s)\n", W);
    //printf("%i sentences(s)\n", S);

    if (index <= 0)

    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)

    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }

}
