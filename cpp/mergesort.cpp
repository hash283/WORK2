//program to sort array of integers using mergesort
#include<iostream>
void sorts(int ar[],int sp,int ep);
void merge(int ar[],int sp,int mp,int ep);
int main()
{
    int n;
    std::cout<<"Enter no of elements\n";
    std::cin>>n;
    int ar[n];
    std::cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
        std::cin>>ar[i];
    int sp=0,ep=n-1;
    int mp=(sp+ep)/2;
    sorts(ar,sp,mp);
    sorts(ar,mp+1,ep);
    merge(ar,sp,mp,ep);
    for(int k=0;k<n;k++)
        std::cout<<ar[k]<<"\t";
}
void sorts(int ar[],int sp,int ep)
{
    int n=(ep-sp);
    int mp=(sp+ep)/2;
    if(n<1)
        return;
    else
    {
        sorts(ar,sp,mp);
        sorts(ar,mp+1,ep);
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
