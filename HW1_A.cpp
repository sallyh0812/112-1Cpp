/*Program that allows user to enter quarter, dime, nickel,
then output the monetary value in cent*/

#include <iostream>
using namespace std;

int main(){
    int quarter, dime, nickel, cent;
    cin >> quarter >> dime >> nickel;
    //quarter=25 dime=10 nickel=5 cents
    cent = quarter*25 + dime*10 + nickel*5;
    cout << cent << endl;
    return 0;
}
