#include<iostream>
using namespace std;
int sort(int ar[],int sp,int ep);
int merge(int ar[],int sp,int mp,int ep);
int main()
{
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the nos\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int inv=sort(a,0,n-1);
    cout<<"the no of inversions are "<<inv<<endl;
    for(int j:a)
        cout<<j<<"\t";
}
int sort(int ar[],int sp,int ep)
{
    int n=ep-sp;
    int mp=(ep+sp)/2;
    if(n<1)
        return 0;
    else
    {
       int x=sort(ar,sp,mp);
       int y=sort(ar,mp+1,ep);
       int z=merge(ar,sp,mp,ep);
       return x+y+z;
    }

}
int merge(int ar[],int sp,int mp,int ep)
{
    int n=ep-sp+1;
    int i=sp,j=mp+1,k=0,z=0;
    int b[n];
    while(i<=mp && j<=ep)
    {
        if(ar[i]<=ar[j])
        {
            b[k]=ar[i];
            i++;
            k++;
        }
        else
        {
            b[k]=ar[j];
            j++;
            k++;
            z+=mp-i+1;
        }
    }
    while(i<=mp)
    {
        b[k]=ar[i];
        i++;
        k++;
    }
    while(j<=ep)
    {
        b[k]=ar[j];
        j++;
        k++;
    }
    for(int l=0,c=sp;l<n;l++)
    {
        ar[c]=b[l];
        c++;
    }
    return z;
}