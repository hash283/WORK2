#include<iostream>
#include"sortutil.h"
void sort(int ar[],int sp,int ep)
{
    int n=(ep-sp);
    int mp=(sp+ep)/2;
    if(n<1)
        return;
    else
    {
        sort(ar,sp,mp);
        sort(ar,mp+1,ep);
        merge(ar,sp,mp,ep);
    }
}
void merge(int ar[],int sp,int mp,int ep)
{
    int n=(ep-sp)+1;
    int b[n],l=0,i=sp,j=mp+1;
    while(i<=mp && j<=ep)
    {
        if(ar[i]<ar[j])
        {
            b[l]=ar[i];
            l++;
            i++;
        }
        else
        {
            b[l]=ar[j];
            l++;
            j++;
        }
    }
    while(i<=mp)
    {
        b[l]=ar[i];
        i++;
        l++;
    }
    while(j<=ep)
    {
        b[l]=ar[j];
        j++;
        l++;
    }
    for(int k=0,c=sp;k<n;k++)
    {
        ar[c]=b[k];
        c++;
    }
}