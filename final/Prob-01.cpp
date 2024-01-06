#include <iostream>
using namespace std;

int main()
{
    int W, L;
    cin >> W >> L;
    int matrix[W][L];
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < L; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int max = 0, sum = 0;
    bool find_zero = false;
    for (int size = 2; size < min(W, L); size++)
    {
        for (int i = 0; i < W - size + 1; i++)
        {
            for (int j = 0; j < L - size + 1; j++)
            {
                sum = 0;
                find_zero = false;
                for (int is = 0; is < size; is++)
                {
                    for (int js = 0; js < size; js++)
                    {
                        if (matrix[i + is][j+js] == 0)
                        {
                            find_zero = true;
                        }
                        sum += matrix[i + is][j+js];
                    }
                }
                if(!find_zero && sum > max){
                    max = sum;
                }
            }
        }
    }
    cout << max <<endl;
    return 0;
}