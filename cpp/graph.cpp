#include<iostream>
#include<random>
#include<vector>
#include<sstream>
#include<string>
#include<climits>
#include<fstream>
using namespace std;
int main()
{
    int i=200,j=200,k=0,l,m,c,sm=INT_MAX,edge;
    vector<int> ar[201];
    vector<int> ar2[201];
    ifstream file;
    file.open("assignment3.txt");
    string line;
    while(getline(file,line))
    {
        stringstream s(line);
        s>>c;
        int value;
        while(s>>value)
        {
            ar[c].push_back(value);
            k++;
        }
    }
    for(int n=1;n<=200;n++)
        ar2[n]=ar[n];
    edge=k;
    for(int d=1;d<=400;d++)
    {
        k=edge;
        i=200;
        j=200;
        while(i>2)
        {
            random_device rd;
            mt19937 seed(rd());
            uniform_int_distribution<> dist(1,j);
            l=dist(seed);
            while(ar[l].empty())
            {
                vector<int> tm;
                tm=ar[l];
                ar[l]=ar[j];
                ar[j]=tm;
                j--;
                uniform_int_distribution<> dist3(1,j);
                l=dist3(seed);
            }
            uniform_int_distribution<> dist2(0,ar[l].size()-1);
            m=dist2(seed);
            ar[l].erase(ar[l].begin()+m);
            i--;
            k--;
        }
        if(k<sm)
            sm=k;
        for(int n=1;n<=200;n++)
            ar[n]=ar2[n];
    }
    cout<<sm;
}