#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int fibo(int,int,int);
void main()
{
    int n;
    system("cls");
    printf("Enter limit :");
    scanf("%d",&n);
    printf("\nSum : %d",fibo(0,1,n));
    getch();

}

int fibo(int x, int y, int z)
{
    static int s=0;
    printf("%d\t", x);
    z--;
    s+=x;
    if (z<1)
        return (s);
    else
        fibo(y,x+y,z);
}

