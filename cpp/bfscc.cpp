#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<fstream>
#include<sstream>
#define NODES 11
using namespace std;
int main()
{
    vector<int> ar[NODES];
    queue<int> tm;
    bool ex[NODES];
    for(int i=0;i<NODES;i++)
        ex[i]=0;
    string line;
    ifstream myfile;
    myfile.open("bfstest2.txt");
    while(getline(myfile,line))
    {
        int c,x;
        stringstream s(line);
        s>>c;
        while(s>>x)
            ar[c].push_back(x);
    }
    for(int i=1;i<NODES;i++)
    {
        if(ex[i]==0)
        {
            ex[i]=1;
            tm.push(i);
            while(!tm.empty())
            {
                int st=tm.front();
                cout<<"\t"<<st;
                tm.pop();
                for(decltype(ar[st].size()) j=0;j<ar[st].size();j++)
                {
                    int t=ar[st][j];
                    if(ex[t]==0)
                    {
                        ex[t]=1;
                        tm.push(t);
                    }
                }
            }
        }
        cout<<endl;
    }
}