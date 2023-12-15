/*a program that tells what coins to give out for any amount of change
from 1 cent to 99 cents. Use coin denominations of 25 cents (quarters), 10
cents (dimes), and 1 cent (pennies).
For example, if the amount is 86 cents, the output would be the following:
86 cents can be given as 3 quarter(s), 1 dime(s) and 1 penny(pennies).
You should write the following function in your program
void computeCoins (int coinValue, int& num, int& amountLeft);

Precondition: 0 < coinValue < 100; 0 <= amountLeft < 100.
Postcondition: num has been set equal to the maximum number of
coins of denomination coinValue cents that can be obtained from
amountLeft. Additionally, amountLeft has been decreased by the
value of the coins, that is, decreased by num * coinValue.

Include a loop that lets the user repeat this computation for new input
values until the user says he or she wants to end the program. (Hint: Use
integer division and the % operator to implement the required function.)*/

#include <iostream>
using namespace std;

void computeCoins(int coinValue, int &num, int &amountLeft);

int main()
{
    int change, numCoins;
    cout << "Please enter the amount of change: ";
    cin >> change;
    while (change != 0)
    {
        cout << change << " cent(s) = ";
        computeCoins(25, numCoins, change);
        cout << numCoins << " quarter(s) + ";
        computeCoins(10, numCoins, change);
        cout << numCoins << " dime(s) + ";
        cout << change << " penny(pennies)" << "\n";
        cout << "Please enter the amount of change: ";
        cin >> change;
    }

    return 0;
}

void computeCoins(int coinValue, int &num, int &amountLeft)
{
    num = amountLeft / coinValue;
    amountLeft %= coinValue;
}