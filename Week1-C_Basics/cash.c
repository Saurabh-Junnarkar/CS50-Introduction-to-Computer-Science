/**
 * @file cash.c
 * @brief Optimal currency denomination calculator with descriptive breakdown (CS50 Cash)
 * * ARCHITECTURAL DESIGN:
 * - Computes the absolute minimum coin count required to render a specific value of change.
 * - Input Gate: Enforces non-negative boundaries via a do-while loop constraint (>= 0).
 * - Algorithmic Optimization: Utilizes sequential division and remainder reduction 
 * ($25\phi \rightarrow 10\phi \rightarrow 5\phi \rightarrow 1\phi$) to maintain flat, 
 * highly efficient O(1) computational complexity.
 * - Interface Layer: Outputs both the grand total and an itemized breakdown per denomination.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to confirm their change
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    // Calculate the minimum number of coins
    int c25 = 0;
    int c10 = 0;
    int c5 = 0;
    int coins = 0;
    if (change >= 25)
    {
        c25 = change / 25;
        change = change - (25 * c25);
    }
    if (change >= 10)
    {
        c10 = change / 10;
        change = change - (10 * c10);
    }
    if (change >= 5)
    {
        c5 = change / 5;
        change = change - (5 * c5);
    }
    coins = c25 + c10 + c5 + change;

    // Print the minimum number of coins and the quantity of each coin
    printf("Minimum coins: %i\n", coins);
    printf("%i coin(s) of $25, %i coin(s) of $10, %i coin(s) of $5, and %i coin(s) of $1\n", c25,
           c10, c5, change);
}
