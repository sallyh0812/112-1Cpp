#include <iostream>
using namespace std;

int main()
{
  int a, b, c;
  cout << "Enter three integer numbers: ";
  cin >> a >> b >> c;
  if (a > b)
  {
    if (a > c)
    {
      if (b > c)
      {
        // cba
        cout << "Numbers in ascending order: " << c << " " << b << " " << a << endl;
      }
      else
      {
        // bca
        cout << "Numbers in ascending order: " << b << " " << c << " " << a << endl;
      }
    }
    else
    {
      // bac
      cout << "Numbers in ascending order: " << b << " " << a << " " << c << endl;
    }
  }
  else
  {
    if (b > c)
    {
      if (c > a)
      {
        // acb
        cout << "Numbers in ascending order: " << a << " " << c << " " << b << endl;
      }
      else
      {
        // cab
        cout << "Numbers in ascending order: " << c << " " << a << " " << b << endl;
      }
    }
    else
    {
      // abc
      cout << "Numbers in ascending order: " << a << " " << b << " " << c << endl;
    }
  }
}