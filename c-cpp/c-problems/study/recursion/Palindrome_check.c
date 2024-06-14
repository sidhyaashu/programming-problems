/*
A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward. Palindrome check involves checking if a given string is a palindrome or not.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str, int start, int end) {
    if (start >= end)
        return true;
    if (str[start] != str[end])
        return false;
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[] = "radar";
    int len = strlen(str);
    if (isPalindrome(str, 0, len - 1))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
