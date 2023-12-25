/*create a program to manage the inventory of a store. Each product in the inventory has a unique product ID, and a quantity in stock.

Steps:
1. Read in all 5 product IDs.
2. Read in all 5 stock quantities.
3. Given a command, perform the function described below
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#define SIZE 5

void displayProducts(const int *productIDs, const int *quantities);
void displayHighestQuantity(const int *productIDs, const int *quantities);
void updateQuantity(const int *productIDs, int *quantities, int productID, int newQuantity);
void sortByQuantity(int *productIDs, int *quantities);
void sortByID(int *productIDs, int *quantities);
void swap(int *a, int *b);

int main()
{
    ifstream inStream;
    inStream.open("Lab11_tue_demo.txt");
    int productIDs[SIZE], quantities[SIZE];
    int id, new_q;
    string command;

    for (int i = 0; i < SIZE; i++)
    {
        inStream >> productIDs[i];
    }
    for (int i = 0; i < SIZE; i++)
    {
        inStream >> quantities[i];
    }
    do
    {
        inStream >> command;
        if (command == "update")
        {
            inStream >> id >> new_q;
            updateQuantity(&productIDs[0], &quantities[0], id, new_q);
        }
        else if (command == "display")
        {
            displayProducts(&productIDs[0], &quantities[0]);
        }
        else if (command == "displayhq")
        {
            displayHighestQuantity(&productIDs[0], &quantities[0]);
        }
        else if (command == "sq")
        {
            sortByQuantity(&productIDs[0], &quantities[0]);
        }
        else if (command == "sid")
        {

            sortByID(&productIDs[0], &quantities[0]);
        }
        else{
            cout << "Error: command not found!" << endl;
        }
        cout << "----------------------------------------------"<<endl;
    }while(!inStream.eof());
    return 0;
}
void displayProducts(const int *productIDs, const int *quantities)
{
    cout << "Current command: display" << endl;
    cout << "ProductIDs: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(4) << *(productIDs + i);
    }
    cout << endl;
    cout << "Quantities: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(4) << *(quantities + i);
    }
    cout << endl;
}
void displayHighestQuantity(const int *productIDs, const int *quantities)
{
    cout << "Current command: displayhq" << endl;
    int max_q = *quantities, max_i;
    for (int i = 0; i < SIZE; i++)
    {
        if (*(quantities + i) > max_q)
        {
            max_i = *(productIDs + i);
            max_q = *(quantities + i);
        }
    }
    cout << "Max productID: " << setw(4) << max_i << endl;
    cout << "Max Quantity:  " << setw(4) << max_q;
    cout << endl;
}
void updateQuantity(const int *productIDs, int *quantities, int productID, int newQuantity)
{
    bool find = false;
    cout << "Current command: update" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (*(productIDs + i) == productID)
        {
            cout << "productID " << productID << ": " << setw(4) << *(quantities + i) << " -> " << newQuantity << endl;
            *(quantities + i) = newQuantity;
            find = true;
            break;
        }
    }
    if (!find)
    {
        cout << "Error: product ID " << productID << " not found!" << endl;
    }
}
void sortByQuantity(int *productIDs, int *quantities)
{
    cout << "Current command: sq" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i; j < SIZE; j++)
        {
            if (*(quantities + i) > *(quantities + j))
            {
                swap(quantities + i, quantities + j);
                swap(productIDs + i, productIDs + j);
            }
        }
    }
}
void sortByID(int *productIDs, int *quantities)
{
    cout << "Current command: sid" << endl;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i; j < SIZE; j++)
        {
            if (*(productIDs + i) > *(productIDs + j))
            {
                swap(quantities + i, quantities + j);
                swap(productIDs + i, productIDs + j);
            }
        }
    }
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}