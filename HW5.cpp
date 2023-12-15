/*Write a program that allow the user to input the weight, intensity of a
physical activity, minutes spent performing the physical activity and the
number of calories in one serving of your favorite food. And output how
many servings of that food should be eaten per day to maintain the person’s
current weight at the specified activity level.

Function 1: Computes the calories required for the basal metabolic rate
Input: weight
Output: calories required = 70 * (weight / 2.2) ^ 0.756

Function 2: Computes the calories required for physical activity
Input: weight、intensity、minutes
Output: calories required = 0.0385 * intensity * weight * minutes

The total consumption of calories is
1. meet basal metabolic rate (Function 1)
2. account for physical activity such as exercise (Function 2)
3. energy required to digest the food (Total Calories Consumed * 0.1)
In the end, you should output how many servings of that food should be
eaten per day*/

#include <iostream>
#include <cmath>
using namespace std;

float basalMetabolic(float weight);
float physicalActivity(float weight, float intensity, float minutes);

int main()
{
    float weight, intensity, minutes, calories_for_food;
    float ans, totalConsumed;
    cout << "Please enter the (weight,intensity,minutes,calories_for_food): ";
    cin >> weight >> intensity >> minutes >> calories_for_food;
    while (weight != 0 || intensity != 0 || minutes != 0 || calories_for_food != 0)
    {   
        totalConsumed = basalMetabolic(weight) + physicalActivity(weight, intensity, minutes);
        ans = totalConsumed * 10 / 9 / calories_for_food;
        cout << "You need to eat " << ans << " servings of your favorite food per day!\n";
        cout << "Please enter the (weight,intensity,minutes,calories_for_food): ";
        cin >> weight >> intensity >> minutes >> calories_for_food;
    }

    return 0;
}

float basalMetabolic(float weight)
{
    return (70 * pow((weight / 2.2), 0.756));
}

float physicalActivity(float weight, float intensity, float minutes)
{
    return (0.0385 * intensity * weight * minutes);
}