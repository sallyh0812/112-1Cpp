/**/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define MAX 100000
using namespace std;

void specialNum(vector<int> &special_num);
bool isSpecialNum(int n);
int main()
{
    vector<int> special_num;
    string s, word, num;
    int count;
    specialNum(special_num);
    cout << "Please enter a string : ";
    cin >> s;
    while (s != "0")
    {
        num = "";
        word = "";

        // seperate word with digit
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                num += s[i];
            }
            else
            {
                word += s[i];
            }
        }

        cout << endl;

        if (word.empty())
        {
            cout << "all numbers" << endl;
        }
        else
        {
            // count each word
            for (int ascii = 33; ascii < 128; ascii++)
            {
                if (word.find(char(ascii)) != -1)
                {
                    count = 0;
                    for (int i = 0; i < word.length(); i++)
                    {
                        if (word[i] == char(ascii))
                        {
                            count++;
                        }
                    }
                    cout << char(ascii) << " : " << count << endl;
                }
            }
        }

        cout << "In the range from 10 to " << stoi(num) << endl;

        // determine special number
        for (int i = 10; i < special_num.size(); i++)
        {
            if (special_num[i] >= stoi(num))
            {
                break;
            }
            cout << special_num[i] << endl;
        }
        cout << "Please enter a string : ";
        cin >> s;
    }
    cout << endl;
    return 0;
}

void specialNum(vector<int> &special_num)
{
    for (int i = 0; i < MAX; i++)
    {
        if (isSpecialNum(i))
        {
            special_num.push_back(i);
        }
    }
}

bool isSpecialNum(int n)
{
    string str;
    str = to_string(n);
    int slen = str.length();
    int sum = 0;
    for (int i = 0; i < slen; i++)
    {
        sum += pow(int(str[i] - '0'), slen);
    }
    if (sum == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}