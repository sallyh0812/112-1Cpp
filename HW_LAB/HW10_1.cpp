/*a program to assign passengers seats in an airplane. Assume a small
airplane with seat numbering as Figure 1. The program should display the seat
pattern, with an X marking the seats already assigned. For example, after seats
1A, 2B, and 4C are taken, the display should look like Figure 2.
After displaying the seats available, the program prompts for the seat desired, the
user types in a seat, and then the display of available seats is updated. This
continues until all seats are filled or until the user signals that the program should
end. If the user types in a seat that is already assigned, the program should say
that that seat is occupied and ask for another choice.
- Limitation
◼ Input file name: input1.txt. Output file name: output1.txt. TA will
generate our own hidden case to check your program functionality with
this file name! (naming error: -10%)
◼ Cin and Cout operations are prohibited in this exercise.
- Airplane
◼ The number of rows is fixed at 7 rows.
◼ Each row will begin with a row ID, starting from 1, followed by the
letters ABCD, separated by a space.
- Input file
◼ When submitting the code, it should only accept a file named input1.txt
as input.
◼ Only 1A,1B, ..., 7D, END will appear in the input file.
- Output file
◼ When submitting the code, it should only accept a file named
output1.txt as output.
◼ Display the initial seat at the beginning.
◼ The user inputs a seat, and the display of available seats is updated.
◼ When the input is 'END,' print out 'End of choosing the seat.' and then
stop the program.
◼ If all seats are filled, print out 'All seats are occupied!' and then stop the
program.
◼ If the user types in a seat that is already assigned, print out 'The seat is
already occupied, please choose another seat.'.
◼ For output examples, please refer to the output1_1_ans.txt and
output1_2_ans.txt provided by the TA.*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int ctoi(char c);
char itoc(int n);
void printSeat(const int seat[4][7]);
int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("input1.txt");
    outStream.open("output1.txt");
    int seat[7][4] = {0};
    char n, c;
    int row, col, remains = 28;
    for (int i = 0; i < 7; i++)
    {
        outStream << i + 1;
        for (int j = 0; j < 4; j++)
        {
            if (seat[i][j])
            {
                outStream << setw(2) << 'X';
            }
            else
            {
                outStream << setw(2) << itoc(j);
            }
        }
        outStream << endl;
    }
    outStream << endl;

    while (!inStream.eof())
    {
        if (remains != 0)
        {
            
            inStream.get(n);
            if (n == '\n')
            {
                continue;
            }
            else if (n == 'E')
            {
                outStream << "Please choose a seat: END"<< endl;
                outStream << "End of choosing the seat.";
                break;
            }
            inStream.get(c);
            outStream << "Please choose a seat: "<< n << c << endl;
            row = (int)(n - '0') - 1;
            col = ctoi(c);
            if (seat[row][col] == 0)
            {
                seat[row][col] = 1;
                remains -= 1;
                for (int i = 0; i < 7; i++)
                {
                    outStream << i + 1;
                    for (int j = 0; j < 4; j++)
                    {
                        if (seat[i][j])
                        {
                            outStream << setw(2) << 'X';
                        }
                        else
                        {
                            outStream << setw(2) << itoc(j);
                        }
                    }
                    outStream << endl;
                }
            }
            else
            {
                outStream << "The seat is already occupied, please choose another seat." << endl;
            }
            outStream << endl;
        }
        else
        {
            outStream << "All seats are occupied!" ;
            break;
        }
    }

    return 0;
}
int ctoi(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
        break;
    case 'B':
        return 1;
        break;
    case 'C':
        return 2;
        break;
    case 'D':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}

char itoc(int n)
{
    switch (n)
    {
    case 0:
        return 'A';
        break;
    case 1:
        return 'B';
        break;
    case 2:
        return 'C';
        break;
    case 3:
        return 'D';
        break;
    default:
        return 'E';
        break;
    }
}