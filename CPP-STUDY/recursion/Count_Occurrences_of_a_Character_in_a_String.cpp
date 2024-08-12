#include <iostream>
#include <string>
using namespace std;

int countOccurrences(const string& str, char ch, int index) {
    if (index == str.length())
        return 0;
    if (str[index] == ch)
        return 1 + countOccurrences(str, ch, index + 1);
    else
        return countOccurrences(str, ch, index + 1);
}

int main() {
    string str;
    char ch;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Enter a character to count: ";
    cin >> ch;
    cout << "Occurrences of '" << ch << "': " << countOccurrences(str, ch, 0) << endl;
    return 0;
}
