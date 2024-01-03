#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

#define FILEIN "pika.ppm"
#define FILEOUT "pika_out.ppm"
#define ACSIIOUT "test_ascii.txt"
const string LINE = "========================================================================================================================================================";
const string ASCII_H = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`\'. ";
const string ASCII_M = "@%#*+=-:. ";

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

void boxfilterTrans(int **img, int **new_img, int height, int width, int filter_size, ofstream &out)
{
    float **box_filter = new float *[filter_size];
    for (int i = 0; i < filter_size; i++)
    {
        box_filter[i] = new float[filter_size];
    }
    for (int i = 0; i < filter_size; i++)
    {
        for (int j = 0; j < filter_size; j++)
        {
            box_filter[i][j] = 1.0 / (filter_size * filter_size);
        }
    }

    float new_value = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            new_value = 0;
            for (int i = 0; i < filter_size; i++)
            {
                for (int j = 0; j < filter_size; j++)
                {
                    new_value += img[y + i][x + j] * box_filter[i][j];
                }
            }
            new_img[y][x] = int(new_value);
            out << new_img[y][x] << " ";
        }
        out << endl;
    }

    for (int i = 0; i < filter_size; i++)
    {
        delete[] box_filter[i];
    }
    delete[] box_filter;
    box_filter = NULL;
}

void constfilterTrans(int **img, int **new_img, int height, int width, int filter_size, ofstream &out)
{
    int **const_filter = new int *[filter_size];
    for (int i = 0; i < filter_size; i++)
    {
        const_filter[i] = new int[filter_size];
    }
    for (int i = 0; i < filter_size; i++)
    {
        for (int j = 0; j < filter_size; j++)
        {
            const_filter[i][j] = 0;
        }
    }
    const_filter[filter_size / 2][filter_size / 2] = 1;

    int new_value = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            new_value = 0;
            for (int i = 0; i < filter_size; i++)
            {
                for (int j = 0; j < filter_size; j++)
                {
                    new_value += img[y + i][x + j] * const_filter[i][j];
                }
            }
            new_img[y][x] = new_value;
            out << new_img[y][x] << " ";
        }
        out << endl;
    }

    for (int i = 0; i < filter_size; i++)
    {
        delete[] const_filter[i];
    }
    delete[] const_filter;
    const_filter = NULL;
}

void midValueTrans(int **img, int **new_img, int height, int width, int filter_size, ofstream &out)
{
    int *temp = new int[filter_size * filter_size];

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int i = 0; i < filter_size; i++)
            {
                for (int j = 0; j < filter_size; j++)
                {
                    temp[i * filter_size + j] = img[y + i][x + j];
                }
            }
            sort(temp, temp + (filter_size * filter_size));
            new_img[y][x] = temp[filter_size * filter_size / 2];
            out << new_img[y][x] << " ";
        }
        out << endl;
    }
    delete[] temp;
    temp = NULL;
}

void grayStretch(int **img, int **new_img, int height, int width, int fa, int fb, int ga, int gb)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {

            if (img[y][x] < fa)
            {
                new_img[y][x] = ga / fa * img[y][x];
            }
            else if (img[y][x] < fb) // fa<=img[y][x]<fb
            {
                new_img[y][x] = ga + (gb - ga) / (fb - fa) * img[y][x];
            }
            else // img[y][x] > fb
            {
                new_img[y][x] = gb + (255 - gb) / (255 - fb) * img[y][x];
            }
        }
    }
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
                cout << setw(1) << '@';
                // asciiFile <<setw(1) << '@';
            }
            else
            {
                cout << setw(1) << '-';
                // asciiFile << setw(1) <<'-';
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
            cout << setw(1) << ASCII_M[img[y][x] / unit % ASCII_M.length()];
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
            cout << setw(1) << ASCII_H[img[y][x] / unit % ASCII_H.length()];
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
    int filter_size, option, fill_0, display_op;
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

        out_filepath = in_filepath.substr(0, in_filepath.length() - 4);
        getline(inFile, type);
        inFile >> width >> height;
        inFile >> max_value;

        cout << "What do you want? (-1 to end)" << endl;
        cout << "(1)box filter (2)const filter (3)mid value tranform (4)gray stretch" << endl;
        cin >> option;
        while (option != -1 && (option < 1 || option > 4))
        {
            cout << "Not valid option." << endl;
            cout << "What do you want?" << endl;
            cout << "(1)box filter (2)const filter (3) mid value tranform" << endl;
            cin >> option;
        }
        if (option == -1)
        {
            break;
        }

        int **new_img = new int *[height];
        for (int i = 0; i < height; i++)
        {
            new_img[i] = new int[width]();
        }

        if (option >= 1 && option <= 3)
        {
            cout << "Enter your filter size (-1 to end):  ";
            cin >> filter_size;
            while (filter_size == 0 || filter_size % 2 == 0)
            {
                cout << "Filter size must be an odd number and must not be 0." << endl;
                cout << "Enter your filter size: ";
                cin >> filter_size;
            }
            if (filter_size == -1)
            {
                break;
            }

            fill_0 = filter_size - 1;

            // initialize dynamic array/////////////////////////////////
            int **img = new int *[height + fill_0];
            for (int i = 0; i < height + fill_0; i++)
            {
                img[i] = new int[width + fill_0]();
            }

            // read original->img with zero padding/////////////////////////////////
            for (int y = 0; y < height + fill_0; y++)
            {
                for (int x = 0; x < width + fill_0; x++)
                {
                    if (y < fill_0 / 2 || x < fill_0 / 2 || y >= fill_0 / 2 + height || x >= fill_0 / 2 + width)
                    {
                        img[y][x] = 0;
                    }
                    else
                    {
                        inFile >> img[y][x];
                    }
                    // cout << img[y][x] << " ";
                }
                // cout << endl;
            }
            // display(img, height+fill_0, width+fill_0);

            // transform->new_img by filter////////////////////////////////
            if (option == 1)
            {
                out_filepath += "_box_" + to_string(filter_size) + ".ppm";
                outFile.open(out_filepath);
                outFile << type << endl;
                outFile << width << " " << height << endl;
                outFile << max_value << endl;
                boxfilterTrans(img, new_img, height, width, filter_size, outFile);
            }
            else if (option == 2)
            {
                out_filepath += "_const_" + to_string(filter_size) + ".ppm";
                outFile.open(out_filepath);
                outFile << type << endl;
                outFile << width << " " << height << endl;
                outFile << max_value << endl;
                constfilterTrans(img, new_img, height, width, filter_size, outFile);
            }
            else if (option == 3)
            {
                out_filepath += "_mid_" + to_string(filter_size) + ".ppm";
                outFile.open(out_filepath);
                outFile << type << endl;
                outFile << width << " " << height << endl;
                outFile << max_value << endl;
                midValueTrans(img, new_img, height, width, filter_size, outFile);
            }

            // delete dynamic array/////////////////////////////////////////////

            for (int i = 0; i < height + fill_0; i++)
            {
                delete[] img[i];
            }
            delete[] img;
            img = NULL;
        }
        else if (option == 4)
        {
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

            int fa, fb, ga, gb;
            cout << "Enter your fa fb ga gb in order (0-255, spererate with space):\n";
            cin >> fa >> fb >> ga >> gb;
            while (fa < 0 || fa > 255 || fb <= fa || fb > 255 || ga < 0 || ga > 255 || gb <= ga || gb > 255)
            {
                cout << "Value should in the range of 0-255 and fb > fa, gb > ga" << endl;
                cout << "Enter your fa fb ga gb in order (0-255, spererate with space):\n";
                cin >> fa >> fb >> ga >> gb;
            }
            if (fa == -1 && fb == -1 && ga == -1 && gb == -1)
            {
                break;
            }

            // transform->new_img by gray stretch////////////////////////////////
            grayStretch(img, new_img, height, width, fa, fb, ga, gb);
        }

        // display new/////////////////////////////////////////////
        // asciiFile.open(ACSIIOUT);
        // display(img, height+fill_0, width+fill_0);
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
            display(new_img, height, width);
        }
        else if (display_op == 2)
        {
            displayMQ(new_img, height, width);
        }
        else if (display_op == 3)
        {
            displayHQ(new_img, height, width);
        }

        for (int i = 0; i < height; i++)
        {
            delete[] new_img[i];
        }
        delete[] new_img;
        new_img = NULL;

        // asciiFile.close();
        inFile.close();
        outFile.close();
    }

    end();

    /////////////////////////////////////////
    return 0;
}