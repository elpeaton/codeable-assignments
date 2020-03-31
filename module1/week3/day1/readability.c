#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);

int main(void)
{
    string text = get_string("Text: ");

    int L = 100 * count_letters(text) / count_words(text);
    int S = 100 * count_sentences(text) / count_words(text);

    float index = 0.0588 * (float)L - 0.296 * (float)S - 15.8;

    if (index > 1 && index < 16)
    {
        printf("Grade %i\n", (int)round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string txt)
{
    int letters = 0;
    int lenght_text = strlen(txt);

    for (int i = 0; i < lenght_text; i++)
    {
        if (isalpha(txt[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string txt)
{
    int words = 0;
    int lenght_text = strlen(txt);

    for (int i = 0; i < lenght_text; i++)
    {
        if (isspace(txt[i]))
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentences(string txt)
{
    int sentences = 0;
    int lenght_text = strlen(txt);

    for (int i = 0; i < lenght_text; i++)
    {
        if ((txt[i]) == '.' || (txt[i]) == '?' || (txt[i]) == '!')
        {
            sentences++;
        }
    }
    return sentences;
}