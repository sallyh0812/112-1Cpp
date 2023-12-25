#include <iostream>
using namespace std;

int ways(int x, int y);

int main()
{
    int x, y, ans;

    while (true)
    {
        cout << "Please input x and y in order:";
        cin >> x >> y;
        if (x == 0 && y == 0)
        {
            break;
        }
        ans = ways(x, y);
        cout << "answer: " << ans << "\n";
    }

    return 0;
}

int ways(int x, int y)
{
    // x<0 y<0 return 0
    if (x < 0 || y < 0){
        return 0;
    }
    if (x == 0 && y == 1 || x == 1 && y == 0 || x == 0 && y == 0){
        return 1;
    }
    else
    {
        return ways(x - 1, y) + ways(x - 2, y) + ways(x, y - 2) + ways(x, y - 1);
    }
}
