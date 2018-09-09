//algorithm to topologically sort nodes in a acyclic graph using dfs
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<fstream>
#define NODES 7
int t=NODES-1;
int fv[NODES];
using namespace std;
void dfs(vector<int> ar[],int i,bool ex[]);
int main()
{
    vector<int> ar[NODES];
    bool ex[NODES];
    for(int i=0;i<NODES;i++)
        ex[i]=0;
    string line;
    ifstream myfile;
    myfile.open("digraph.txt");
    while(getline(myfile,line))
    {
        int c,x;
        stringstream ss(line);
        ss>>c;
        while(ss>>x)
            ar[c].push_back(x);
    }
    for(int i=1;i<NODES;i++)
    {
        if(ex[i]==0)
            dfs(ar,i,ex);
    }
    for(int i=1;i<NODES;i++)
        cout<<"The fv of "<<i<<" is "<<fv[i]<<endl;
}
void dfs(vector<int> ar[],int i,bool ex[])
{
    ex[i]=1;
    for(decltype(ar[i].size()) j=0;j<ar[i].size();j++)
    {
        int n=ar[i][j];
        if(ex[n]==0)
            dfs(ar,n,ex);
    }
    fv[i]=t;
    t--;
}
