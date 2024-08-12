/*
The Ackermann function is a classic example of a recursive function that grows extremely quickly with its arguments. It's defined as follows:

A(m, n) =

n + 1, if m = 0
A(m - 1, 1), if m > 0 and n = 0
A(m - 1, A(m, n - 1)), if m > 0 and n > 0
It's mainly used as a benchmark for testing the performance of computer systems due to its rapid growth.

*/

#include <stdio.h>

int ackermann(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return ackermann(m - 1, 1);
    else if (m > 0 && n > 0)
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    int m = 3, n = 2;
    printf("Ackermann(%d, %d) = %d\n", m, n, ackermann(m, n));
    return 0;
}
