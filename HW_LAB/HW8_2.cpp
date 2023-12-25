/*This program numbers the lines found in a text file. Write a program that
reads text from a file and outputs each line to the screen and to another file
preceded by a line number. Print the line number at the start of the line
and right-adjusted in a field of three spaces. Follow the line number with a
colon, then one space, then the text of the line. You should get a character
at a time and write code to ignore leading blanks on each line, You may
assume that the lines are short enough to fit within a line on the screen.
- Input file name : input2.txt
- Output file name : output2.txt
- line numbers are followed by 1 , 2 , 3 , 4…… 
*/

#include <iostream>
#include <fstream>
#include <iomanip> //for setw()
#include <cmath>
using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("input2.txt");
    outStream.open("output2.txt");
    int line = 1;
    char c;
    while(!inStream.eof()){
        do{
            inStream.get(c);
        }while(c==' ');
        inStream.putback(c);
        cout << setw(3) << right << line << " : ";
        outStream << setw(3) << right << line << " : ";
        do{
            inStream.get(c);
            if(inStream.eof()){
                break;
            }
            cout << c;
            outStream << c;
        }while(c!='\n');
        line += 1;
    }
    
    return 0;
}