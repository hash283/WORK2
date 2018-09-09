#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
#define NODES 10
int t[NODES],s[NODES];
int z=1;
void dfs(vector<int> ar[],int i,bool ex[]);
void dfsf(vector<int> ar[],int i,int n,bool ex[]);
int main()
{
    int m=NODES-1;
    vector<int> g[NODES],rg[NODES];
    bool ex[NODES];
    for(int i=0;i<NODES;i++)
        ex[i]=0;
    ifstream file;
    file.open("testscc.txt");
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
    for(int i=NODES-1;i>0;i--)
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
            dfsf(g,c,c,ex);
        m--;
    }
    for(int i=1;i<NODES;i++)
        cout<<i<<" has value "<<s[i]<<endl;
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
void dfsf(vector<int> ar[],int i,int n,bool ex[])
{
    ex[i]=1;
    for(decltype(ar[i].size()) j=0;j<ar[i].size();j++)
    {
        int m=ar[i][j];
        if(ex[m]==0)
            dfsf(ar,m,n,ex);
    }
    s[i]=n;
}