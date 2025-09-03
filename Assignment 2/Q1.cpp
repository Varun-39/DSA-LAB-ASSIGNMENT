#include<iostream>
using namespace std;
int binarysearch (int arr[],int n, int target){
    int left = 0; 
    int y = n -1 ;
    while (left <= y) {
        int mid  = left + (y - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        }
        else if (arr[mid] > target) {
            y = mid - 1;
        }
        else {
            return -1;
        }
        }
        }
int main() {
    int arr[] = {10,20,30,40,50} ;
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 40;
    int result = binarysearch(arr,n , target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
}


    
