#include <iostream>
using namespace std;

int countBinaryStrings(int n, int lastBit) {
    if (n == 0)
        return 1;
    if (lastBit == 1)
        return countBinaryStrings(n - 1, 0);
    return countBinaryStrings(n - 1, 0) + countBinaryStrings(n - 1, 1);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Number of binary strings of length " << n << " without consecutive 1s: " << countBinaryStrings(n, 0) << endl;
    return 0;
}
