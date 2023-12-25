/*Given a function :
int* concatenate(int* array_1, int* array_2, int size_1, int size_2);
Implement the function that concatenate the content of two dynamic integer 
arrays. The function inputs are two reference pointers to the arrays and the 
size of both arrays. The function will return a pointer to a new array which 
contains a copy of the elements of both arrays.
For example:
array_1 = {1, 3, 5}; size_1 = 3;
array_2 = {2, 4, 6, 8, 10}; size_2 = 5;
should return a pointer to array_3 that array_3 = {1, 3, 5, 2, 4, 6, 8, 10}.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int* concatenate(int* array_1, int* array_2, int size_1, int size_2);

int* concatenate(int* array_1, int* array_2, int size_1, int size_2){
    int* array_3 = new int[size_1+size_2];
    for(int i = 0; i< size_1;i++){
        *(array_3+i) = *(array_1+i);
    }
    for(int i = 0; i< size_2; i++){
        *(array_3+size_1+i) = *(array_2+i);
    }
    return array_3;
}