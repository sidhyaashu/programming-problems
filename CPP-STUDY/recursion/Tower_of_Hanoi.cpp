#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char aux, char dest) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << dest << endl;
        return;
    }
    towerOfHanoi(n - 1, source, dest, aux);
    cout << "Move disk " << n << " from rod " << source << " to rod " << dest << endl;
    towerOfHanoi(n - 1, aux, source, dest);
}

int main() {
    int numDisks;
    cout << "Enter number of disks: ";
    cin >> numDisks;
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    return 0;
}
