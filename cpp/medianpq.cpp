//program to compute median from a set of nos in O(logn) using stl priority queue
#include<iostream>
#include<queue>
#include<fstream>
#include<vector>
#include<chrono>
#define NODES 10001
using namespace std;
int med[NODES];
int main()
{
    auto start = chrono::steady_clock::now();
    priority_queue <int> sm;
    priority_queue <int, vector<int>, greater<int>> big;
    ifstream file;
    file.open("Median8.txt");
    int x,j,i=1,sum=0;
    file>>x;
    sm.push(x);
    med[i]=x;
    i++;
    int sz1=1,sz2=0;
    while(file>>x)
    {
        j=sm.top();
        if(x>j)
        {
            big.push(x);
            ++sz2;
        }
        else
        {
            sm.push(x);
            ++sz1;
        }
        if(sz1-sz2>1)
        {
            int c=sm.top();
            sm.pop();
            --sz1;
            big.push(c);
            ++sz2;
        }
        else if(sz2-sz1>1)
        {
            int c=big.top();
            big.pop();
            --sz2;
            sm.push(c);
            ++sz1;
        }
        if(i%2==0)
            med[i]=sm.top();
        else
            {
                if(sz2>sz1)
                    med[i]=big.top();
                else
                    med[i]=sm.top();
            }
        ++i;
    }
    for(int i=1;i<NODES;i++)
        sum=sum+med[i];
    sum=sum%10000;
    cout<<"the sol is "<<sum<<endl;
    file.close();
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<chrono::duration <double, milli> (diff).count()<<" ms"<<endl;
}
