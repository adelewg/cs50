#include <stdio.h>
#include <cs50.h>
#include <math.h>


int digits (long number)
{
    int counter = 0;
    while(number > 0)
    {
        number/=10;
        counter++;
    }
    return counter;
}

int main(void)
{
    long num = get_long("Number: ");
    // initiate a variable to store the sum of every other digit multiplied by 2
    int sum = 0;
    long alt_num = num;
    for(int i = 0; i < digits(num); i+=2)
    {
        alt_num /= 10;
        int other = 2 * (alt_num % 10);
        alt_num /= 10;
        if(digits(other) < 2)
        {
            sum += other;
        }
        //if after multiplying by 2 you get two digits - you need to add them digit by digit
        else
        {
            sum += other % 10;
            sum += other / 10;
        }

    }
    //now you need to add that temporary number to all the other digits in the credit card that you did not look at
    for(int i = 0; i < digits(num); i += 2)
    {
        long num2 = num;
        sum += num2 % 10;
        num2 /= 100;
    }

    if(sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
