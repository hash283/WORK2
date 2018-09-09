#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<sstream>
using namespace std;
int main()
{
    int source,noe=0;
    queue<int> tm;
    vector<int> ar[7];
    bool ex[7];
    int dist[7];
    for(int i=0;i<7;i++)
    {
        ex[i]=0;
        dist[i]=0;
    }
    string line;
    ifstream file;
    cout<<"Enter source vertex\n";
    cin>>source;
    file.open("bfstest.txt");
    while(getline(file,line))
    {
        int c,x;
        stringstream ss(line);
        ss>>c;
        while(ss>>x)
        {
            if(x>c)
                noe++;
            ar[c].push_back(x);
        }
    }
    tm.push(source);
    ex[source]=1;
    while(!tm.empty())
    {
        int st=tm.front();
        tm.pop();
        for(decltype(tm.size())i=0;i<ar[st].size();i++)
        {
            int t=ar[st][i];
            if(ex[t]==0)
            {
                ex[t]=1;
                dist[t]=dist[st]+1;
                tm.push(t);
            }
        }
    }
    for(int i=1;i<=6;i++)
    {
       cout<<"Minimum no of hops from "<<source<<" to "<<i<<" is "<<dist[i]<<endl;
    }
    cout<<"\nNo of edges are "<<noe<<endl;
}