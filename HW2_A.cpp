#include <iostream>
#include <string>
using namespace std;

int main()
{
    double hour, grossPay, socialSecurity, federalIncome;
    double stateIncome, netTakeHome;
    int dependent, unionDue, healthInsurance;
    char option;

    do
    {
        cout << "############### Paid Calculator ###############\n";
        cout << "Enter the number of hours worked in a week: ";
        cin >> hour;
        cout << "Enter the number of dependents: ";
        cin >> dependent;

        if (hour > 40)
        {
            grossPay = 16.78 * 40 + 16.78 * 1.5 * (hour - 40);
        }
        else
        {
            grossPay = 16.78 * hour;
        }

        socialSecurity = grossPay * 0.06;
        federalIncome = grossPay * 0.14;
        stateIncome = grossPay * 0.05;
        unionDue = 10;

        cout << "Gross Pay: $" << grossPay << endl;
        cout << "Social Security Tax: $" << socialSecurity << endl;
        cout << "Federal Income Tax: $" << federalIncome << endl;
        cout << "State Income Tax: $" << stateIncome << endl;
        cout << "Union Dues: $" << unionDue << endl;
        if (dependent >= 3)
        {
            healthInsurance = 35;
            cout << "Health Insurance: $35" << endl;
        }
        else
        {
            healthInsurance = 0;
        }
        netTakeHome = grossPay - (socialSecurity + federalIncome + stateIncome + unionDue + healthInsurance);
        cout << "Net Take-Home Pay: $" << netTakeHome << endl;
        cout << "###############################################\n";

        cout << "Do you want to calculate again? (yY/nN): ";
        cin >> option;
    } while (option == 'y' || option == 'Y');
    cout << "Thanks for using the Paid Calculator, Bye";
}