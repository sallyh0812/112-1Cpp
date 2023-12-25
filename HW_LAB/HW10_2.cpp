/*A program that reads in a line of text and outputs the line with all the
digits in all integer numbers replaced with ‘x’.For example,
Input:
My userID is John17 and my 4 digits pin is 1234 which is secret.
Output:
My userID is John17 and my x digits pin is xxxx which is secret.
Note that if a digit is part of a word, then the digit is not changed to an ‘x’. For
example, note that john17 is NOT changed to johnxx.
Include a loop that allows the user to repeat this calculation again
until the user says she or he wants to end the program.
- Input format:
The user enters a sentence with digits in some words, and the last word
end with a dot ’.’
- Output format:
Turn each word with all digits to ‘x’
- Terminate program:
Enter -1
- Sample input/output (on screen/terminal):
- Note:
◼ The dot ‘.’ is part of last word, so don’t turn this word into digits.
◼ Words are separated by a space(blank). For example, (12 / 31)
includes three words “12”, “/” and “31” */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Input: " << endl;
    cin >> s;
    while (s != "-1")
    {
        bool digit = false;
        cout << "Output: " << endl;
        while (s[s.length() - 1] != '.')
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '.')
                {
                }
                if (s[i] == ' ')
                {
                }
                if (isdigit(s[i]))
                {
                    digit = true;
                }
                else
                {
                    digit = false;
                    break;
                }
            }
            if (digit)
            {
                for (int i = 0; i < s.length(); i++)
                {
                    cout << 'x';
                }
                cout << " ";
            }
            else
            {
                cout << s << " ";
            }
            cin >> s;
        }
        cout << s << "\n\n";
        cout << "Input: " << endl;
        cin >> s;
    }

    return 0;
}
