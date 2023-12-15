/*Tommy wants to play number guessing.
Define the answer a ( 1 <= a <= 99 ) by yourself in your program.
The lower limit low and upper limit up are initialize to 0 and 100.
(ex. int a = 55; int low = 0; int up = 100; ) 
Guide Tommy until he guess it right, 
then turn off the program.*/


# include <iostream>
using namespace std;

int main(){
    int ans = 55;
    int low = 0, up = 100;
    int guess;
    do{
        cout << "Please enter the number you guess (range " << low << "~" << up << "):";
        cin >> guess;
        if (guess < low || guess > up){
        	cout << guess << " is not in the range!!" << endl; 
		}
        else if (guess == 0){
            cout << "Answer is " << ans << endl;
        }
        else if (guess < ans){
            cout << "Guess up" << endl;
            low = guess;
        }
        else if (guess > ans){
            cout << "Guess down" << endl;
            up = guess;
        }
    }while(guess != ans);
    cout << "Congratulation!";
    return 0;
}
