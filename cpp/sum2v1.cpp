//program to compute 
#include<iostream>
#include<fstream>
#include<algorithm>
#include<chrono>
#define BUCKETS 1000000
#define LOWER_RANGE -10000
#define UPPER_RANGE 10000
using namespace std;
int main()
{
    auto start = chrono::steady_clock::now();
    int range=UPPER_RANGE-LOWER_RANGE+1,sum=0;
    long long ar[BUCKETS];
    vector<bool> check;
    for(int i=0;i<range;i++)
        check.push_back(0);
    long i=0;
    ifstream file;
    file.open("sum2.txt");
    while(file>>ar[i])
        i++;
    sort(ar,ar+BUCKETS);
    for(long j=0;j<BUCKETS;j++)
    {
        long long *ptr1=0,*ptr2=0;
        long long y1=LOWER_RANGE-ar[j];
        long long y2=UPPER_RANGE-ar[j];
        ptr1=lower_bound(ar,ar+BUCKETS,y1);
        ptr2=lower_bound(ar,ar+BUCKETS,y2);
        if(ptr1!=0 && ptr2!=0)
         {
            for(long long *ptr=ptr1;ptr<=ptr2;ptr++)
            {
                long long t=*ptr+ar[j]-LOWER_RANGE;
                if(t>=0 && t<range)
                    check[t]=1;
            }
         }
    }
    for(int l=0;l<range;l++)
        if(check[l]==1)
            sum++;
    cout<<sum<<endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<chrono::duration <double, milli> (diff).count()<<" ms"<<endl;
}
