/**
 * @file cash.c
 * @brief Calculates the minimum number of coins needed for change.
 * * How it works:
 * - Asks the user for the amount of change owed and ensures it is not negative.
 * - Uses division to quickly find out how many quarters, dimes, and nickels 
 * can fit into the total amount without needing slow subtraction loops.
 * - Prints the final coin count along with a friendly breakdown of each coin used.
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
