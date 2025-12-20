#include<iostream>
using namespace std;

typedef int* IntPtr;

int main() {
    int d1, d2;
    cout << "Enter row and column dimensions of the array: ";
    cin >> d1 >> d2;

    IntPtr *m = new IntPtr[d1]; // Dynamic array of 3 integer pointers
    
    int i, j;
    for (i = 0; i < d1; i++) {
        m[i] = new int[d2]; // Dynamic array of integers for each row
    }

    cout << "Enter the elements of the array:" << endl;
    for (i = 0; i < d1; i++) {
        for (j = 0; j < d2; j++) {
            cin >> m[i][j];
        }
    }

    cout << "The elements of the array are:" << endl;
    for (i = 0; i < d1; i++) {
        for (j = 0; j < d2; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (i = 0; i < d1; i++) {
        delete[] m[i];
    }
    delete[] m;

    return 0;
}   