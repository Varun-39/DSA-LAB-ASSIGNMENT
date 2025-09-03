#include <iostream>
using namespace std;
int main () {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size/2 ; i++){
        for (int j = size ; j > i; j--){
            int temp = arr[j];
            temp = arr[i];
            arr[i] = arr[j];
        }

    }
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}