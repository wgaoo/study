/*************************************************************************
	> Filename: heapsort.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-28 10:11
	> Last modified: 2014-07-28 10:36
	> Description: 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

inline int leftChild(int i)
{
    return 2*i+1;
}

template <typename Comparable>
void percDown(vector<Comparable>&a,int i,int n)
// Input: n是堆的元素个数
{
    int child;
    Comparable tmp;

    for(tmp=a[i];leftChild(i)<n;i=child)
    {
        child = leftChild(i);
        if(child != n-1 && a[child] < a[child+1])
        {
            child++;
        }
        if(tmp<a[child])
        {
            a[i]=a[child];
        }
        else
        {
            break;
        }
    }
    a[i] = tmp;
}

template<typename Comparable>
void heapsort(vector<Comparable>& a)
{
    // 建立堆
    for(int i=a.size()/2;i>=0;i--)
    {
        percDown(a,i,a.size());
    }
    // 循环删除最大值
    cout<<"After sorted:";
    for(int j=a.size()-1;j>=0;j--)
    {
        cout<<a[0]<<" ";
        swap(a[0],a[j]);
        percDown(a,0,j);
    }
    cout<<endl;
}

int main()
{
    vector<int> coll;
    int size;
    cout<<"Input size of array:"<<endl;
    cin>>size;
    int tmp;
    for(int i=0;i<size;i++)
    {
        cin>>tmp;
        coll.push_back(tmp);
    }
    heapsort(coll);
    return 0;
}
