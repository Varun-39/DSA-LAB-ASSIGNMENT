#include<iostream>
using namespace std;
int main()  {
int arr[6] = {10,10,20,30,20,40};
for (int i = 0; i <6 ; i++)  {
 for (int j = i + 1; j < 6; j++) {
   if (arr[i] == arr[j]) {
     for (int k = j; k < 6 - 1; k++) {
        arr[k] = arr[k + 1];
        arr[k + 1] = 0;
     }
     }
    }
 }
 cout << "Array after removing duplicates: ";
  for (int i = 0; i < 6 - 1; i++) {
    cout << arr[i] << " ";
  }
 return 0;
 } 