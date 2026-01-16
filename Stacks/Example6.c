/*
Topic: Infix to Prefix Conversion

Explanation:
1. Reverse the infix expression.
2. Swap '(' with ')' while reversing.
3. Convert reversed infix to postfix using stack.
4. Reverse the postfix result to get prefix.
5. Supports operators +, -, *, / and operands (letters/digits).
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

// Push onto stack
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Return precedence of operator
int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

// Reverse a string in-place
void reverse(char str[]) {
    int l = 0, h = strlen(str) - 1;
    while (l < h) {
        char temp = str[l];
        str[l] = str[h];
        str[h] = temp;
        l++;
        h--;
    }
}

int main() {
    char infix[MAX], prefix[MAX], temp;
    int i, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Step 1: Reverse infix and swap parentheses
    reverse(infix);
    for (i = 0; infix[i]; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 2: Convert reversed infix to postfix
    for (i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            // Operand goes to result
            prefix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                prefix[k++] = pop();
            pop(); // remove '('
        } else {
            // Operator
            while (top != -1 && priority(stack[top]) >= priority(infix[i]))
                prefix[k++] = pop();
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';

    // Step 3: Reverse postfix to get prefix
    reverse(prefix);

    printf("Prefix: %s\n", prefix);
    return 0;
}

/*
Output:
Enter infix expression: (A+B)*(C-D/E)
Prefix: *+AB-C/DE
*/