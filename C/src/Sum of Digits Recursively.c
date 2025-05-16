// This project is a C program that multiplies two numbers using recursion.

#include <stdio.h>

// Recursive function to calculate the sum of digits of a number
int sum_of_digit(int n)
{
    // Base case: if number is 0, return 0
    if (n == 0)
       return 0;

    // Recursive case: get the last digit (n % 10) and add it to the sum of the remaining digits
    return (n % 10 + sum_of_digit(n / 10));
}

int main()
{
    int num;

    // Prompt the user to enter a number
    printf("\nEnter Any Number - ");
    scanf("%d", &num);

    // Call the recursive function and store the result
    int result = sum_of_digit(num);

    // Display the result
    printf("Sum of digits in %d is %d\n", num, result);

    return 0;
}
