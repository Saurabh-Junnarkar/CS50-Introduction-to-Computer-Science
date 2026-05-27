/**
 * @file mario.c
 * @brief Console-based structural rendering simulation (CS50 Mario Less)
 * * ARCHITECTURAL DESIGN:
 * - Generates a right-aligned pyramidal grid of a user-specified height.
 * - Enforces dynamic input validation using an iterative control loop constraint (>= 1).
 * - Implements a highly decoupled functional abstraction by passing local parameters 
 * (row counts and offsets) by value to user-defined rendering modules.
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
