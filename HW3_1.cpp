/*You have just purchased a stereo system that cost $ 1,000 on the following credit 
plan: no down payment. The monthly payment of $50 is used to 
pay the interest and whatever is left is used to pay part of the remaining debt. 
Hence, the first month you pay 1.5% of $1,000 in interest. That is $15 in interest. 
So, the remaining $35 is deducted from your debt, which leaves you with a debt 
of $965.00. The next month you pay interest of 1.5% of $965.00, which is 
$14.48. Hence, you can deduct $35.52 (which is $50 - $14.48) from the amount 
you owe. Write a program that will tell you how many months it will take 
you to pay off the loan, as well as the total amount of interest paid over the 
life of the loan.*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    float rate=0.015, pay=50;
    float sumInterest, loan, interest;
    int countMonth = 0;
    cout << "Enter loan :";
    cin >> loan;
    while(loan > 0){
        countMonth++;
        interest = ceil(loan * rate * 100)/100; //對小數點第二位做無條件進位
        sumInterest += interest;
        loan = loan + interest - pay;
    }

    cout << "How many months it will take you to pay off the loan: " << countMonth << endl;
    cout << "The total mount of interest is: " << sumInterest << endl;
    return 0;
}