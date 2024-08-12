#include <iostream>
#include <vector>
using namespace std;

int arraySum(const vector<int>& arr, int size) {
    if (size == 0)
        return 0;
    else
        return arr[size - 1] + arraySum(arr, size - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Sum of array elements: " << arraySum(arr, arr.size()) << endl;
    return 0;
}
