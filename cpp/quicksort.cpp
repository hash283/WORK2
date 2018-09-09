#include<iostream>
using namespace std;
int quicksort(int ar[],int sp,int ep);
int main()
{
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int ar[n];
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++)
     cin>>ar[i];
    int c=quicksort(ar,0,n-1);
    for(auto i:ar)
        cout<<i<<"\t";
    cout<<"\n"<<c;
}
int quicksort(int ar[],int sp,int ep)
{
    int n=ep-sp+1,j=sp+1,tmp;
    if(n<=1)
        return 0;
    else
    {
        int pi=ar[sp];
        for(int i=sp+1;i<=ep;i++)
        {
            if(ar[i]<pi)
                {
                    tmp=ar[i];
                    ar[i]=ar[j];
                    ar[j]=tmp;
                    j++;
                }
        }
        int z=n-1;
        tmp=ar[sp];
        ar[sp]=ar[j-1];
        ar[j-1]=tmp;
        int x=quicksort(ar,sp,j-2);
        int y=quicksort(ar,j,ep);
        return x+y+z;
    }
}