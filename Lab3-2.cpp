/*Given a number, find the product of all its factors and
print it on the screen.
(assume num = d1 * d2 which d2 >= d1)*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    do
    {
    	cout << "Please enter a number: ";
        cin >> num;
        if (num == 1)
        {
            cout << "1 = 1" << endl;
        }
        else
        {
            int check = int(sqrt(num));
            for (int i = 1; i <= check; i++)
            {
                if (num % i == 0)
                {
                    cout << num << " = " << i << " * " << num / i << endl;
                }
            }
        }
    } while (num != 1);

    return 0;
}
