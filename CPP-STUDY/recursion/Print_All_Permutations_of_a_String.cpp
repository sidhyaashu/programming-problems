#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void generatePermutations(string str, int start, int end) {
    if (start == end) {
        cout << str << endl;
        return;
    }
    for (int i = start; i <= end; ++i) {
        swap(str[start], str[i]);
        generatePermutations(str, start + 1, end);
        swap(str[start], str[i]);
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Permutations of the string are:" << endl;
    generatePermutations(str, 0, str.length() - 1);
    return 0;
}
