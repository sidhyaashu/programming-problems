#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int low, int high, int target) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    else
        return binarySearch(arr, low, mid - 1, target);
}

int main() {
    vector<int> arr = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23};
    int target;
    cout << "Enter the number to search: ";
    cin >> target;
    int index = binarySearch(arr, 0, arr.size() - 1, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
