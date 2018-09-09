//program using randomised seletion to find the ith order statistic in an array 
#include<iostream>
#include<random>
using namespace std;
int select(int ar[],int sp,int ep,int i);
int main()
{
    int n,i;
    cout<<"Enter the size of array\n";
    cin>>n;
    int ar[n];
    cout<<"Enter the array elements\n";
    for(int j=0;j<n;j++)
    {
        cin>>ar[j];
    }
    cout<<"Enter the ith minimum element to be found\n";
    cin>>i;
    cout<<select(ar,0,n-1,i-1);
}
int select(int ar[],int sp,int ep,int i)
{
    int n=ep-sp+1;
    if(n==1)
        return ar[sp];
    else
    {
        int j,k,l;
        random_device rd;
        mt19937 seed(rd());
        uniform_int_distribution<> dist(sp,ep);
        j=dist(seed);
        cout<<"partion index is ";
        cout<<j;
        cout<<"\n";
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
        cout<<"The current index after partition is";
        cout<<j;
        cout<<"\n";
        if(i==j)
            return ar[j];
        else if(i<j)
            return select(ar,sp,j-1,i);
        else
            return select(ar,j+1,ep,i);
    }
}
