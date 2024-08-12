#include <iostream>
#include <string>
using namespace std;

void generateSubsets(const string& str, string subset, int index) {
    if (index == str.length()) {
        cout << subset << endl;
        return;
    }
    // Exclude current character
    generateSubsets(str, subset, index + 1);
    // Include current character
    generateSubsets(str, subset + str[index], index + 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Subsets of the string are:" << endl;
    generateSubsets(str, "", 0);
    return 0;
}
