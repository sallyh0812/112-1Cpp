/*A standard deviation, S, of a list of N numbers x is defined as Formula I. In this
exercise, you will be given a partially filled array. Your goal is to calculate the
correct standard deviation of this partially filled array.
𝑭𝒐𝒓𝒎𝒖𝒍𝒂 𝑰: 𝑆 = √ (∑(𝑥𝑖 − 𝑥̅)^2 / N)
, 𝑤ℎ𝑒𝑟𝑒 𝑥̅ 𝑖𝑠 𝑡ℎ𝑒 𝑎𝑣𝑒𝑟𝑎𝑔𝑒 𝑜𝑓 𝑡ℎ𝑒 𝑁 𝑛𝑢𝑚𝑒𝑟𝑠
- Input file name: input1.txt (naming error: -10%). TA will generate our own
hidden case to check your program functionality with this file name!
- inStream operation is prohibited in this exercise.
- Your program needs to be able to read multiple input cases, and print the
correct results on the terminal, separated by endl.
- Your results should be rounded to 2nd decimal places.
(Hint: cout << fixed << setprecision(2) )
- In input1.txt, the first number N is size, and the following N lines are the values
xi. Each case is separated by an endl.
- 1 ≤ N ≤ 100, each x being double type.
- You have to define a function “calculate_sd” to calculate result using two
formal parameters: 1. an array parameter , 2. array size.
- When size = 0, stop the program
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

#define MAX 100

double calculate_sd(const double data[], int size);

int main()
{
    ifstream inStream;
    inStream.open("input1.txt");
    int size;
    double data[MAX];
    double x, sd;
    inStream >> size;
    while (size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            inStream >> x;
            data[i] = x;
        }
        sd = calculate_sd(data,size);
        cout << fixed << setprecision(2) << sd << endl;
        inStream >> size;
    }
    return 0;
}

double calculate_sd(const double data[], int size){
    double sum=0, avg, sumOfSquare=0, sd;
    for (int i = 0; i<size; i++){
        sum += data[i];
    }
    avg = sum / size;

    for (int i = 0; i<size; i++){
        sumOfSquare += pow(data[i]-avg,2);
    }
    sd = sqrt(sumOfSquare/size);
    return sd;
}