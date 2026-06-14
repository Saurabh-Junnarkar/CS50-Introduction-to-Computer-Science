#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes to Calculate Letters, Words and Sentences
int cal_letter(string a);
int cal_word(string b);
int cal_sentence(string c);

int main(void)
{
    // Get the text from the user
    string text = get_string("Please provide the text: ");

    // Calculate Letters, Words and Sentences in the text
    int tot_letter = cal_letter(text);
    int tot_word = cal_word(text);
    int tot_sent = cal_sentence(text);

    // Calculate the Coleman-Liau Index
    float L = (float) tot_letter * 100 / tot_word;
    float S = (float) tot_sent * 100 / tot_word;
    float coleman = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(coleman);

    // Print the Final Grade Value
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Calculate Total Letters
int cal_letter(string a)
{
    int count_letter = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (isalpha(a[i]))
        {
            count_letter++;
        }
    }
    return count_letter;
}

// Calculate Total Words
int cal_word(string b)
{
    int count_word = 1;
    for (int i = 0; b[i] != '\0'; i++)
    {
        if (isblank(b[i]))
        {
            count_word++;
        }
    }
    return count_word;
}

// Calculate Total Sentences
int cal_sentence(string c)
{
    int count_sentence = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == '.' || c[i] == '!' || c[i] == '?')
        {
            count_sentence++;
        }
    }
    return count_sentence;
}
