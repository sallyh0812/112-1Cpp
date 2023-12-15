/*lab 1: simple input output*/

# include <iostream>
# include <string>
using namespace std;

int main(){
	string name;
    int year, month, date;
	cout << "Please enter your name and birthday : " ;
	cin >> name >> year >> month >> date ;
    cout << "Hello! I'm " << name << "." << endl;
    cout << "My birthday is " << month << " /" << date << " /" << year  ;
    return 0;
}

