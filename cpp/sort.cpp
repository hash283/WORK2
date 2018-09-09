#include<iostream>
#include"sort.h"
void sortx(point ar[],int sp,int ep)
{
    int n=(ep-sp);
    int mp=(sp+ep)/2;
    if(n<1)
        return;
    else
    {
        sortx(ar,sp,mp);
        sortx(ar,mp+1,ep);
        mergex(ar,sp,mp,ep);
    }
}
void sorty(point ar[],int sp,int ep)
{
    int n=(ep-sp);
    int mp=(sp+ep)/2;
    if(n<1)
        return;
    else
    {
        sorty(ar,sp,mp);
        sorty(ar,mp+1,ep);
        mergey(ar,sp,mp,ep);
    }
}
void mergex(point ar[],int sp,int mp,int ep)
{
    int n=(ep-sp)+1;
    int l=0,i=sp,j=mp+1;
    point b[n];
    while(i<=mp && j<=ep)
    {
        if(ar[i].x<ar[j].x)
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
void mergey(point ar[],int sp,int mp,int ep)
{
    int n=(ep-sp)+1;
    int l=0,i=sp,j=mp+1;
    point b[n];
    while(i<=mp && j<=ep)
    {
        if(ar[i].y<ar[j].y)
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