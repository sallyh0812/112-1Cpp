/*Write a program to score the paper-rock-scissor game. Each of two users types in
either P, R or S. The program then announces the winner as well as the basis for
determining the winner: Paper covers rock, Rock breaks scissors, Scissors cut
paper, or Nobody wins. Be sure to allow the users to use lowercase as well as
uppercase letters. Your program should include a loop that lets the user play
again until the user says she or he is done*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    char player1, player2;
    int winner;

    do
    {
        winner = -1;
        cout << "Paper-rock-scissor :";
        cin >> player1 >> player2;
        switch (player1)
        {
        case 'S':
        case 's':
            switch (player2)
            {
            case 'S':
            case 's':
                winner = 0;
                cout << "Tie !" << endl;
                break;
            case 'R':
            case 'r':
                winner = 2;
                cout << "User " << winner << " wins !" << endl;
                break;
            case 'P':
            case 'p':
                winner = 1;
                cout << "User " << winner << " wins !" << endl;
                break;
            }
            break;
        case 'R':
        case 'r':
            switch (player2)
            {
            case 'S':
            case 's':
                winner = 1;
                cout << "User " << winner << " wins !" << endl;
                break;
            case 'R':
            case 'r':
                winner = 0;
                cout << "Tie !" << endl;
                break;
            case 'P':
            case 'p':
                winner = 2;
                cout << "User " << winner << " wins !" << endl;
                break;
            }
            break;
        case 'P':
        case 'p':
            switch (player2)
            {
            case 'S':
            case 's':
                winner = 2;
                cout << "User " << winner << " wins !" << endl;
                break;
            case 'R':
            case 'r':
                winner = 1;
                cout << "User " << winner << " wins !" << endl;
                break;
            case 'P':
            case 'p':
                winner = 0;
                cout << "Tie !" << endl;
                break;
            }
            break;

        default:
            winner = -1;
            cout << endl;
            break;
        }

    } while (winner != -1);

    return 0;
}