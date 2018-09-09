#include<iostream>
using namespace std;
int main()
{
    int n,k=1,product,total;
    cout<<"Enter the no of digits\n";
    cin>>n;
    int a[n],b[n],c[2*n];
    cout<<"Enter the first no\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the 2nd no\n";
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<(2*n);i++)
        c[i]=0;
    for(int i=n-1;i>=0;i--)
    {
        int d=(2*n)-k;
        int pcarry=0;
        int scarry=0;
        for(int j=n-1;j>=0;j--)
        {
            product=(b[i]*a[j])+pcarry;
            pcarry=product/10;
            total=c[d]+(product%10)+scarry;
            scarry=total/10;
            c[d]=total%10;
            d--;
        }
        c[d]=pcarry+scarry;
        k++;
    }
    for(int i:c)
        cout<<i;
}