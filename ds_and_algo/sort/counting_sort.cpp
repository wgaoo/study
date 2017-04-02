/*************************************************************************
	> Filename: counting_sort.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-24 21:55
	> Last modified: 2014-07-24 21:55
	> Description: 对［0,9］的若干个数字排序
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void counting_sort(vector<int>& coll)
{
    vector<int> tmpcoll;
    int i;
    for(i=0;i<10;i++)
    {
        tmpcoll.push_back(0);
    }
    for(i=0;i<coll.size();i++)
    {
        tmpcoll[coll[i]]+=1;
    }
    for(i=1;i<tmpcoll.size();i++)
    {
        tmpcoll[i]+=tmpcoll[i-1];
    }
    int k=0;
    for(i=0;i<coll.size();i++)
    {
        if(i<tmpcoll[k])
        {
            coll[i]=k;
        }
        else
        {
            k++;
            coll[i]=k;
        }
    }
}

int main()
{
    vector<int> coll;
    int num;
    while(cin>>num)
    {
        coll.push_back(num);
    }
    counting_sort(coll);
    // print
    for(vector<int>::iterator iter=coll.begin();iter!=coll.end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
