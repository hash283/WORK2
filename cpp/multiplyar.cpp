#include<iostream>
#include<cmath>
int* multiply(int x[],int y[],int n);
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of no\n",
    cin>>n;
    int x[n],y[n];
    cout<<"Enter the no\n";
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
        cin>>y[i];
    int* pro=multiply(x,y,n);
    for(int i=0;i<(2*n);i++)
        cout<<pro[i];
}
int* multiply(int x[],int y[],int n)
{
    if(n==1)
    {
        int *pro=(int*)malloc(2*sizeof(int));
        pro[0]=(x[0]*y[0])/10;
        pro[1]=(x[0]*y[0])%10;
        return pro;
    }
    else
    {
        int l=2*n;
        int *final=(int*)malloc(l*sizeof(int));
        int a[n/2],b[n/2],c[n/2],d[n/2],ar[l],ar1[n+1],ar2[l],ar3[l];
        for(int i=0;i<n/2;i++)
        {
            a[i]=x[i];
            c[i]=y[i];
        }
        for(int j=n/2,k=0;j<n;j++)
        {
            b[k]=x[j];
            d[k]=y[j];
            k++;
        }
        for(int i=0;i<l;i++)
        {
            ar[i]=0;
            ar2[i]=0;
            ar[3]=0;
        }
        int* ac=multiply(a,c,n/2);
        int* bd=multiply(b,d,n/2);
        int* ad=multiply(a,d,n/2);
        int* bc=multiply(b,c,n/2);
        for(int i=0;i<n;i++)
            ar[i]=ac[i];
        int carry=0,k=l-(n+1);
        for(int i=n;i>0;i--)
        {
            int sum=(bc[i-1]+ad[i-1]+carry);
            ar1[i]=sum%10;
            carry=sum/10;
        }
        ar1[0]=carry;
        for(int i=0;i<=n;i++)
            ar2[k+i]=ar1[i];
        for(int i=n-1,j=l-1;i>=0;i--)
            {
                ar3[j]=bd[i];
                j--;
            }
        carry=0;
        for(int i=l-1;i>=0;i--)
        {
            int su=ar[i]+ar2[i]+ar3[i]+carry;
            final[i]=su%10;
            carry=su/10;
        }
        return final;
    }
}