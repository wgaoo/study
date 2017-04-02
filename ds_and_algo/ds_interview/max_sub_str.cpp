/*************************************************************************
> Filename: 1-2-4.cpp
> Author: gaow
> Mail: w_gao@foxmail.com
> Create Time: 2014-07-23 16:32
> Last modified: 2014-07-23 17:11
> Description: 求子数组的最大和
************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
    string s;
    getline(cin,s);

    stringstream strm(s);
    int value;
    vector<int> coll;

    while(strm>>value)
    {
        coll.push_back(value);
    }
    
    // 检查输入的正确性
    for(int j=0;j<coll.size();j++)
    {
        cout<<coll[j]<<" ";
    }
    cout<<endl;

    int idxBegin=0,idxEnd=0,iCurrent=0,idxMaxBegin=0,idxMaxEnd=0,iMax=0;
    for(idxEnd=1;idxEnd<=coll.size();idxEnd++)
    {
        // 采用左闭右开区间的表示法
        if(iCurrent<0)
        {
            idxBegin = idxEnd-1;
            iCurrent = coll[idxEnd-1];
        }
        else
        {
            iCurrent += coll[idxEnd-1];
        }

        if(iCurrent>iMax)
        {
            idxMaxBegin = idxBegin;
            idxMaxEnd = idxEnd;
            iMax = iCurrent;
        }
    }

    // output
    cout<<"最大的子序列为：";
    for(int i=idxMaxBegin;i<idxMaxEnd;i++)
    {
        cout<<coll[i]<<" ";
    }
    cout<<endl;
    cout<<"最大子序列和为:"<<iMax<<endl;
    return 0;
}


