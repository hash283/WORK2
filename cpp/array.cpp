#include<iostream>
int main()
{
    int n=5;
    int ar[n];
    for(int i=0;i<5;i++)
        std::cin>>ar[i];
    for(int i:ar)
        std::cout<<i;
}