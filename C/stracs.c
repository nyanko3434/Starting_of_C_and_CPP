#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct stu
{
    char name[50];
    int x;
}s[5],t;
void main()
{
int i,j;
for(i=0;i<5;i++)
{
printf("Enter data of %dth student:\n Name:",i+1);
scanf("%s",s[i].name);
printf("Roll no:");
scanf("%d",&s[i].x);
}
  system("cls");
for(i= 0;i<5;i++)
{for(j=i+1;j<5;j++)
{
if(s[j].x<s[i].x)
{
t=s[i];
s[i]=s[j];
s[j]=t;
}
}
}
for(i=0;i<5;i++)
{
printf("\nName: %s  Rollno.:%d\n",s[i].name,s[i].x);
}
}
