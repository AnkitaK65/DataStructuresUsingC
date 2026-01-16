/*
Topic: Infix to Postfix Conversion

Explanation:
1. Operands (numbers or letters) go directly to the postfix expression.
2. Operators are pushed onto a stack based on their precedence.
3. Higher precedence operators are popped first.
4. Parentheses are handled properly:
    - '(' is pushed onto the stack.
    - ')' causes popping until '(' is encountered.
*/

#include <stdio.h>
#include <ctype.h> // For isalnum()
    //Returns: Non-zero (true) if c is alphanumeric (a letter A–Z, a–z or a digit 0–9)
    //0 (false) if it is not alphanumeric

#define MAX 50

char stack[MAX];
int top = -1;

// Push character onto stack
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop character from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Return precedence of operators
int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[50], postfix[50];
    int i = 0, k = 0;

    printf("Enter infix expression (e.g., A+B*C): ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        char symbol = infix[i];

        if (isalnum(symbol)) {
            // Operand goes directly to postfix
            postfix[k++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            // Pop until '(' is found
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            if (top != -1) pop(); // Remove '('
        }
        else {
            // Operator: pop higher or equal precedence operators
            while (top != -1 && priority(stack[top]) >= priority(symbol))
                postfix[k++] = pop();
            push(symbol);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0'; // Null terminate string

    printf("Postfix: %s\n", postfix);
    return 0;
}

/*
Output:
Enter infix expression (e.g., A+B*C): (A+B)*(C-D/E)
Postfix: AB+CDE/-*
*/