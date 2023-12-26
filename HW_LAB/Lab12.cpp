/*Here is grade system. We input student’s name, student’s ID, the course  student has taken, and the grade student got.
We need to save them into the system, and give instructions.
0 : for exit
Don’t forget to delete the array.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int id;
    string course;
    int grade;
};

void init();

void displayStudent(int stu_amount, Student *stu_arr);
void search(int stu_amount, Student *stu_arr, int id);

int main()
{
    int option, stu_amount = 0, id;
    Student *stu_arr = new Student[stu_amount];
    Student student;
    do
    {
        init();
        cin >> option;
        if (option == 1)
        {
            //addStudent(stu_amount, stu_arr);
            cout << "Enter student's name\n";
            cin >> student.name;
            cout << "Enter student's id\n";
            cin >> student.id;
            cout << "Enter student's course\n";
            cin >> student.course;
            cout << "Enter student's grade\n";
            cin >> student.grade;

            stu_amount++;
            Student *new_stu_arr = new Student[stu_amount];
            for (int i = 0; i < stu_amount - 1; i++)
            {
                new_stu_arr[i] = stu_arr[i];
            }
            new_stu_arr[stu_amount - 1] = student;
            delete[] stu_arr;
            stu_arr = new_stu_arr;
            new_stu_arr = NULL;
        }
        else if (option == 2)
        {
            displayStudent(stu_amount, stu_arr);
        }
        else if (option == 3)
        {
            cout << "Enter student's id\n";
            cin >> id;
            search(stu_amount, stu_arr, id);
        }
        else
        {
            break;
        }
        //cout << stu_arr[stu_amount - 1].name << endl;
    } while (option != 0);

    return 0;
}

void init()
{
    cout << endl;
    cout << "Enter your option\n";
    cout << "1: Add a new student\n";
    cout << "2: Display all students\n";
    cout << "3: Search student\n";
    cout << "0: Exit\n";
}

void displayStudent(int stu_amount, Student *stu_arr)
{
    cout << "All Students:\n";
    for (int i = 0; i < stu_amount; i++)
    {
        cout << "Name: " << stu_arr[i].name;
        cout << ", ID: " << (stu_arr + i)->id;
        cout << ", Course: " << (stu_arr + i)->course;
        cout << ", Grade: " << (stu_arr + i)->grade << endl;
    }
}

void search(int stu_amount, Student *stu_arr, int id)
{
    bool find = false;
    cout << "Search Results:" << endl;
    for (int i = 0; i < stu_amount; i++)
    {
        if ((stu_arr[i].id) == id)
        {
            find = true;
            cout << "Name: " << stu_arr[i].name;
            cout << ", ID: " << (stu_arr + i)->id;
            cout << ", Course: " << (stu_arr + i)->course;
            cout << ", Grade: " << (stu_arr + i)->grade << endl;
        }
    }
    if (!find)
    {
        cout << "Student with ID " << id << " not found." << endl;
    }
}