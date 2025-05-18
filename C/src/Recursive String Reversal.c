#include <stdio.h>
#include <string.h>

// Recursive helper to reverse string between two indices
void reverse(char *str, int left, int right)
{
    if (left >= right)
        return;

    // Swap characters
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    // Recur for next pair
    reverse(str, left + 1, right - 1);
}

int main()
{
    char str[50];

    // Get user input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  // Remove newline character

    // Call reverse with start and end indices
    reverse(str, 0, strlen(str) - 1);

    printf("Reverse of the given string is: %s\n", str);

    return 0;
}
