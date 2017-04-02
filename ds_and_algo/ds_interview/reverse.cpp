/*************************************************************************
	> Filename: reverse.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-24 19:23
	> Last modified: 2014-07-24 19:23
    > Description: 对应＜数据结构面试题＞1.2.7 翻转句子中的单词顺序
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

void reverse(string& s)
{
    int i=0,j=s.size()-1;
    while(i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
}

int main()
{
    string s;
    getline(cin,s);
    cout<<s<<endl;
    return 0;    
}
