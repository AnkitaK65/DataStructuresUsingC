/*
Topic: Prefix Expression Evaluation (Single-digit operands)

Explanation:
1. Scan the prefix expression from right to left.
2. Push operands onto the stack.
3. When an operator is encountered, pop two operands,
    apply the operator, and push the result.
4. At the end, the stack contains the final result.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

int stack[MAX];
int top = -1;

// Push element onto stack
void push(int x) {
    stack[++top] = x;
}

// Pop element from stack
int pop() {
    return stack[top--];
}

int main() {
    char prefix[50];
    int i;

    printf("Enter prefix expression (single-digit operands): ");
    scanf("%s", prefix);

    // Scan from right to left
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int
        } else {
            int a = pop();
            int b = pop();

            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Result: %d\n", pop());
    return 0;
}

/*
Output:
Enter prefix expression (single-digit operands): *+23-9/82
Result: 25
*/