#ifndef _string_H_
#define _string_H_
#include <string>
#endif

#ifndef _fstream_H_
#define _fstream_H_
#include <fstream>
#endif

#ifndef _iostream_H_
#define _iostream_H_
#include <iostream>
#endif

#ifndef _ppm_to_ascii_CPP_
#define _ppm_to_ascii_CPP_
#include "ppm_to_ascii.cpp"
#endif

#ifndef _img_filters_CPP_
#define _img_filters_CPP_
#include "img_filters.cpp"
#endif

using namespace std;

const string LINE = "=============================================================================================================";

void init()
{
    cout << endl
         << LINE << endl
         << endl
         << "Welcome to image filter! (Enter -1 anywhere to end)" << endl
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

int main()
{
    ifstream inFile;
    ofstream outFile;
    string type, in_filepath, out_filepath;
    int width, height, max_value;

    /////////////////////////////////////////////////////
    int filter_size, option, fill_0, display_op;
    init();
    while (true)
    {
        cout << endl
             << "Enter the filepath (-1 to end):\n";
        cin >> in_filepath;
        inFile.open(in_filepath);
        if (in_filepath == "-1")
        {
            break;
        }

        while (inFile.fail())
        {
            cout << "Input file opening failed.\n";
            cout << endl
                 << "Enter the filepath (-1 to end):\n";
            cin >> in_filepath;
            inFile.open(in_filepath);
        }

        out_filepath = in_filepath.substr(0, in_filepath.length() - 4);
        getline(inFile, type);
        inFile >> width >> height;
        inFile >> max_value;

        cout << endl
             << "What do you want? (-1 to end)" << endl;
        cout << "(1)box filter (2)const filter (3)median filter" << endl
             << "(4)alpha-trimmed mean filter (5)gray stretch (6)histogram equalization" << endl;
        cin >> option;
        if (option == -1)
        {
            break;
        }
                
        while ((option < 1 || option > 6))
        {
            cout << "Not valid option." << endl;
            cout << endl
                 << "What do you want?" << endl;
            cout << "(1)box filter (2)const filter (3)median filter" << endl
                 << "(4)alpha-trimmed mean filter (5)gray stretch (6)histogram equalization" << endl;
            cin >> option;
        }

        int **new_img = new int *[height];
        for (int i = 0; i < height; i++)
        {
            new_img[i] = new int[width]();
        }

        if (option >= 1 && option <= 4)
        {
            cout << endl
                 << "Enter your filter size (-1 to end):  ";
            cin >> filter_size;
            if (filter_size == -1)
            {
                break;
            }
            while (filter_size == 0 || filter_size % 2 == 0)
            {
                cout << "Filter size must be an odd number and must not be 0." << endl;
                cout << endl
                     << "Enter your filter size: ";
                cin >> filter_size;
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
                }
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
            else if (option == 4) // alpha-trimmed
            {
                int alpha;
                cout << endl
                     << "Enter your alpha parameter (-1 to end): ";
                cin >> alpha;
                while (alpha % 2 == 1 || alpha >= filter_size * filter_size)
                {
                    cout << "Alpha should be even and smaller than square of filter size." << endl;
                    cout << endl
                         << "Enter your alpha parameter (-1 to end): ";
                    cin >> alpha;
                }
                if (alpha == -1)
                {
                    break;
                }

                out_filepath += "_atm" + to_string(alpha) + "_" + to_string(filter_size) + ".ppm";
                outFile.open(out_filepath);
                outFile << type << endl;
                outFile << width << " " << height << endl;
                outFile << max_value << endl;
                alphaTrimmedMean(img, new_img, height, width, filter_size, alpha, outFile);
            }

            // delete dynamic array/////////////////////////////////////////////
            for (int i = 0; i < height + fill_0; i++)
            {
                delete[] img[i];
            }
            delete[] img;
            img = NULL;
        }
        else if (option == 5) // gray stretch
        {
            out_filepath += "_graystretch.ppm";
            outFile.open(out_filepath);
            outFile << type << endl;
            outFile << width << " " << height << endl;
            outFile << max_value << endl;

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
            cout << endl
                 << "Enter your fa fb ga gb in order (0~255, spererate with space)(all -1 to end):\n";
            cin >> fa >> fb >> ga >> gb;
            if (fa == -1 && fb == -1 && ga == -1 && gb == -1)
            {
                break;
            }
            while (fa < 0 || fa > 255 || fb <= fa || fb > 255 || ga < 0 || ga > 255 || gb <= ga || gb > 255)
            {
                cout << "Value should in the range of 0~255 and fb > fa, gb > ga" << endl;
                cout << endl
                     << "Enter your fa fb ga gb in order (0-255, spererate with space):\n";
                cin >> fa >> fb >> ga >> gb;
            }

            // transform->new_img by gray stretch////////////////////////////////
            grayStretch(img, new_img, height, width, fa, fb, ga, gb, outFile);

            ///////////////////////////////////////////////////////////
            for (int i = 0; i < height; i++)
            {
                delete[] img[i];
            }
            delete[] img;
            img = NULL;
        }
        else if (option == 6) // histogram equalization
        {
            out_filepath += "_he.ppm";
            outFile.open(out_filepath);
            outFile << type << endl;
            outFile << width << " " << height << endl;
            outFile << max_value << endl;

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

            // transform->new_img by gray stretch////////////////////////////////
            histogramEqualization(img, new_img, height, width, outFile);
            ///////////////////////////////////////////////////////////
            for (int i = 0; i < height; i++)
            {
                delete[] img[i];
            }
            delete[] img;
            img = NULL;
        }

        // hint message
        cout << endl
             << "Transfromed successful!" << endl
             << "Your new ppm filepath is \'" << out_filepath << "\'" << endl;

        // display new/////////////////////////////////////////////
        cout << endl
             << "Do you want to display your img? (-1 to end)" << endl;
        cout << "(0)don't display (1)low quality (2)mid quality (3) high quality" << endl;
        cin >> display_op;
        while (display_op != -1 && (display_op < 0 || display_op > 3))
        {
            cout << "Not valid option." << endl;
            cout << endl
                 << "Do you want to display your img? (-1 to end)" << endl;
            cout << "(0)don't display (1)low quality (2)mid quality (3) high quality" << endl;
            cin >> display_op;
        }
        if (display_op == -1)
        {
            break;
        }
        else if (display_op == 1)
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

        cout << endl
             << LINE << endl
             << endl;
    }

    end();

    /////////////////////////////////////////
    return 0;
}