#include <iostream>
using namespace std;
int toSparse(int mat[100][100], int rows, int cols, int sparse[][3]) {
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;
    return k - 1;
}
void printSparse(int sparse[][3], int nonZero) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
    cout << endl;
}
void transposeSparse(int sparse[][3], int trans[][3]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int nonZero = sparse[0][2];

    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= nonZero; j++) {
            if (sparse[j][1] == i) {
                trans[k][0] = sparse[j][1];
                trans[k][1] = sparse[j][0];
                trans[k][2] = sparse[j][2];
                k++;
            }
        }
    }
}

int main() {
    int rows, cols;
    int arr[100][100];
    int sparse[100][3], trans[100][3];

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "\nEnter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << "\nThe entered matrix is:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int nonZero = toSparse(arr, rows, cols, sparse);

    cout << "\nTriplet form of the matrix:\n";
    printSparse(sparse, nonZero);

    transposeSparse(sparse, trans);

    cout << "Transpose in triplet form:\n";
    printSparse(trans, trans[0][2]);

    return 0;
}
