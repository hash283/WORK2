#include<iostream>
using namespace std;
int perm(int n,int r);
int main()
{
    int n,r;
    cout<<"Enter n\n";
    cin>>n;
    cout<<"Enter r\n";
    cin>>r;
    int res=perm(n,r);
    cout<<res<<endl;
}
int perm(int n,int r)
{
    if(n<=1)
        return 1;
    else if(r==1)
        return n;
    else if(r==0)
        return 1;
    else
    {
        int n1=n*perm(n-1,r);
        int n2=(n-r)*perm(n-r-1,r);
        int n3=r*perm(r-1,r);
        return n1/(n2*n3);
    }
}