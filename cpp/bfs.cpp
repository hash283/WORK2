//algorithm to compute minimum hops from one point to another in an undirected graph using bfs
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
struct node
{
    int label;
    node* next;
};
struct queue
{
    int n;
    queue *left,*right;
};
queue* head=0;
queue* tail=0;
int main()
{
    string line;
    int source,ne=0;
    node* ar[7];
    bool ex[7];
    int dist[7];
    for(int i=0;i<7;i++)
    {
        ar[i]=0;
        ex[i]=0;
        dist[i]=0;
    }
    cout<<"Enter source vertex\n";
    cin>>source;
    ifstream file;
    file.open("bfstext");
    while(getline(file,line))
    {
        int c,x;
        stringstream ss(line);
        ss>>c;
        while(ss>>x)
        {
            if(x>c)
                ne++;
            node* ptr=new node;
            ptr->label=x;
            ptr->next=0;
            if(ar[c]==0)
                ar[c]=ptr;
            else
            {
                ptr->next=ar[c];
                ar[c]=ptr;
            }
        }
    }
    queue *tmp=new queue;
    tmp->n=source;
    ex[source]=1;
    head=tmp;
    tail=tmp;
    tmp->left=0;
    tmp->right=0;
    while(head!=0)
    {
        queue* tp=head;
        int st=head->n;
        head=tp->right;
        delete tp;
        cout<<st<<endl;
        for(node* trv=ar[st];trv!=0;trv=trv->next)
        {
            if(ex[trv->label]==0)
            {
                dist[trv->label]=dist[st]+1;
                ex[trv->label]=1;
                tmp=new queue;
                tmp->n=trv->label;
                tmp->left=0;
                tmp->right=0;
                if(head==0)
                {
                    head=tmp;
                    tail=tmp;
                }
                else
                {
                    tail->right=tmp;
                    tmp->left=tail;
                    tail=tmp;
                }
            }
        }
    }
    for(int i=1;i<=6;i++)
    {
       cout<<"Minimum no of hops from "<<source<<" to "<<i<<" is "<<dist[i]<<endl;
    }
    cout<<"\nNo of edges are "<<ne<<endl;

}
