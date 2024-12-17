//Program to Find distance between two points
#include<iostream>
#include<cmath>
using namespace std;

class Point
{
    int x, y;
    friend void distance (Point, Point);

public:
    Point (int a, int b)
    {
        x = a;
        y = b;
    }

};

void distance (Point a, Point b)
{
    int dis = sqrt(pow(a.x-b.x,2)+ pow(a.y-b.y,2));

    cout << "Distance between (" << a.x <<", " << a.y << ") and (" <<b.x <<", " << b.y << ") : " << dis << " units "<<endl;
}

int main()
{
    int p, q;

    cout << "Enter 1st point's co-ordinate : " << endl << "x : ";
    cin  >> p;
    cout << "y : ";
    cin  >> q;
    Point prt1(p,q);

    cout << "Enter 2nd point's co-ordinate : " << endl << "x : ";
    cin  >> p;
    cout << "y : ";
    cin  >> q;
    Point prt2(p,q);

    distance (prt1, prt2);

    return 0;
}
