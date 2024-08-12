#include <iostream>
#include <string>
using namespace std;

int countDecodings(const string& digits, int n) {
    if (n == 0 || n == 1)
        return 1;
    int count = 0;
    if (digits[n - 1] > '0')
        count = countDecodings(digits, n - 1);
    if (digits[n - 2] == '1' || (digits[n - 2] == '2' && digits[n - 1] < '7'))
        count += countDecodings(digits, n - 2);
    return count;
}

int main() {
    string digits = "1234";
    cout << "Number of possible decodings: " << countDecodings(digits, digits.length()) << endl;
    return 0;
}
