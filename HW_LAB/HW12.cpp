/*Creates a one-dimensional dynamic array to emulate a two-dimensional array
and returns a pointer to the one-dimensional dynamic array.
Please complete HW12 by using the following functions:
1.void set(int *arr, int rows, int columns, int desired_row, int desired_column, int val)
2.void get(int *arr, int rows, int columns, int desired_row, int desired_column)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void set(int *arr, int rows, int columns, int desired_row, int desired_column, int val);
void get(int *arr, int rows, int columns, int desired_row, int desired_column);

int main()
{
    int row, column, desired_row, desired_col, val;
    while (true)
    {
        cout << "Enter rows and columns of 2D array:\n";
        cin >> row;
        cin >> column;
        int *arr = new int [row * column];

        cout << "Memory allocation is created for array\n";
        cout << "Enter the desired rows and columns of array to set the values:\n";
        cin >> desired_row;
        cin >> desired_col;
        if (desired_row >= row || desired_col >= column || desired_row < 0 || desired_col < 0)
        {
            cout << "Desired indices are invalid\n";
            break;
        }
        cout << "Enter the value to set in the array:\n";
        cin >> val;
        set(arr, row, column, desired_row, desired_col, val);
        cout << "Enter the desired rows and columns of array to get the values:\n";
        cin >> desired_row;
        cin >> desired_col;
        if (desired_row >= row || desired_col >= column || desired_row < 0 || desired_col < 0)
        {
            cout << "Desired indices are invalid\n";
            break;
        }
        get(arr, row, column, desired_row, desired_col);
    }

    return 0;
}

void set(int *arr, int rows, int columns, int desired_row, int desired_column, int val)
{
    arr[desired_row * columns + desired_column] = val;
}

void get(int *arr, int rows, int columns, int desired_row, int desired_column)
{
    cout << "The value from the desired index is  : " << arr[desired_row * columns + desired_column] << endl;
}