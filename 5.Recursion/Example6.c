/*
Question: Write a program to reverse a string 
using both recursion and iteration.
*/

#include <stdio.h>
#include <string.h>

// Recursive reverse
void reverseRecursive(char str[], int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseRecursive(str, start + 1, end - 1);
}

int main() {
    char str1[100], str2[100];
    printf("Enter a string: ");
    scanf("%s", str1);

    strcpy(str2, str1); // Copy for iteration

    reverseRecursive(str1, 0, strlen(str1) - 1);
    printf("Reversed (Recursion): %s\n", str1);

    // Iterative reverse
    int start = 0, end = strlen(str2) - 1;
    while (start < end) {
        char temp = str2[start];
        str2[start] = str2[end];
        str2[end] = temp;
        start++;
        end--;
    }
    printf("Reversed (Iteration): %s\n", str2);

    return 0;
}

/*
Output:
Enter a string: Hello
Reversed (Recursion): olleH
Reversed (Iteration): olleH
*/