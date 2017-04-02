/*************************************************************************
	> Filename: HashTable.h
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-29 11:16
	> Last modified: 2014-07-29 11:20
	> Description: hash所需要的接口函数
 ************************************************************************/

#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

template<typename HashedObj>
class HashTable
{
public:
    explict HashTable(int size=101);

    bool contains(const HashedObj &x)const;

    void makeEmpty();
    void insert(const HashedObj &x);
    void remove(const HashedObj &x);

private:
    vector<list<HashedObj>> theLists;
    int currentSize;

    void rehash();
    int myhash(const HashedObj &x) const;
}

int hash(const string &key);
int hash(int key);
