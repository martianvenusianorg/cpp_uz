#include <iostream>
#include <cstdlib>
#include <cstddef>

typedef int* IntPtr;

void fill_array(int a[], int size);

void sort(int a[], int size);

int main(){   
    using namespace std;
    cout << "This program sorts number of integers from lowest to highest." << endl;
    int array_size;
    cout << "Enter the number of elements: ";
    cin >> array_size;

    IntPtr a;
    a = new int[array_size];

    fill_array(a, array_size);
    sort(a, array_size);
    delete[] a;
    return 0;
}

void fill_array(int a[], int size)
{
    using namespace std;
    cout << "Enter " << size << " integer values: " << endl;
    for (int index = 0; index < size; index++) {
        cin >> a[index];
    }
}

void sort(int a[], int size)
{
    using namespace std;
    IntPtr p;
    p = a;
    cout << p[1] << endl; // Print address of first element
    cout << a[1] << endl; // Print address of first element
    cout << &p[0] << endl; // Print address of pointer variable
    cout << &a[0] << endl; // Print address of array variable
    cout << &p[1] << endl; // Print address of pointer variable
    cout << &a[1] << endl; // Print address of array variable
    
    int temp;
    for (int pass = 0; pass < size - 1; pass++) {
        for (int index = 0; index < size - pass - 1; index++) {
            if (p[index] > p[index + 1]) {
                temp = p[index];
                p[index] = p[index + 1];
                p[index + 1] = temp;
            }
        }
    }
    cout << "The sorted values are: " << endl;
    for (int index = 0; index < size; index++) {
        cout << p[index] << " ";
    }
    cout << endl;
}