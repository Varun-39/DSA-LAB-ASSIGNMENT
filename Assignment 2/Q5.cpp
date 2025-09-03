#include<iostream>
using namespace std;
void DiagonalMatrix(int arr[][100], int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i != j) {
                arr[i][j] = 0;
            }
        }
    }
}
void TriDiagonalMatrix(int arr[][100], int rows, int columns){
for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (!(i == j || i == j - 1 || i == j + 1)) {
                arr[i][j] = 0;
            }
        }
    }
} 
void makeLowerTriangular(int arr[][100], int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i < j) {
                arr[i][j] = 0; 
            }
        }
    }
}
void UpperTriangular(int arr[][100], int rows, int columns){
    for (int i = 0; i <rows; i++){
        for (int j = 0; j<columns; j++){
            if (j>i){
                arr[i][j] = 0;
            }
        }
    }
}
void makeSymmetric(int arr[][100], int rows, int columns) {
    if (rows != columns) {
        cout << "Matrix must be square to be symmetric!" << endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < columns; j++) {
            arr[j][i] = arr[i][j];
        }
    }
}
int main() {
   int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> columns;
    int arr[100][100];

 cout << "\n Enter the elements of the matrix"<< endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    cin >> arr[i][j];
                }
            }
            cout << "\nThe entered matrix is:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
 DiagonalMatrix(arr, rows, columns);
 cout << "\nThe diagonal matrix is:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
TriDiagonalMatrix(arr, rows, columns);
 cout << "\nThe Tridiagonal matrix is:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
makeLowerTriangular(arr, rows, columns);
 cout << "\nThe LowerTriangular matrix is:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
UpperTriangular(arr, rows, columns);
cout<< "\nThe UpperTriangular matrix is:" <<endl;
for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
makeSymmetric(arr, rows, columns);
cout<< "\nThe symmetric matrix is:" <<endl;
for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}
