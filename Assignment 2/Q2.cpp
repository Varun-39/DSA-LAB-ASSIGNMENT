#include<iostream>
using namespace std;
int main () {
    int arr[7] = {64,34,25,12,22,11,90};
    int counter = 1;
    while (counter < 7) {
        for (int i = 0; i < 7-counter;i++ ) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }

        }
        counter++;
    }
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
}