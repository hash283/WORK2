#include<iostream>
#include<vector>
#include<chrono>
#include<string>
#include<fstream>
#include<sstream>
#define NODES 320000
using namespace std;
int t[NODES];
int z=1,v=0;
void dfs(vector<int> ar[],int i,bool ex[]);
void dfsf(vector<int> ar[],int i,bool ex[]);
int main()
{
    auto start = chrono::steady_clock::now();
    int m=NODES-1;
    vector<int> g[NODES],rg[NODES];
    bool ex[NODES];
    for(int i=0;i<NODES;i++)
        ex[i]=0;
    ifstream file;
    file.open("SCC.txt");
    string line;
    while(getline(file,line))
    {
        stringstream ss(line);
        int c,x;
        ss>>c;
        while(ss>>x)
        {
            g[c].push_back(x);
            rg[x].push_back(c);
        }
    }
    for(int i=NODES-1;i>=0;i--)
    {
        if(ex[i]==0)
            dfs(rg,i,ex);
    }
    for(int i=0;i<NODES;i++)
        ex[i]=0;
    while(m>0)
    {
        int c=t[m];
        if(ex[c]==0)
        {
            dfsf(g,c,ex);
            cout<<v<<endl;
            v=0;
        }
        m--;
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<chrono::duration <double, milli> (diff).count()<<" ms"<<endl;
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
    t[z]=i;
    z++;
}
void dfsf(vector<int> ar[],int i,bool ex[])
{
    ex[i]=1;
    for(decltype(ar[i].size()) j=0;j<ar[i].size();j++)
    {
        int m=ar[i][j];
        if(ex[m]==0)
            dfsf(ar,m,ex);
    }
    v++;
}