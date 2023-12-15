/*A customer bought items totaling n dollars and 
handed over a 500-dollar bill for payment. 
Please write a program to help you calculate and
return the change (least amount) to the customer.
(assuming there is enough change in all denominations)

static_cast<int>(f)*/ 

#include <iostream>
using namespace std;

int main(){
	int n, coin_100, coin_50, coin_10, coin_5, coin_1;
	cout << "Please enter the customer's purchase amount n: ";
	cin >> n;
	n = 500-n;
	coin_100 = n/100;
	n %= 100;
	coin_50 = n/50;
	n %= 50;
	coin_10 = n/10;
	n %= 10;
	coin_5 = n/5;
	n %= 5;
	coin_1 = n;
	cout << "coin_100:" << coin_100 << " ";
	cout << "coin_50:" << coin_50 << " ";
	cout << "coin_10:" << coin_10 << " ";
	cout << "coin_5:" << coin_5 << " ";
	cout << "coin_1:" << coin_1 << " ";
    return 0;
}
