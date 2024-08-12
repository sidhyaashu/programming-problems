/*
A mathematical puzzle where we have three rods and n disks. The objective is to move the entire stack to another rod, with the following constraints:
Only one disk can be moved at a time.
Each move consists of taking the top disk from one stack and placing it on another stack.
No disk may be placed on top of a smaller disk.

*/


#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'B', 'C'); // A, B, and C are rod names
    return 0;
}
