/* a program that will compute the average word length (average number of
characters per word) for a file that contains some text. A word is defined to be any
string of symbols that is preceded and followed by one of the following at each
end: a blank, a comma, a period, the beginning of a line, or the end of a line. Your
program should define a function that is called with the input-file stream as an
argument.

You should write the following function in your program to complete the
average word length calculation
    void wordLengthCal (ifstream& fileIn);
Return type can be modified and you can add other parameters if you need.
- Note that words with zero length will not be considered.
- A blank, a comma, a period, the beginning of a line, or the end of a line won't
be counted in number of characters.
- When you compute average word length, the type should be double or you
may get wrong answer*/

#include <iostream>
#include <fstream>
using namespace std;

void wordLengthCal(ifstream &fileIn, int &word, int &totalLength);

int main()
{
    ifstream inStream;
    inStream.open("input2.txt");
    int word = 0, totalLength = 0;
    double avg;
    wordLengthCal(inStream, word, totalLength);
    avg = (double)totalLength / word;
    cout << avg << endl;

    return 0;
}

void wordLengthCal(ifstream &fileIn, int &word, int &totalLength)
{
    char c;
    bool isWord = false;
    while (!fileIn.eof())
    {
        fileIn.get(c);
        if (c == ' ' || c == ',' || c == '\n' || c == '.' || fileIn.eof())
        {
            if (isWord)
            {
                word += 1;
                isWord = false;
            }
        }
        else
        {
            totalLength += 1;
            isWord = true;
            //cout << totalLength << " ";
        }
    }
}