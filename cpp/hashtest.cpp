#include<iostream>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<vector>
#define BUCKETS 1000003
using namespace std;
struct node
{
    long long n;
    node* next;
};
long long hashf(long long x);
int main()
{
    vector<int> check;
    long long t,counter=0,unfilled=0;
    node* ar[BUCKETS];
    for(long long i=0;i<BUCKETS;i++)
    {
        ar[i]=0;
        check.push_back(0);
    }
    ifstream file;
    file.open("sum2.txt");
    while(file>>t)
    {
        node* tm=new node;
        tm->n=t;
        tm->next=0;
        long long i=hashf(t);
        if(ar[i]==0)
            ar[i]=tm;
        else
        {
            counter++;
            tm->next=ar[i];
            ar[i]=tm;
            check[i]++;
        }
    }
    sort(check.begin(),check.end());
    for(long long i=0;i<BUCKETS;i++)
    {
        if(ar[i]==0)
            unfilled++;
    }
    cout<<"no of unfilled buckets are "<<unfilled<<endl;
    cout<<"no of buckets having more than one data are "<<counter<<endl;
    cout<<check[BUCKETS];
}
long long hashf(long long x)
{
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return x%BUCKETS;
}
