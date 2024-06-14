#include <iostream>
#include <vector>
using namespace std;

void generateParentheses(int n, int open, int close, string current, vector<string>& result) {
    if (open == n && close == n) {
        result.push_back(current);
        return;
    }
    if (open < n)
        generateParentheses(n, open + 1, close, current + '(', result);
    if (close < open)
        generateParentheses(n, open, close + 1, current + ')', result);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<string> result;
    generateParentheses(n, 0, 0, "", result);
    cout << "Valid combinations of " << n << " pairs of parentheses are:" << endl;
    for (const string& s : result)
        cout << s << endl;
    return 0;
}
