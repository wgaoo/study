/*************************************************************************
	> Filename: DisjSets.h
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-29 11:00
	> Last modified: 2014-07-29 11:03
    > Description: 不相交集合接口
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class DisjSets
{
public:
    explict DisjSets(int numElements);

    int find(int x) const;
    int find(int x);
    void unionSets(int root1,int root2);

private:
    vector<int> s;
    vector<int*> pColl;// 加入额外数据以实现1.路径压缩2.按秩合并
};
