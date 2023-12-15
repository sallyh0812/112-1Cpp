/*In this exercise you are required to write a program that reads in two positive
integers that are 20 or fewer digits in length and then outputs the sum of the two
numbers. Your program will read the digits as values of type “char” so that input
cases, e.g. 1234 for A is read as the four characters ‘1’, ‘2’, ‘3’, and ‘4’. After that,
the characters are then changed to values of type “int”. The digits will be read into
a partially filled array. Then, your program will perform the addition by
implementing the usual paper-and-pencil addition algorithm. The result of the
addition is stored in an array of size 20, and the result is then written to the screen.
If the result of the addition is an integer with more than maximum number of digits
(that is, more than 20 digits), then your program should issue a related “overflow”
message.
- Input file name: input2.txt (naming error: -10%). TA will generate our own
hidden case to check your program functionality with this file name.
- Cin operation is prohibited in this exercise.
- Your program should be able to read multiple input cases, and print readable
correct results in the terminal, separated by endl.
- In the input2.txt, the first row of two positive integers represent A and B
respectively, and so on.
- Your results shown in the terminal should follow the example output format
figure down below, including the “Overflow” case.
- Notice: Data type of all input cases are positive integer.
- Simply adding A and B together (e.g. cout << a + b << endl) is not allowed!
Please perform the paper-and-pencil addition algorithm mentioned above
using array.
- When A = 0, B = 0, stop the program
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

#define MAX 20

int main()
{
    ifstream inStream;
    inStream.open("input2.txt");
    int A[MAX], B[MAX], alen = 0, blen = 0;
    bool meetNum;
    char c;
    while (!inStream.eof())
    {
        alen = 0;
        blen = 0;
        //read A
        while (!inStream.eof())
        {
            inStream.get(c);
            if (c == ' ')
            {
                break;
            }
            if (alen < MAX)
            {
                A[alen] = (int)(c - '0');
            }
            alen++;
        }
        
        //read B
        while (!inStream.eof())
        {
            inStream.get(c);
            if (c == '\n' || inStream.eof())
            {
                break;
            }
            if (blen < MAX)
            {
                B[blen] = (int)(c - '0');
            }
            blen++;
        }
        
        //if A,B == 0,0: break
        if (A[0] == 0 && B[0] == 0)
        {
            break;
        }
        
        //if A,B more than 20 digits: overflow, continue
        if (alen > MAX || blen > MAX)
        {
            cout << "Overflow!" << endl;
            continue;
        }
        
        int sum[MAX + 1] = {0};
        
        //calculate sum by paper-pencil addition algorithm
        for (int i = 0; i < min(alen, blen); i++)
        {
            sum[i] += (A[alen - i - 1] + B[blen - i - 1]);
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        for (int i = min(alen, blen); i < max(alen, blen); i++)
        {
            sum[i] += alen > blen ? A[alen - i - 1] : B[blen - i - 1];
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }

        //if A+B more than 20 digit: overflow
        if (sum[MAX] != 0)
        {
            cout << "Overflow!" << endl;
        }
        else
        {
            cout << "A + B = ";
            meetNum = false;
            for (int i = MAX; i >= 0; i--)
            {   
                //skip zeros at the front
                if (sum[i] == 0 && !meetNum)
                {
                    continue;
                }
                else
                {
                    cout << sum[i];
                    meetNum = true;
                }
            }
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}