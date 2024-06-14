/*
Linear search is the simplest searching algorithm. It sequentially checks each element of the list until a match is found or the end of the list is reached.
*/
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i; // Return index if element is found
    }
    return -1; // Return -1 if element is not found
}


/*
Binary Search:

Binary search is a fast search algorithm with O(log n) time complexity. It requires the array to be sorted.

*/

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid; // Return index if element is found
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1; // Return -1 if element is not found
}



/*
Jump Search:

Jump search is a searching algorithm for sorted arrays. It jumps ahead by fixed steps and then performs linear search.
*/

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }
    if (arr[prev] == x)
        return prev;
    return -1; // Return -1 if element is not found
}



/*
Interpolation Search:

Interpolation search is an improvement over binary search for uniformly distributed arrays.
*/

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
        if (arr[pos] == x)
            return pos; // Return index if element is found
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1; // Return -1 if element is not found
}



/*
Exponential Search:

Exponential search involves two steps: find the range where the element is present and then do binary search in that range.
*/

int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x)
        return 0; // Return index if element is found at the beginning
    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}




/*
Fibonacci Search:

Fibonacci search is a comparison-based technique that uses Fibonacci numbers to divide the array into two parts.
*/

int fibonacciSearch(int arr[], int n, int x) {
    int fibMMinus2 = 0;
    int fibMMinus1 = 1;
    int fibM = fibMMinus1 + fibMMinus2;
    while (fibM < n) {
        fibMMinus2 = fibMMinus1;
        fibMMinus1 = fibM;
        fibM = fibMMinus1 + fibMMinus2;
    }
    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibMMinus2, n - 1);
        if (arr[i] < x) {
            fibM = fibMMinus1;
            fibMMinus1 = fibMMinus2;
            fibMMinus2 = fibM - fibMMinus1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fibMMinus2;
            fibMMinus1 = fibMMinus1 - fibMMinus2;
            fibMMinus2 = fibM - fibMMinus1;
        } else
            return i; // Return index if element is found
    }
    if (fibMMinus1 && arr[offset + 1] == x)
        return offset + 1;
    return -1; // Return -1 if element is not found
}



/*
Ternary Search:

Ternary search is a divide and conquer algorithm that splits the array into three parts and determines which part the element lies in.
*/

int ternarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == x)
            return mid1; // Return index if element is found
        if (arr[mid2] == x)
            return mid2; // Return index if element is found
        if (arr[mid1] > x)
            return ternarySearch(arr, l, mid1 - 1, x);
        if (arr[mid2] < x)
            return ternarySearch(arr, mid2 + 1, r, x);
        return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
    }
    return -1; // Return -1 if element is not found
}




/*
Recursive Linear Search:

Recursive linear search searches for an element in an array using recursion.
*/

int recursiveLinearSearch(int arr[], int l, int r, int x) {
    if (r < l)
        return -1; // Return -1 if element is not found
    if (arr[l] == x)
        return l; // Return index if element is found
    if (arr[r] == x)
        return r; // Return index if element is found
    return recursiveLinearSearch(arr, l + 1, r - 1, x);
}
