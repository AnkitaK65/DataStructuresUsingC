/*
Topic: Postfix Expression Evaluation

Explanation:
1. Postfix expression (Reverse Polish Notation) is given as input.
2. Operands (numbers) are pushed into a stack.
3. When an operator is encountered, 
    - Pop the top two operands from the stack.
    - Apply the operator on them.
    - Push the result back into the stack.
4. At the end, the stack contains the final result.
*/

#include <stdio.h>
#include <ctype.h>  // For isdigit()

#define MAX 50

int stack[MAX];
int top = -1;  // Initialize stack

// Function to push element into stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Function to pop element from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 for underflow error
    }
    return stack[top--];
}

int main() {
    char postfix[50];
    int i = 0;

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    while (postfix[i] != '\0') {
        // If character is an operand (0-9)
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0'); // Convert char to int and push
        } else {
            // Operator encountered: pop two operands
            int b = pop(); // Second operand
            int a = pop(); // First operand

            if (a == -1 || b == -1) {  // Error check
                printf("Invalid expression\n");
                return 1;
            }

            // Apply operator and push result
            switch (postfix[i]) {
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
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    return 1;
            }
        }
        i++;
    }

    // Final result
    int result = pop();
    if (top != -1) { // Extra elements in stack mean invalid expression
        printf("Invalid postfix expression\n");
        return 1;
    }

    printf("Result: %d\n", result);
    return 0;
}

/*
Output:
Enter postfix expression (single-digit operands): 32+4*
Result: 20
*/