//Program to convert Temperature from degree Fahrenheit to degree celsius
#include<iostream>

using namespace std;

int main()
{
    cout << "Enter the Temperature in Degree Fahrenheit : ";
    double fahrenheit;
    cin >> fahrenheit;

    double celsius = (fahrenheit-32)/1.8;
    cout <<endl << "The given temperature in Degree Celsius : "<< celsius <<endl;

    return 0;
}
