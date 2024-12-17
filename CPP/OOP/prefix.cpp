// Program to find the common prefix from the given words

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str[10], strTest, strTem ="";
    //string *strPointer = &str;
    int n, m;

    cout << "Enter number of strings(1-10): ";
    cin >> n;

    cout << "Enter the strings: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> str[i];
    }

    strTest = str[0];

    for(int i=0; i<n; i++)
    {
        if (str[i].size()< strTest.size())
            m = str[i].size();
        else
            m = strTest.size();
        for (int j = 0; j<m;j++ )
        {
            if (str[i].substr(j,1) == strTest.substr(j,1))
                strTem.append(str[i].substr(j,1));
            else
                break;
        }

        strTest = strTem;
        strTem.clear();
    }

    cout << endl << "The common prefix : " << strTest;


    return 1;
}
