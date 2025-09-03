#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 7, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]) + 1;

    int left = 0, right = n - 2;
    int missing = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            missing = mid + 1;
            right = mid - 1;
        }
    }

    cout << "Missing number (Binary Search): " << missing << endl;

    return 0;
}