#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

const string LINE = "========================================================================================================================================================";
const string ASCII_H = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"; //$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`\'. ";
const string ASCII_M = " .:-=+*#%@";                                                               //"@%#*+=-:. ";
const int W = 3;

void init()
{
    cout << endl
         << LINE << endl
         << endl
         << "Welcome! (Enter -1 anywhere to end)" << endl
         << endl
         << LINE << endl;
}

void end()
{
    cout << endl
         << LINE << endl
         << endl
         << "Thank you!" << endl
         << endl
         << LINE << endl;
}

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

int main()
{
    ifstream inFile;
    ofstream outFile;
    // ofstream asciiFile;
    string type, in_filepath, out_filepath;
    int width, height, max_value;

    /////////////////////////////////////////////////////
    int display_op;
    init();
    while (true)
    {
        cout << "Enter the filepath: (-1 to end):\n";
        cin >> in_filepath;
        inFile.open(in_filepath);
        while (inFile.fail() && in_filepath != "-1")
        {
            cout << "Input file opening failed.\n";
            cout << "Enter the filepath: ";
            cin >> in_filepath;
            inFile.open(in_filepath);
        }
        if (in_filepath == "-1")
        {
            break;
        }

        getline(inFile, type);
        inFile >> width >> height;
        inFile >> max_value;

        // initialize dynamic array/////////////////////////////////
        int **img = new int *[height];
        for (int i = 0; i < height; i++)
        {
            img[i] = new int[width];
        }

        // read original->img/////////////////////////////////
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                inFile >> img[y][x];
            }
        }

        // display new/////////////////////////////////////////////
        // asciiFile.open(ACSIIOUT);
        cout << "How do you want to display your img? (-1 to end)" << endl;
        cout << "(1)low quality (2)mid quality (3) high quality" << endl;
        cin >> display_op;
        while (display_op != -1 && (display_op < 1 || display_op > 3))
        {
            cout << "How do you want to display your img? (-1 to end)" << endl;
            cout << "(1)low quality (2)mid quality (3) high quality" << endl;
            cin >> display_op;
        }
        if (display_op == -1)
        {
            break;
        }

        if (display_op == 1)
        {
            display(img, height, width);
        }
        else if (display_op == 2)
        {
            displayMQ(img, height, width);
        }
        else if (display_op == 3)
        {
            displayHQ(img, height, width);
        }

        for (int i = 0; i < height; i++)
        {
            delete[] img[i];
        }
        delete[] img;
        img = NULL;

        // asciiFile.close();
        inFile.close();
    }

    end();

    /////////////////////////////////////////
    return 0;
}