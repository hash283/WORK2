#include<iostream>
#include<fstream>
using namespace std;
long quicksort(int ar[],int sp,int ep);
int main()
{
    ifstream file;
    file.open("quicksort.txt");
    int n=10000,i=0;
    int ar[n];
    while(file>>ar[i])
        i++;
    long comp=quicksort(ar,0,n-1);
    cout<<comp<<endl;
    file.close();
}
long quicksort(int ar[],int sp,int ep)
{
    int n=ep-sp+1,tm,j=sp+1,mp=(ep+sp)/2,med;
    if(n<=1)
        return 0;
    else
    {
        if(ar[sp]>ar[mp])
        {
            if(ar[sp]<ar[ep])
                med=sp;
            else if(ar[ep]<ar[mp])
                med=mp;
            else
                med=ep;
        }
        else
        {
            if(ar[mp]<ar[ep])
                med=mp;
            else if(ar[ep]<ar[sp])
                med=sp;
            else
                med=ep;
        }
        int pi=ar[med];
        long z=n-1;
        tm=ar[med];
        ar[med]=ar[sp];
        ar[sp]=tm;
        for(int i=sp+1;i<=ep;i++)
        {
            if(ar[i]<pi)
            {
                tm=ar[i];
                ar[i]=ar[j];
                ar[j]=tm;
                j++;
            }
        }
        tm=ar[sp];
        ar[sp]=ar[j-1];
        ar[j-1]=tm;
        long x=quicksort(ar,sp,j-2);
        long y=quicksort(ar,j,ep);
        return x+y+z;
    }
}