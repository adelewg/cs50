#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    int cents = round(change * 100);

    int coins = 0;

    if (cents >= 25)
    {
        int quarters = cents / 25;
        coins += quarters;
        cents = cents - (quarters * 25);
    }

    if (cents >= 10 && cents < 25)
    {
        int dimes = cents / 10;
        coins += dimes;
        cents = cents - (dimes * 10);
    }

    if (cents >= 5 && cents < 10)
    {
        int nickels = cents / 5;
        coins += nickels;
        cents = cents - (nickels * 5);
    }

    if (cents < 5)
    {
        int pennies = cents / 1;
        coins += pennies;
        cents = cents - (pennies);
    }

    printf("%i\n", coins);
}
