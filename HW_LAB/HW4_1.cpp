/*Write an astrology program. The user types in a birthday, and the program
respond with the sign and horoscope for that birthday. The month may be entered
as a number from 1 to 12.
This program will have a long multiway branch (Please use ‘Switch’). Your
program should include a loop that lets the user repeat this calculation until the
user says she or he is done.*/

#include <iostream>
#include <string>
using namespace std;

int monthToNum(string month_s);

int main()
{
    string month, ans;
    int monthInt, date;
    do
    {
        cout << "Input the month : ";
        cin >> month;
        monthInt = monthToNum(month);

        switch (monthInt)
        {
        case 1:
            cout << "Input the date : ";
            cin >> date;
            if (date > 31 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }

            if (date >= 20)
            {
                ans = "Aquarius";
            }
            else
            {
                ans = "Capricorn";
            }
            break;

        case 2:
            cout << "Input the date : ";
            cin >> date;
            if (date > 28 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 19)
            {
                ans = "Pisces";
            }
            else
            {
                ans = "Aquarius";
            }
            break;

        case 3:
            cout << "Input the date : ";
            cin >> date;
            if (date > 31 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 21)
            {
                ans = "Aries";
            }
            else
            {
                ans = "Pisces";
            }
            break;

        case 4:
            cout << "Input the date : ";
            cin >> date;
            if (date > 30 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 20)
            {
                ans = "Taurus";
            }
            else
            {
                ans = "Aries";
            }
            break;

        case 5:
            cout << "Input the date : ";
            cin >> date;
            if (date > 31 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 21)
            {
                ans = "Gemini";
            }
            else
            {
                ans = "Taurus ";
            }
            break;

        case 6:
            cout << "Input the date : ";
            cin >> date;
            if (date > 30 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 22)
            {
                ans = "Cancer";
            }
            else
            {
                ans = "Gemini";
            }
            break;

        case 7:
            cout << "Input the date : ";
            cin >> date;
            if (date > 31 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 23)
            {
                ans = "Leo";
            }
            else
            {
                ans = "Cancer";
            }
            break;

        case 8:
            cout << "Input the date : ";
            cin >> date;
            if (date > 31 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 23)
            {
                ans = "Virgo";
            }
            else
            {
                ans = "Leo";
            }
            break;

        case 9:
            cout << "Input the date : ";
            cin >> date;
            if (date > 30 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 23)
            {
                ans = "Libra";
            }
            else
            {
                ans = "Virgo";
            }
            break;

        case 10:
            cout << "Input the date : ";
            cin >> date;
            if (date > 31 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 23)
            {
                ans = "Scorpio";
            }
            else
            {
                ans = "Libra";
            }
            break;

        case 11:
            cout << "Input the date : ";
            cin >> date;
            if (date > 30 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 22)
            {
                ans = "Sagittarius ";
            }
            else
            {
                ans = "Scorpio";
            }
            break;

        case 12:
            cout << "Input the date : ";
            cin >> date;
            if (date > 31 || date < 1)
            {
                ans = "Wrong date !";
                break;
            }
            if (date >= 22)
            {
                ans = "Capricorn";
            }
            else
            {
                ans = "Sagittarius";
            }
            break;

        case -1:
            ans = "";
        default:
            break;
        }
        cout << ans << endl;
    } while (month != "done" && month != "Done");

    return 0;
}

int monthToNum(string month_s)
{
    int month_i;
    if (month_s == "January" || month_s == "january" || month_s == "1")
        month_i = 1;
    else if (month_s == "February" || month_s == "february" || month_s == "2")
        month_i = 2;
    else if (month_s == "March" || month_s == "march" || month_s == "3")
        month_i = 3;
    else if (month_s == "April" || month_s == "april" || month_s == "4")
        month_i = 4;
    else if (month_s == "May" || month_s == "may" || month_s == "5")
        month_i = 5;
    else if (month_s == "June" || month_s == "june" || month_s == "6")
        month_i = 6;
    else if (month_s == "July" || month_s == "july" || month_s == "7")
        month_i = 7;
    else if (month_s == "August" || month_s == "august" || month_s == "8")
        month_i = 8;
    else if (month_s == "September" || month_s == "september" || month_s == "9")
        month_i = 9;
    else if (month_s == "October" || month_s == "october" || month_s == "10")
        month_i = 10;
    else if (month_s == "November" || month_s == "november" || month_s == "11")
        month_i = 11;
    else if (month_s == "December" || month_s == "december" || month_s == "12")
        month_i = 12;
    else
        return -1;
    return month_i;
}