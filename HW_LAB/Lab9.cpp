/**/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    ifstream inStream;
    inStream.open("Conv_demo.txt");
    int size;
    inStream >> size;

    while (size != -1)
    {
        // 2D array with size*size
        int **img = new int *[size];
        for (int i = 0; i < size; i++)
        {
            img[i] = new int[size];
        }

        // 2D array after convolution
        int **conv = new int *[size - 2];
        for (int i = 0; i < size - 2; i++)
        {
            conv[i] = new int[size - 2]();
        }

        int kernel[3][3];

        // read img array
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                inStream >> img[i][j];
            }
        }

        // read kernel
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                inStream >> kernel[i][j];
            }
        }

        // calculation
        for (int i = 0; i < size - 2; i++)
        {
            for (int j = 0; j < size - 2; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        conv[i][j] += img[i + k][j + m] * kernel[k][m];
                    }
                }
            }
        }

        // output
        for (int i = 0; i < size - 2; i++)
        {
            for (int j = 0; j < size - 2; j++)
            {
                cout << setw(4) << conv[i][j] << " ";
            }
            cout << "\n";
        }

        delete[] img;
        delete[] conv;
        inStream >> size;
    }
    return 0;
}