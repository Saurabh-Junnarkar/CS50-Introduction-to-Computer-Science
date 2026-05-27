/**
 * @file mario.c
 * @brief Prints a right-aligned Mario pyramid based on user input.
 * * How it works:
 * - Prompts the user for a pyramid height and ensures it is a positive integer.
 * - Loops through each row to build the pyramid structure.
 * - Passes the row data into clean, separate functions to handle printing 
 * the spaces and the blocks independently.
 */

#include <cs50.h>
#include <stdio.h>

void print_space(int space);
void print_block(int block);

int main(void)
{
    // Prompt user for height (int)
    int height;
    do
    {
        printf("Please provide the height as a positive integer number.\n");
        height = get_int("Enter Pyramid height: \n");
    }
    while (height < 1);

    int j = height;
    // Print a right aligned pyramid for a given height
    for (int i = 1; i <= height; i++)
    {
        // Print row based on which row
        print_space(j);
        print_block(i);
        j--;
    }
}

// Given a number of bricks, first print spaces then blocks
void print_space(int space)
{
    for (int i = 1; i < space; i++)
    {
        printf(" ");
    }
}

void print_block(int block)
{
    for (int j = 0; j < block; j++)
    {
        printf("#");
    }
    printf("\n");
}
