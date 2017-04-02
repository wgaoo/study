/*************************************************************************
	> Filename: bubble_sort.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-24 20:21
	> Last modified: 2014-07-24 20:21
	> Description: 
 ************************************************************************/

#include<iostream>
using namespace std;

void bubble_sort(int a[],int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i;j>0;j--)
        {
            if(a[j-1]>a[j])
            {
                swap(a[j-1],a[j]);
            }
        }
    }
}

int main()
{
    int size;
    int arr[100];
    cout<<"Input size:"<<endl;
    cin>>size;
    cout<<"Input Array:"<<endl;
    int i;
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr,size);
    cout<<"After sorted:"<<endl;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
