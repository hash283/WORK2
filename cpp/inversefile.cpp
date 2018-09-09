//program to compute no of inversions in an array from a file as input in O(nlogn) time
#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;
long sort(int ar[],int sp,int ep);
long merge(int ar[],int sp,int mp,int ep);
int main()
{
    auto start = chrono::steady_clock::now();
    ifstream myfile;
    myfile.open("Intarray.txt");
    int n=100000,x,i=0;
    int a[n];
    while(myfile>>x)
    {
        a[i]=x;
        i++;
    }
    long inv=sort(a,0,n-1);
    cout<<"the no of inversions are "<<inv<<endl;
    myfile.close();
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<chrono::duration <double, milli> (diff).count()<<" ms"<<endl;
}
long sort(int ar[],int sp,int ep)
{
    int n=ep-sp;
    int mp=(ep+sp)/2;
    if(n<1)
        return 0;
    else
    {
       long x=sort(ar,sp,mp);
       long y=sort(ar,mp+1,ep);
       long z=merge(ar,sp,mp,ep);
       return x+y+z;
    }

}
long merge(int ar[],int sp,int mp,int ep)
{
    int n=ep-sp+1;
    int i=sp,j=mp+1,k=0;
    long z=0;
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
