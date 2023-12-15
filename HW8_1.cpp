/*a program that reads a file and answer the question. The program
will print the answer from the file for your question, and then continue to
answer the question that you ask, until the user enters “12345” to end the
program.
-Input file name : input1.txt (naming error : -10%)
-You need to use the random function to change the chapter number.
-You need to repeat to enter your question until you enter “12345”.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void printLine(ifstream &input);

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("input1.txt");
    string s, question;

    getline(cin, question);
    while (question != "12345")
    {
        if (inStream.eof())
        {
            inStream.close();
            inStream.open("input1.txt");
        }
        printLine(inStream);
        getline(cin, question);
    }

    return 0;
}

void printLine(ifstream &input)
{
    char c;
    int randint;
    while (!input.eof())
    {
        input.get(c);
        if (c == '\n' || input.eof())
        {
            break;
        }
        if (c == '#')
        {
            randint = rand() % 20;
            cout << randint << ".";
            do
            {
                input.get(c);
            } while (c != '\n');
            break;
        }
        cout << c;
    }
    cout << "\n";
}