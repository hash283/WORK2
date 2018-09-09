#include<iostream>
using namespace std;
bool find(int ar[],int sp,int ep);
int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    bool x=find(ar,0,n-1);
     if(x)
        cout<<"Found it\n";
    else
     cout<<"Not found it\n";
}
bool find(int ar[],int sp,int ep)
{
    int mp=(ep+sp)/2;
    if(sp==ep)
        return false;
    if(ar[mp]==mp)
        return true;
    else if(ar[mp]>mp)
        return find(ar,sp,mp);
    else
        return find(ar,mp+1,ep);
}