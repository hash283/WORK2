#include<iostream>
using namespace std;
int max(int ar[],int sp,int ep);
int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int m=max(ar,0,n-1);
    cout<<"largest nos is"<<m;
}
int max(int ar[],int sp,int ep)
{
    int mp=(sp+ep)/2;
    if((ar[mp-1]<ar[mp]) && (ar[mp]>ar[mp+1]))
        return ar[mp];
    else if(ar[mp-1]>ar[mp])
        return max(ar,sp,mp);
    else
        return max(ar,mp+1,ep);
}
