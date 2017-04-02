/*************************************************************************
	> Filename: isEndOrder.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-24 19:35
	> Last modified: 2014-07-25 14:51
	> Description: ＜数据结构面试题＞1.2.8 判断数组是否是二叉查找树后续便利结果
 ************************************************************************/

#include<iostream>
using namespace std;

// [begin,end]区间
bool isPostOrder(int arr[],int begin,int end)
{
    if(begin>=end)
    {
        return true;
    }
    int k=begin;
    while(k<=end&&arr[k]<arr[end])
    {
        k++;
    }
    int tmp = k;
    while(tmp <= end)
    {
        tmp++;
        if(arr[tmp]<arr[end])
        {
            return false;
        }
    }
    return isPostOrder(arr,begin,k-1) && isPostOrder(arr,k+1,end);
}

int main()
{
    int size;
    int arr[100];
    cout<<"Input int Arr size:"<<endl;
    cin>>size;
    cout<<"Input "<<size<<" int numbers:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    if(isPostOrder(arr,0,size-1))
    {
        cout<<"is Post Order"<<endl;
    }
    else
    {
        cout<<"is not Post Order"<<endl;
    }
    return 0;
}
