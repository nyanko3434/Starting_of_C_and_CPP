#include<iostream>
#include<string>
using namespace std;

/*class Employee
{
    private:
        int a, b, c;
    public:
        int d, e;
        void setData(int a1, int b1, int c1); // Declaration
        void getData(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};

void Employee :: setData(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    Employee harry;
    // harry.a = 134; -->This will throw error as a is private
    harry.d = 34;
    harry.e = 89;
    harry.setData(1,2,4);
    harry.getData();
    return 0;
}*/

class Student
{
    private:
        int marks, position;

    public:
        int rollNo , grade;
        string name;
        void getData(int ,int );
        void out()
        {
            cout << "The Info on " << name << " :" << endl
                 << "Roll no : " << rollNo << endl
                 << "Grade   : " << grade << endl
                 << "Marks   : " << marks << endl
                 << "Rank    : " << position << endl;
        }
};

void Student :: getData (int a, int b)
{
    marks = a;
    position = b;
}

int main()
{
    Student nay;

    nay.rollNo = 669;
    nay.grade = 13;
    nay.name = "Nayan";
    nay.getData(95,2);

    nay.out();

    return 0;
}
