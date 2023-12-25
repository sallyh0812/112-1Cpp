/*a program that reads a file and asks the user for the number of lines they
want to see. The program will print the specified number of lines, and then
continue to ask the user how many lines of content they want to see, until the user
enters 0 or the entire file has been read.
- Input file name : input1.txt (naming error : -10%)
- You need to repeat to ask user how many lines of content they want to see
until the user enters 0 or the entire file has been read.
- If the number of lines entered by the user exceeds the total number of lines
in the file, you should print up to the last line of the file and terminate the
program.*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inStream;
    int count = 1, n;
    char next;
    cout << "How many lines do you want to see :";
    cin >> n;
    inStream.open("./input1.txt");
    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            inStream.get(next);
            while (!inStream.eof())
            {
                cout << next;
                if (next == '\n')
                {
                    break;
                }
                inStream.get(next);
            }
        }
        if (inStream.eof())
        {
            break;
        }
        cout << "How many lines do you want to see :";
        cin >> n;
    }
    return 0;
}