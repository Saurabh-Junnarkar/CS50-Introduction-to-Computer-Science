#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // To ensure that user only provided 1 command-line argurment
    if (argc != 2)
    {
        printf("Correct usage: ./caesar key\n");
        return 1;
    }

    // Loop through argv[1] to confirm if it is a number
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert string to int
    int key = atoi(argv[1]) % 26;

    // Prompt for Plaintext
    string plaintext = get_string("plaintext:  ");

    int text_count = strlen(plaintext);

    // Cipher Matrix loop
    for (int i = 0; i < text_count; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            if ('z' - plaintext[i] >= key)
            {
                plaintext[i] = plaintext[i] + key;
            }
            else if ('z' - plaintext[i] < key)
            {
                plaintext[i] = 'a' + (key - ('z' - plaintext[i]) - 1);
            }
        }

        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            if ('Z' - plaintext[i] >= key)
            {
                plaintext[i] = plaintext[i] + key;
            }
            else if ('Z' - plaintext[i] < key)
            {
                plaintext[i] = 'A' + (key - ('Z' - plaintext[i]) - 1);
            }
        }
    }

    // Output Ciphertext
    printf("ciphertext: %s\n", plaintext);
    return 0;
}
