#ifndef _string_H_
#define _string_H_
#include <string>
#endif

#ifndef _fstream_H_
#define _fstream_H_
#include <fstream>
#endif

#ifndef _vector_H_
#define _vector_H_
#include <vector>
#endif

#ifndef _math_algorithm_H_
#define _math_algorithm_H_
#include <algorithm>
#include <cmath>
#endif

using namespace std;

void boxfilterTrans(int **img, int **new_img, int height, int width, int filter_size, ofstream &out)
{
    // Create the kernel for box filter with filter size
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

    // Loop through old img and put new value to new img
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

    // Delete the dynamic array
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
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            vector<int> temp;
            for (int i = 0; i < filter_size; i++)
            {
                for (int j = 0; j < filter_size; j++)
                {
                    temp.push_back(img[y + i][x + j]);
                }
            }
            sort(temp.begin(), temp.end());
            new_img[y][x] = temp[filter_size * filter_size / 2];
            out << new_img[y][x] << " ";
        }
        out << endl;
    }
}

void alphaTrimmedMean(int **img, int **new_img, int height, int width, int filter_size, int alpha, ofstream &out)
{
    int discard = alpha / 2, sum;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            vector<int> temp;
            for (int i = 0; i < filter_size; i++)
            {
                for (int j = 0; j < filter_size; j++)
                {
                    temp.push_back(img[y + i][x + j]);
                }
            }
            sort(temp.begin(), temp.end());
            sum = 0;
            for (int i = discard; i < filter_size * filter_size - discard; i++)
            {
                sum += temp[i];
            }
            // Assign the mean value to the output pixel
            new_img[y][x] = sum / (filter_size * filter_size - discard * 2);
            out << new_img[y][x] << " ";
        }
        out << endl;
    }
}

void grayStretch(int **img, int **new_img, int height, int width, int fa, int fb, int ga, int gb, ofstream &out)
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
            out << new_img[y][x] << " ";
        }
        out << endl;
    }
}

void histogramEqualization(int **img, int **new_img, int height, int width, ofstream &out)
{
    vector<int> darkness(256);
    vector<float> cdf(256);
    vector<int> newDarkness(256);
    int minValue = 255, maxValue = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (img[y][x] < minValue)
            {
                minValue = img[y][x];
            }
            if (img[y][x] > maxValue)
            {
                maxValue = img[y][x];
            }
            darkness[img[y][x]] += 1;
        }
    }

    cdf[0] = (darkness[0] / float(height * width));
    for (int i = 1; i < 256; i++)
    {
        cdf[i] = darkness[i] / float(height * width) + cdf[i - 1];
    }
    out << endl;
    for (int i = 0; i < 256; i++)
    {
        newDarkness[i] = int(round(255 * (cdf[i] - cdf[minValue]) / (cdf[maxValue] - cdf[minValue])));
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            new_img[y][x] = newDarkness[img[y][x]];
            out << new_img[y][x] << " ";
        }
        out << endl;
    }
}

