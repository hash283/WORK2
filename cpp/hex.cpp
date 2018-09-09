#include<iostream>
#include<string>
#include<chrono>
using namespace std;
string hex(int n);
int main()
{
    auto start = chrono::steady_clock::now();
    int no;
    cout<<"Enter no"<<endl;
    cin>>no;
    cout<<hex(no)<<endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<chrono::duration <double, milli> (diff).count()<<" ms"<<endl;
}
string hex(int n)
{
    if(n<=9)
        return to_string(n);
    else
    {
        string s;
        int i=n%16;
        if(i>9)
        {
            s=s+(char)(i-10+65);
            s=hex(n/16)+s;
            return s;
        }
        else
        {
            s=hex(n/16)+to_string(i);
            return s;
        }
    }
}