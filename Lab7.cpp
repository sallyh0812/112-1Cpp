/*string str_1;
int num_1;
num_1 = stoi(str_1);
1. transpose the matrix and calculate
the sum of the square of each element
in each row.
2. Based on Exercise-1 input file,
calculate the rank of each row.
*/

#include <iostream>
#include <fstream>
#include <iomanip> //for setw()
#include <cmath>
using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream1, outStream2;
    inStream.open("input1_Tue.txt");
    outStream1.open("output1_1.txt");
    outStream2.open("output1_2.txt");
    int matrix[5][5]; //動態宣告 if一開始不知道長寬
    int a, ans[5], rank;

    //read input file into array
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            inStream >> a;
            matrix[j][i] = a; //transpose
        }
    }

    //calculate the sum of square for each row
    for (int i = 0; i < 5; i++)
    {
        ans[i] = 0;
        for (int j = 0; j < 5; j++)
        {
            outStream1 << setw(8) << matrix[i][j];
            ans[i] += pow(matrix[i][j], 2);
        }
        outStream1 << "  = " << ans[i] << '\n';
    }

    //determine the rank
    for (int i = 0; i < 5; i++)
    {
        rank = 1;
        for (int j = 0; j < 5; j++)
        {
            outStream2 << setw(8) << matrix[i][j];
            if (j == i)
            {
                continue;
            }
            if (ans[i] > ans[j])
            {
                rank += 1;
            }
        }
        outStream2 << "  = rank" << rank << '\n';
    }

    return 0;
}