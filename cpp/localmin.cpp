#include<iostream>
using namespace std;
int min(int ar[],int sp,int ep);
int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int m=min(ar,0,n-1);
    cout<<m;
}
int min(int ar[],int sp,int ep)
{
    int mp=(sp+ep)/2;
    if(mp==0 && ar[mp]<ar[mp+1])
        return ar[mp];
    else if(mp==ep && ar[mp]<ar[mp-1])
        return ar[mp];
    if(ar[mp]<ar[mp+1] && ar[mp]<ar[mp-1])
        return ar[mp];
    else if(ar[mp]>ar[mp+1])
        return min(ar,mp+1,ep);
    else
        return min(ar,sp,mp);
}