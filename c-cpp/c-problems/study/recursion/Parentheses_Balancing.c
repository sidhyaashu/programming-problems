/*
"Parentheses Balancing" is a problem where you have a string containing various parentheses characters ('(', ')', '{', '}', '[', ']'), and you need to determine whether the parentheses are balanced, meaning that each opening parenthesis has a corresponding closing parenthesis and they are properly nested.

*/

#include <stdio.h>
#include <stdbool.h>

// Function to check if two characters form a valid pair of parentheses
bool isValidPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Recursive function to check if parentheses are balanced
bool isBalanced(char *expr, int start, int end) {
    // Base case: if start index is greater than or equal to end index, return true
    if (start >= end)
        return true;

    // If the current character is an opening parenthesis
    if (expr[start] == '(' || expr[start] == '{' || expr[start] == '[') {
        // Find the corresponding closing parenthesis
        int i;
        for (i = start + 1; i <= end; i++) {
            if (expr[i] == expr[start] || expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
                break;
        }
        // If no corresponding closing parenthesis found, return false
        if (i > end)
            return false;
        // If the pair is valid, recursively check the substring between them
        if (isValidPair(expr[start], expr[i]))
            return isBalanced(expr, start + 1, i - 1) && isBalanced(expr, i + 1, end);
    }

    // If the current character is not an opening parenthesis, continue checking the rest of the string
    return isBalanced(expr, start + 1, end);
}

int main() {
    char expr[] = "{[()]}";
    int length = sizeof(expr) / sizeof(expr[0]);

    if (isBalanced(expr, 0, length - 1))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
