/*************************************************************************
	> Filename: hamming_weight.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-26 10:34
	> Last modified: 2014-07-26 10:35
    > Description: 对应pdf中的1.4.10,计算某数字二进制表示中１的个数
 ************************************************************************/

#include<iostream>
using namespace std;

int num_of_1(int n)
{
    int count = 0;
    while(n!=0)
    {
        if(n%2==1)
        {
            count++;
        }
        n/=2;
    }
    return count;
}

int main()
{
    int num;
    cout<<"Input a uint number:"<<endl;
    cin>>num;
    cout<<"Num of 1 in binary num:"<<num_of_1(num)<<endl;
    return 0;
}
