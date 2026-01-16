/*
Topic: Postfix Expression Evaluation (Multi-digit operands)

Explanation:
1. Postfix expression is entered as space-separated operands and operators.
2. Operands (numbers) are pushed into a stack.
3. On encountering an operator, pop two operands, evaluate, and push the result.
4. Supports multi-digit numbers and simple operators (+, -, *, /).
*/

#include <stdio.h>
#include <stdlib.h> // For atoi()

#define MAX 50

int stack[MAX];
int top = -1;

// Push element onto stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop element from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int n; // Number of tokens
    printf("Enter number of tokens in postfix expression: ");
    scanf("%d", &n);

    char token[20]; // To hold each token
    for (int i = 0; i < n; i++) {
        scanf("%s", token);

        // If operator
        if (token[0] == '+' || token[0] == '-' || 
            token[0] == '*' || token[0] == '/') {

            int b = pop();
            int a = pop();

            if (a == -1 || b == -1) {
                printf("Invalid expression\n");
                return 1;
            }

            switch (token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': 
                    if (b == 0) {
                        printf("Division by zero error\n");
                        return 1;
                    }
                    push(a / b); 
                    break;
            }
        } 
        else { // Operand: convert to integer
            push(atoi(token));
        }
    }

    int result = pop();
    if (top != -1) {
        printf("Invalid postfix expression\n");
        return 1;
    }

    printf("Result: %d\n", result);
    return 0;
}

/*
Output:
Enter number of tokens in postfix expression: 5
12 3 + 4 *
Result: 60
*/