/*************************************************************************
	> Filename: insert_sort.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-08-18 10:19
	> Last modified: 2014-08-18 10:19
	> Description: 
 ************************************************************************/

#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

int insert_sort(int iArr[],int iSize)
{
    int i,j,k,tmp;
    for(i=0;i<iSize;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(iArr[j]>iArr[i])
            {
                break;
            }
        }
        if(j<i)
        {
            tmp=iArr[i];
            for(k=i;k>j;k--)
            {
                iArr[k]=iArr[k-1];
            }
            iArr[j]=tmp;
        }
    }
}

int main()
{
    int iArr[]={1,4,2,7,6};
    int iSize =5;
    insert_sort(iArr,iSize);
    copy(iArr,iArr+5,ostream_iterator<int>(cout," "));
    cout<<endl;
    return 0;
}
