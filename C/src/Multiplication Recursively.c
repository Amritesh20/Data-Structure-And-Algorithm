// This project is a C program that multiplies two numbers using recursion.
// The program prompts the user to enter two integers and then calculates their product using a recursive function.
// The recursive function `multiply` takes two integers as arguments and returns their product.
#include <stdio.h>
#include <stdlib.h>

int multiply(int x, int y)
{
    if (y == 0 || x == 0)
    {
        return 0;
    }
    else if (y > 0)
    {
        return x + multiply(x, y - 1);
    }
    else // if y is negative
    {
        return -multiply(x, -y);
    }
}

int main()
{
    int z1, z2, result;

    printf("\nEnter First number - ");
    scanf("%d", &z1);

    printf("\nEnter Second Number - ");
    scanf("%d", &z2);

    result = multiply(z1, z2);

    printf("\nResult of multiplication: %d\n", result);

    return 0;
}
