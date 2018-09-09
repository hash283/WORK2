#include<iostream>
#include<vector>
#include<random>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
struct edge
{
    int src,dest;
};
struct vertex
{
    int name;
    vector<int> merged;
    vector<int> edges;
};
struct graph
{
    int vcount;
    vector<edge> edges;
    vector<vertex> vertices;
};
int main()
{
    graph g;
    g.vcount=0;
    ifstream myfile;
    myfile.open();
    string line;
    while(getline(myfile,line))
    {
        int temp1,temp2
        vertex v;
        stringstream ss(line);
        ss>>temp1;
        v.name=temp1;
        while(ss>>temp2)
        {
            v.edges.push_back(temp2);
            if(temp2>temp1)
            {
                edge e;
                e.src=temp1;
                e.dest=temp2;
                g.edges.push_back(e);
            }
            g.vcount++;
            g.vertices.push_back(v);
        }
    }
    auto sz=g.edges.size();
    int ite=g.vertices*g.vertices*log(g.vertices);
    for(int i=1;i<=ite;i++)
    {
        while(g.vertices>2)
        {
            random_device rd;
            mt19937 seed(rd());
            uniform_int_distribution<> di(0,sz-1);
            int l=di(seed);
        }
    }


}