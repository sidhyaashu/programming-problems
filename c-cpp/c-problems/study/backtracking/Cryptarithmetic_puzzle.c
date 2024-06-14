#include <stdio.h>

int main() {
    int s, e, n, d, m, o, r, y;
    for (s = 0; s <= 9; s++) {
        for (e = 0; e <= 9; e++) {
            for (n = 0; n <= 9; n++) {
                for (d = 0; d <= 9; d++) {
                    for (m = 1; m <= 9; m++) {
                        for (o = 0; o <= 9; o++) {
                            for (r = 0; r <= 9; r++) {
                                for (y = 0; y <= 9; y++) {
                                    if ((s * 1000 + e * 100 + n * 10 + d) +
                                        (m * 1000 + o * 100 + r * 10 + e) ==
                                        (m * 10000 + o * 1000 + n * 100 + e * 10 + y)) {
                                        printf("S = %d, E = %d, N = %d, D = %d\n", s, e, n, d);
                                        printf("M = %d, O = %d, R = %d, E = %d\n", m, o, r, e);
                                        printf("M = %d, O = %d, N = %d, E = %d, Y = %d\n", m, o, n, e, y);
                                        return 0; // Found solution
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("No solution found\n");
    return 0;
}
