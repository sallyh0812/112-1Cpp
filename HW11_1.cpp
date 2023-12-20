/*Limitation
◼ Input file name: input1.txt. Output file name: output1.txt. TA will
generate our own hidden case to check your program functionality with
this file name! (naming error: -10%)
◼ Cin and Cout operations are prohibited in this exercise.
- Given a function :
vector<string> split(string target, string delimiter);
implement the function split so that it returns a vector of the strings in target
that are separated by the string delimiter.
For example:
split(“1+2+3” , “+”)
should return a vector with the strings “1”, “2”, “3”.
Similarly,
split(“AdBdC” , “d”)
should return a vector with the strings “A”, “B”, “C”.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string target, string delimiter);
int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("HW11_input1_2.txt");
    outStream.open("HW11_output1_2.txt");
    string target, delimiter;
    getline(inStream, target);
    getline(inStream, delimiter);
    vector<string> ans;
    ans = split(target, delimiter);
    for(int i =0;i<ans.size();i++){
        outStream << i << " : " << ans[i] << endl;
    }
    return 0;
}

vector<string> split(string target, string delimiter)
{
    vector<string> ans;
    string s;
    for (int i = 0; i < target.length(); i++)
    {
        if (target[i] == delimiter[0])
        {
            ans.push_back(s);
            s = "";
        }
        else if(i==target.length()-1){
            s += target[i];
            ans.push_back(s);
        }
        else
        {
            s += target[i];
        }
    }
    return ans;
}