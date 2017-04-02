/*************************************************************************
	> Filename: my_minus.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-08-19 20:05
	> Last modified: 2014-08-19 20:49
	> Description: 
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

void my_reverse(char a[])
{
    int i=0;
    while(a[i]!=0)
    {
        i++;
    }
    i--;
    int j=0;
    while(j<i)
    {
        swap(a[j],a[i]);
        j++;
        i--;
    }
}

int main()
{
    char num1[100],num2[100];
    int i;
    for(i=0;i<100;i++)
    {
        num1[i]=0;
        num2[i]=0;
    }

    cin>>num1>>num2;
    my_reverse(num1);
    my_reverse(num2);
    
    cout<<"After Reversed:"<<num1<<" "<<num2<<endl;
    int tmp=0;
    i=0;
    while(num2[i]!=0 || tmp!=0)
    {
        if(num1[i]!=0 && num2[i]!=0)
        {
            if(num1[i]-num2[i]-tmp<0)
            {
                num1[i]=num1[i]-num2[i]+10-tmp+'0';
                tmp=1;
            }
            else
            {
                num1[i]=num1[i]-num2[i]-tmp+'0';
                tmp=0;
            }
        }
        if(num2[i]==0)
        {
            if(num1[i]-tmp<'0')
            {
                num1[i]=num1[i]-tmp+10;
                tmp=1;
            }
            else
            {
                num1[i]=num1[i]-tmp;
                tmp=0;
            }
        }
        i++;
    }

    my_reverse(num1);
    cout<<num1<<endl;
}
