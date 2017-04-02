/*************************************************************************
	> Filename: main.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-24 21:57
	> Last modified: 2014-07-24 22:01
	> Description: 
 ************************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    for(int i=0;i<1000;i++)
    {
        cout<<random()%10<<" ";
    }
}
