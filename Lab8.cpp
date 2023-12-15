/*You are an astronaut on a distant planet, equipped with a set of
alien numbers(int). Your mission is to write a program that
calculates how many pairs of these numbers can form the
activation code to return to Earth. Are you ready for the
challenge?
*/

#include <iostream>
using namespace std;

int pairs(const int array[], int size, int code);

int main()
{
    int size, activation;
    cout << "Please enter the size of the alien numbers array: ";
    cin >> size;
    while (size != 0)
    {
        int *alien = new int[size];
        cout << "Please enter 5 elements for the alien nymbers array:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> alien[i];
        }
        cout << "Entered alien numbers: ";
        for (int i = 0; i < size; i++)
        {
            cout << alien[i] << " ";
        }
        cout << "\n";
        cout << "Please enter your activation code: ";
        cin >> activation;
        cout << "pairs: " << pairs(alien, size, activation) << "\n";
        delete[] alien;
        cout << "Please enter the size of the alien numbers array: ";
        cin >> size;
    }

    return 0;
}

int pairs(const int array[], int size, int code)
{
    int ans = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] + array[j] == code)
            {
                ans += 1;
            }
        }
    }
    return ans;
}