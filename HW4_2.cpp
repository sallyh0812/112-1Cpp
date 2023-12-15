/*You need to find out a four-digit number where: (ex: abcd)
All four digits are different (a, b, c, d are different)
The digit int the thousands place is three times the digit in the tens place (a =
c*3)
The number is odd (abcd % 2 is one)
The sum of the digit is 27 (a+b+c+d = 27)*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    for (c = 1; c <= 3; c++) //because a < 9 and a,c must not be 0
    {
        a = c * 3;

        for (d = 1; d <= 9; d += 2) // odd
        {
            if (d == a || d == c)
                continue;
            for (b = 0; b <= 9; b++)
            {
                if (b == c || b == a || b == d)
                    continue;
                if ((a + b + c + d) == 27)
                {
                    cout << a << b << c << d << endl;
                }
            }
        }
    }
    return 0;
}