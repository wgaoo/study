/*************************************************************************
	> Filename: print_hex.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-28 16:16
	> Last modified: 2014-07-28 16:38
	> Description: ＜数据结构面试题＞1.12.3 把十进制数分别以二进制和十六进制输出
 ************************************************************************/

#include<iostream>
using namespace std;

// 以二进制形式输出
void PrintBin(unsigned long n)
{
    if(n/2>0)
    {
        PrintBin(n/2);
    }
    cout<<n%2;
}

void PrintHex(unsigned long n)
{
    if(n/16>0)
    {
        PrintHex(n/16);
    }
    if(n%16<10)
    {
        cout<<n%16;
    }
    else
    {
        char ch = n%16+'A'-10;
        cout<< ch;
    }
}

int main()
{
    unsigned long num;
    cout<<"input unsigned num:"<<endl;
    cin>>num;
    cout<<"in bin form:";
    PrintBin(num);
    cout<<endl;
    cout<<"in hex form:";
    PrintHex(num);
    cout<<endl;
    return 0;
}
