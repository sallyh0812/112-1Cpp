/*Program that asks user the current hour, minute, second,
output the time in seconds since midnight
Ask them for value again if the input is invalid*/ 

#include <iostream>
#include <string>
using namespace std;

int main(){
	int hour, minute, second, secFromMidnight;
	
	do{
		cout << "Enter the hour of the day: "; 
		cin >> hour; //0-23
	}while(hour < 0 || hour > 23);
	
	do{
		cout << "Enter the minutes of the hour: "; 
		cin >> minute; //0-59
	}while(minute < 0 || minute > 59);

	do{
		cout << "Enter the seconds passed in the current minutes: "; 
		cin >> second; //0-59
	}while(second < 0 || second > 59);

	secFromMidnight = hour*60*60 + minute*60 + second;

	cout << "The time in seconds since midnight is: ";
	cout << secFromMidnight;

	return 0;
} 
