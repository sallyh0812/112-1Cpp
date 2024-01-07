#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

const string ASCII_H = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"; //$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`\'. ";
const string ASCII_M = " .:-=+*#%@";                                                               //"@%#*+=-:. ";
const int W = 3;

void display(int **img, int height, int width)
{
    // ofstream asciiFile;
    // asciiFile.open(ACSIIOUT);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (img[y][x] > 174)
            {
                cout << setw(W) << '@';
                // asciiFile <<setw(W) << '@';
            }
            else
            {
                cout << setw(W) << '-';
                // asciiFile << setw(W) <<'-';
            }
        }
        cout << endl;
        // asciiFile << endl;
    }
    cout << endl;
    // asciiFile << endl;
    // asciiFile.close();
}

void displayMQ(int **img, int height, int width)
{
    // ofstream asciiFile;
    //  asciiFile.open(ACSIIOUT);
    int unit = 256 / ASCII_M.length();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << setw(W) << ASCII_M[min(img[y][x] / unit, int(ASCII_M.length() - 1))];
            // asciiFile << ASCII[img[y][x] / UNIT];
        }
        cout << endl;
        // asciiFile << endl;
    }
    cout << endl;
    // asciiFile << endl;
    // asciiFile.close();
}

void displayHQ(int **img, int height, int width)
{
    // ofstream asciiFile;
    //  asciiFile.open(ACSIIOUT);
    int unit = 256 / ASCII_H.length();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << setw(W) << ASCII_H[min(img[y][x] / unit, int(ASCII_H.length() - 1))];
            // asciiFile << ASCII[img[y][x] / UNIT];
        }
        cout << endl;
        // asciiFile << endl;
    }
    cout << endl;
    // asciiFile << endl;
    //  asciiFile.close();
}