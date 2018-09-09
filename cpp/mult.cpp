//program to multiply 2 large nos using karatsuba multiplication(recursion)
#include<iostream>
#include<string>
using namespace std;
string multiply(string x,string y);
int main()
{
    string x,y;
    cout<<"Enter the two nos\n";
    cin>>x>>y;
    string pro=multiply(x,y);
    cout<<pro;
}
string multiply(string x,string y)
{
    auto n=x.size();
    if(n==1)
        return to_string(stoi(x)*stoi(y));
    else
    {
        string a,b,c,d,s1,s2,s3,final;
        string temp1(n,'0'),temp2(n/2,'0');
        for(decltype(x.size()) i=0;i<n/2;i++)
        {
            a=a+x[i];
            c=c+y[i];
        }
        for(auto i=n/2;i<n;i++)
        {
            b=b+x[i];
            d=d+y[i];
        }
        string ac=multiply(a,c);
        string bd=multiply(b,d);
        string ad=multiply(a,d);
        string bc=multiply(b,c);
        auto n2=bd.size(),n3=ad.size(),n4=bc.size();
        s1=ac+temp1;
        int carry=0;
        if(n3>n4)
        {
            string temp3(n3-n4,'0');
            bc=temp3+bc;
        }
        else
        {
            string temp3(n4-n3,'0');
            ad=temp3+ad;
        }
        for(long i=ad.size()-1;i>=0;i--)
        {
            int sum=((int)ad[i]-48)+((int)bc[i]-48)+carry;
            s2=to_string(sum%10)+s2;
            carry=sum/10;
        }
        if(carry>0)
            s2=to_string(carry)+s2;
        s2=s2+temp2;
        if(s1.size()>s2.size())
        {
            string temp4(s1.size()-s2.size(),'0');
            s2=temp4+s2;
        }
        else
        {
            string temp4(s2.size()-s1.size(),'0');
            s2=temp4+s2;
        }
        string temp5(s1.size()-n2,'0');
        s3=temp5+bd;
        carry=0;
        for(long i=s1.size()-1;i>=0;i--)
        {
            int sum=((int)s1[i]-48)+((int)s2[i]-48)+((int)s3[i]-48)+carry;
            final=to_string(sum%10)+final;
            carry=sum/10;
        }
        if(carry>0)
            final=to_string(carry)+final;
        return final;
    }
}
