#include<iostream>

using namespace std;

class Complex;

class Calculator
{
public:
    static int sumReal(Complex, Complex);
    static int sumImaginary (Complex, Complex);
};

class Complex
{
    int a, b;

    friend int Calculator :: sumReal (Complex, Complex);
    friend int Calculator :: sumImaginary (Complex, Complex);

   //friend class Calculator;

public:

    void out();
    void setData(int x, int y)
    {
        a = x;
        b = y;
    }

};

void Complex :: out(void)
    {
       cout << "Your number : " << a << " + " << b << "i" << endl;
    }

int Calculator :: sumReal (Complex c, Complex d)
{
    return (c.a+d.a);
}

int Calculator :: sumImaginary (Complex c, Complex d)
{
    return (c.b+d.b);
}

int main()
{
    Complex f, g, h;


    f.setData(5,6);
    g.setData(6,8);
    //h.setData(Calculator::sumReal(f, g),Calculator::sumImaginary(f, g));
    cout << Calculator::sumReal(f,g) << endl << Calculator::sumImaginary(f,g);
    f.out();
   // g.out();
    //h.out();

    return 1;
}
