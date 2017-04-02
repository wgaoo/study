/*************************************************************************
	> Filename: test_getline.cpp
	> Author: gaow
	> Mail: w_gao@foxmail.com 
	> Create Time: 2014-07-23 17:32
	> Last modified: 2014-07-24 08:47
	> Description: 
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<unistd.h>
using namespace std;

vector<string>* split(string s);

int main()
{
    string s;
    getline(cin,s);
    vector<string>* pcoll = split(s);
    // print
    for(vector<string>::iterator iter = pcoll->begin();iter != pcoll->end(); iter++)
    {
        cout<<*iter<<"\t";
    }
    cout<<endl;
    delete pcoll;
    return 0;
}

vector<string>* split(string s)
{
    vector<string>* pcoll = new vector<string>();
    int idx;
    while(!s.empty())
    {
        string substr;
        string nextstr;
        int idx = s.find_first_of(",");
        if(idx!=string::npos)
        {
            substr = s.substr(0,idx);
            pcoll->push_back(substr);
            nextstr = s.substr(idx+1,s.size()-idx-1);
            s=nextstr;
        }
        else
        {
            substr = s;
            pcoll->push_back(substr);
            break;
        }
    }
    return pcoll;
}
