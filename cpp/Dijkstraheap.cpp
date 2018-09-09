//Implementation of Dijistra algorithm to compute min distance from a source vetex to another
#include<iostream>
#include<vector>
#include<chrono>
#include<string>
#include<climits>
#include<fstream>
#include<sstream>
#define NODES 201
struct node
{
    int n;
    int dist;
};
using namespace std;
int key[NODES],track[NODES];
bool visited[NODES];
int extractmin(vector<int> &heap);
void del(vector<int> &heap,int pos);
void insert(vector<int> &heap,int point);
void driver(vector<int> &heap,int i,int c);
int main()
{
    auto start = chrono::steady_clock::now();
    node v;
    vector<node> gr[NODES];
    vector<int> heap;
    for(int i=1;i<=NODES-1;i++)
        heap.push_back(i);
    for(int i=1;i<NODES;i++)
    {
        key[i]=INT_MAX;
        track[i]=i-1;
        visited[i]=0;
    }
    int x,c,y,source;
    string line;
    char temp;
    ifstream myfile;
    myfile.open("DIJ.txt");
    while(getline(myfile,line))
    {
        stringstream ss(line);
        ss>>c;
        while(ss>>x>>temp>>y)
        {
            v.n=x;
            v.dist=y;
            gr[c].push_back(v);
        }
    }
    key[1]=0;
    while(!heap.empty())
    {
        source=extractmin(heap);
        visited[source]=1;
        node t;
        auto size=gr[source].size();
        for(decltype(gr[source].size()) j=0;j<size;j++)
        {
            t=gr[source][j];
            int point=t.n;
            if(visited[point]==0)
            {
                int length=t.dist+key[source];
                if(key[point]>length)
                {
                    del(heap,track[point]);
                    key[point]=length;
                    insert(heap,point);
                }
            }
        }
    }
    for(int i=1;i<NODES;i++)
        if((i==7)||(i==37)||(i==59)||(i==82)||(i==99)||(i==115)||(i==133)||(i==165)||(i==188)||(i==197))
            cout<<"minimum distance from 1 to "<<i<<" is "<<key[i]<<endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<chrono::duration <double, milli> (diff).count()<<" ms"<<endl;
}
int extractmin(vector<int> &heap)
{
    auto size=heap.size();
    auto top=size-1;
    int tm=heap[top];
    heap[top]=heap[0];
    heap[0]=tm;
    int source=heap[top];
    heap.pop_back();
    track[heap[0]]=0;
    size=size-1;
    if(size<=1)
        return source;
    int i=0;
    unsigned long c1=1,c2=2;
    if(size>2)
    {
        while((key[heap[i]]>key[heap[c1]]) || (key[heap[i]]>key[heap[c2]]))
        {
            if(key[heap[c1]]<key[heap[c2]])
            {
                driver(heap,i,c1);
                i=c1;
            }
            else
            {
                driver(heap,i,c2);
                i=c2;
            }
            c1=(2*i)+1;
            c2=(2*i)+2;
            if(c1>size-1)
                break;
            if(c1==size-1)
            {
                if(key[heap[i]]>key[heap[c1]])
                        driver(heap,i,c1);
                break;
            }
        }
    }
    else if(size==2)
            driver(heap,i,c1);
    return source;
}
void del(vector<int> &heap,int pos)
{
    unsigned long c1,c2;
    auto size=heap.size();
    unsigned long i=pos;
    if(size==1)
    {
        heap.pop_back();
        return;
    }
    auto top=size-1;
    int tm=heap[top];
    heap[top]=heap[pos];
    heap[pos]=tm;
    heap.pop_back();
    size=size-1;
    c1=(2*i)+1,c2=(2*i)+2;
    track[heap[pos]]=pos;
    if(c1>size-1)
        return;
    if(c1==size-1)
    {
        if(key[heap[i]]>key[heap[c1]])
                driver(heap,i,c1);
        return;
    }
    while((key[heap[i]]>key[heap[c1]]) || (key[heap[i]]>key[heap[c2]]))
    {
        if(key[heap[c1]]<key[heap[c2]])
        {
            driver(heap,i,c1);
            i=c1;
        }
        else
        {
            driver(heap,i,c2);
            i=c2;
        }
        c1=(2*i)+1;
        c2=(2*i)+2;
        if(c1>size-1)
                return;
        if(c1==size-1)
        {
            if(key[heap[i]]>key[heap[c1]])
                    driver(heap,i,c1);
            return;
        }
    }
}
void insert(vector<int> &heap,int point)
{
    heap.push_back(point);
    auto size=heap.size();
    auto i=size-1;
    track[point]=i;
    if(size==1)
        return;
    unsigned long pa;
    if(i%2==0)
        pa=(i/2)-1;
    else
        pa=i/2;
    while(key[heap[pa]]>key[heap[i]])
    {
        driver(heap,i,pa);
        i=pa;
        if(i==0)
            return;
        if(i%2==0)
            pa=(i/2)-1;
        else
            pa=i/2;
    }
}
void driver(vector<int> &heap,int i,int c)
{
    track[heap[i]]=c;
    track[heap[c]]=i;
    int tm=heap[c];
    heap[c]=heap[i];
    heap[i]=tm;
}
