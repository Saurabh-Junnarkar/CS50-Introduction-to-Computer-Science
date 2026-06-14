#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Declaration of custom function to calculate score
int cal_score(string a);

int main(void)
{
    // Prompt users for Scrabble words
    string s1 = get_string("Player 1: ");
    string s2 = get_string("Player 2: ");

    int score1 = cal_score(s1);
    int score2 = cal_score(s2);

    // Compare score through a function and Print result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Calculcating the string's score in the below function
int cal_score(string a)
{
    int value = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (isalpha(a[i]))
        {
            value = value + points[toupper(a[i]) - 'A'];
        }
    }
    return value;
}
