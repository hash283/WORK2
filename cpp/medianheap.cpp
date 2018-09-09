//program to compute median from a set of nos in O(logn) time using a heap
#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>
#define NODES 10001
using namespace std;
int med[NODES];
int extractmin(vector<int> &big);
int extractmax(vector<int> &sm);
void insertmax(vector<int> &sm,int x);
void insertmin(vector<int> &big,int x);
void swaps(vector<int> &heap,int c,int i);
int main()
{
    auto start = chrono::steady_clock::now();
    vector<int> sm;
    vector<int> big;
    ifstream file;
    file.open("Median8.txt");
    int x,j,i=1,sum=0;
    file>>x;
    sm.push_back(x);
    med[i]=x;
    i++;
    int sz1=1,sz2=0;
    while(file>>x)
    {
        j=sm[0];
        if(x>j)
        {
            insertmin(big,x);
            ++sz2;
        }
        else
        {
            insertmax(sm,x);
            ++sz1;
        }
        if(sz1-sz2>1)
        {
            int c=extractmax(sm);
            --sz1;
            insertmin(big,c);
            ++sz2;
        }
        else if(sz2-sz1>1)
        {
            int c=extractmin(big);
            --sz2;
            insertmax(sm,c);
            ++sz1;
        }
        if(i%2==0)
            med[i]=sm[0];
        else
            {
                if(sz2>sz1)
                    med[i]=big[0];
                else
                    med[i]=sm[0];
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
void insertmin(vector<int> &big,int x)
{
    big.push_back(x);
    auto size=big.size();
    if(size==1)
        return;
    auto i=size-1;
    unsigned long pa;
    if(i%2==0)
        pa=(i/2)-1;
    else
        pa=i/2;
    while(big[pa]>big[i])
    {
        swaps(big,pa,i);
        i=pa;
        if(i==0)
            return;
        if(i%2==0)
            pa=(i/2)-1;
        else
            pa=i/2;
    }
}
void insertmax(vector<int> &sm,int x)
{
    sm.push_back(x);
    auto size=sm.size();
    if(size==1)
        return;
    auto i=size-1;
    auto pa=i;
    if(i%2==0)
        pa=(i/2)-1;
    else
        pa=i/2;
    while(sm[pa]<sm[i])
    {
        swaps(sm,pa,i);
        i=pa;
        if(i==0)
            return;
        if(i%2==0)
            pa=(i/2)-1;
        else
            pa=i/2;
    }
}
int extractmin(vector<int> &big)
{
    int source=big[0];
    auto size=big.size();
    auto i=size-1;
    int tm=big[0];
    big[0]=big[i];
    big[i]=tm;
    i=0;
    unsigned long c1=1,c2=2;
    big.pop_back();
    --size;
    if(size<=1)
        return source;
    else if(size==2)
    {
        if(big[i]>big[c1])
            swaps(big,c1,i);
    }
    else
    {
        while(big[i]>big[c1] || big[i]>big[c2])
        {
            if(big[c1]<big[c2])
            {
                swaps(big,c1,i);
                i=c1;
            }
            else
            {
                swaps(big,c2,i);
                i=c2;
            }
            c1=(2*i)+1;
            c2=(2*i)+2;
            if(c1>size-1)
                break;
            if(c1==size-1)
            {
                if(big[i]>big[c1])
                    swaps(big,c1,i);
                break;
            }
        }
    }
    return source;
}
int extractmax(vector<int> &sm)
{
    int source=sm[0];
    auto size=sm.size();
    auto i=size-1;
    int tm=sm[0];
    sm[0]=sm[i];
    sm[i]=tm;
    i=0;
    unsigned long c1=1,c2=2;
    sm.pop_back();
    --size;
    if(size<=1)
        return source;
    else if(size==2)
    {
        if(sm[i]<sm[c1])
            swaps(sm,c1,i);
    }
    else
    {
        while(sm[i]<sm[c1] || sm[i]<sm[c2])
        {
            if(sm[c1]>sm[c2])
            {
                swaps(sm,c1,i);
                i=c1;
            }
            else
            {
                swaps(sm,c2,i);
                i=c2;
            }
            c1=(2*i)+1;
            c2=(2*i)+2;
            if(c1>size-1)
                break;
            if(c1==size-1)
            {
                if(sm[i]<sm[c1])
                    swaps(sm,c1,i);
                break;
            }
        }
    }
    return source;
}
void swaps(vector<int> &heap,int c,int i)
{
    int tm=heap[i];
    heap[i]=heap[c];
    heap[c]=tm;
}
