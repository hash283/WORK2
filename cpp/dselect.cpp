#include<iostream>
#include"sortutil.h"
using namespace std;
int dselect(int ar[],int sp,int ep,int i);
int main()
{
    int n,i;
    cout<<"Enter the size of array\n";
    cin>>n;
    int ar[n];
    cout<<"Enter the array elements\n";
    for(int j=0;j<n;j++)
        cin>>ar[j];
    cout<<"Enter the ith minimum element to be found\n";
    cin>>i;
    cout<<dselect(ar,0,n-1,i);
}
int dselect(int ar[],int sp,int ep,int i)
{
    int n=ep-sp+1,mp=(ep+sp)/2;
    if(n<=5)
    {
        sort(ar,sp,ep);
        if(i==mp)
            return ar[mp];
        else if(i<mp)
            return dselect(ar,sp,mp-1,i);
        else
            return dselect(ar,mp+1,ep,i);
    }
    else
    {
        int m=n/5,d=0,j=0,k,l,end;
        if(n%5>0)
            m+=1;
        int c[m];
        for(int h=sp;h<=ep;h+=5)
        {
            if(ep-h>3)
                end=h+4;
            else
                end=ep;
            sort(ar,h,end);
            c[d]=ar[(end+h)/2];
            d++;
        }
        int p=dselect(c,0,m-1,ep/10);
        for(int h=sp;h<=ep;h++)
        {
            if(ar[h]==p)
            {
                j=h;
                break;
            }
        }
        int tmp=ar[sp];
        ar[sp]=ar[j];
        ar[j]=tmp;
        for(k=sp+1,l=sp+1;k<=ep;k++)
        {
            if(ar[k]<ar[sp])
            {
                tmp=ar[l];
                ar[l]=ar[k];
                ar[k]=tmp;
                l++;
            }
        }
        j=l-1;
        tmp=ar[sp];
        ar[sp]=ar[j];
        ar[j]=tmp;
        if(i==j)
            return ar[j];
        else if(i<j)
            return dselect(ar,sp,j-1,i);
        else
            return dselect(ar,j+1,ep,i);
    }
}