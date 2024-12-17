#include<iostream>

using namespace std;

void fib (int z, long long x = 0, long long y = 1)
{
    if (!(z < 1))
    {
        cout << x << endl;
        fib(z-1,y,x+y);
    }
}

int fibTerm (int x)
{
    if (x==1)
        return 0;

    if (x==2)
        return 1;

    return fibTerm(x-2) + fibTerm(x-1);
}

int fac (int x= 1)
{
    if(x <= 1)
    {
        return 1;
    }

        return (fac(x-1)*x);
}

int main ()
{


    /*int a;

    cout << "Enter your number : ";
    cin >> a;

    cout << "Factorial of the given number : " << fac(a);




    int n;

    cout << "Enter the number of terms : ";
    cin >> n;

    fib(n);*/

    int t;

    cout << "Enter which term : ";
    cin >> t;

    cout << "The " << t << "th Fibonacci term : " ;//<< fibTerm(t);

    int x=0, y=1, tem;
    for (int i = 1; i<t;i++)
    {
        tem = y;
        y += x;
        x = tem;
    }

    cout << x;

    return 0;


}
