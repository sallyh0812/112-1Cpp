/*calculate what day is the date.
The main program should prompt user to input a date and
print out the corresponding day as well as the calendar
of the month of the date.

Hint: If the year is divisible by 4 and not by 100,
or the year is divisible by 400, it is a leap year.

Hint: The day of the first day of a year can be calculated with following formula.
Day = (y+ (y-1)/4 - (y-1)/100 + (y-1)/400) % 7
*/

#include <iostream>
#include <iomanip>
using namespace std;

bool isLeap(int year);
//Determine if the year is a leap year.
int Date2Day(int year, int month, int date);
// Get the day of the date. Define that “0” represents “Sunday”, “1” 	represents “Monday”, and so on. For example, 2023/10/31 -> 2(Tuesday).
void printDay(int year, int month, int date);
// Print out the mapping of the outputs from Date2Day
void printCalendar(int year, int month);
// Print out the monthly calendar of the month

int main()
{
    int year, month, date;
    while (true)
    {
        cout << "Input the date:";
        cin >> year >> month >> date;
        if (year == 0 && month == 0 && date == 0)
        {
            cout << "\n-----------------------\n";
            break;
        }
        printDay(year, month, date);
        printCalendar(year, month);
        cout << "\n-----------------------\n";
    }

    return 0;
}

bool isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Date2Day(int year, int month, int date)
{
    int firstDay = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7; // January 1st
    int day = 0;
    for (int i = 1; i < month; i++)
    {
        switch (i)
        {
        case 1:
            day += 31;
            break;

        case 2:
            if (isLeap(year))
            {
                day += 29;
            }
            else
            {
                day += 28;
            }
            break;

        case 3:
            day += 31;
            break;

        case 4:
            day += 30;
            break;

        case 5:
            day += 31;
            break;

        case 6:
            day += 30;
            break;

        case 7:
            day += 31;
            break;

        case 8:
            day += 31;
            break;

        case 9:
            day += 30;
            break;

        case 10:
            day += 31;
            break;

        case 11:
            day += 30;
            break;

        case 12:
            day += 31;
            break;

        default:
            break;
        }
    }
    day = (firstDay + day + date - 1) % 7;
    return day;
}

void printDay(int year, int month, int date)
{
    switch (Date2Day(year, month, date))
    {
    case 0:
        cout << "Sunday\n";
        break;
    case 1:
        cout << "Monday\n";
        break;
    case 2:
        cout << "Tuesday\n";
        break;
    case 3:
        cout << "Wednesday\n";
        break;
    case 4:
        cout << "Thursday\n";
        break;
    case 5:
        cout << "Friday\n";
        break;
    case 6:
        cout << "Saturday\n";
        break;
    }
}

void printCalendar(int year, int month)
{
    cout << " SU MO TU WE TH FR SA\n";
    for (int i = 0; i < Date2Day(year, month, 1); i++)
    {
        cout << "   ";
    }
    int daysInMonth;
    switch (month)
    {
    case 1:
        daysInMonth = 31;
        break;

    case 2:
        if (isLeap(year))
        {
            daysInMonth = 29;
        }
        else
        {
            daysInMonth = 28;
        }
        break;

    case 3:
        daysInMonth = 31;
        break;

    case 4:
        daysInMonth = 30;
        break;

    case 5:
        daysInMonth = 31;
        break;

    case 6:
        daysInMonth = 30;
        break;

    case 7:
        daysInMonth = 31;
        break;

    case 8:
        daysInMonth = 31;
        break;

    case 9:
        daysInMonth = 30;
        break;

    case 10:
        daysInMonth = 31;
        break;

    case 11:
        daysInMonth = 30;
        break;

    case 12:
        daysInMonth = 31;
        break;

    default:
        break;
    }
    for (int i = 1; i <= daysInMonth; i++)
    {
        cout << " " << std::setw(2) << std::setfill(' ') << i;
        if (Date2Day(year, month, i) == 6)
        {
            cout << "\n";
        }
    }
}