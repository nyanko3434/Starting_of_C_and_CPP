//Program to roll two dice

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
     srand(time(nullptr)); // Jan 1st 1970
     int dice1 = (rand() % 6) + 1; // (rand() % (Max_value - Min_value + 1) ) + Min_value

     srand(time(nullptr)+100);
     int dice2 = (rand() % 6) + 1;

     cout << dice1 << " , " << dice2;

     return 0;
}
