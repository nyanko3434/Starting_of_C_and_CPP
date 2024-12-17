#include<iostream>
#include<cstdlib>

using namespace std;

int glo = 5;
int a=5'45'5;
void su(){
glo = 55;
}

int main() {
     /*su();
     glo=45;

     cout << glo;*/

     /*int a;
     cout << "Enter the value of a : ";
     cin >> a;

     cout << "The local a = "  << a << endl
          << "The globle a = " << ::a;*/


     int x =5;
     int &y=x;
     cout << x <<"  "<< y<<endl;
     y++;
     cout << x <<"  "<< y;


     return 0;
}
