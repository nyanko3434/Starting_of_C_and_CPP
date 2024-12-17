#include<iostream>
using namespace std;

int main(){

    int mark[]={4,5,6,5};
    int* p = mark; // a gives the address of a[0]
    cout <<*(p++)<<endl//;cout
         <<*(++p);
    cout <<*p;

}
