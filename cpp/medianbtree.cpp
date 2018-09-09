#include<iostream>
#include<fstream>
#include<chrono>
#define NODES 10001
struct node
{
    int n,sz;
    node *left,*right,*pa;
};
node* root=0;
int med[NODES];
using namespace std;
void insert(node **ptr,int x);
int median(node **ptr,int i);
int main()
{
    auto start = chrono::steady_clock::now();
    int x,j,i=1,sum=0;
    ifstream file;
    file.open("Median8.txt");
    file>>x;
    insert(&root,x);
    node *ptr=root;
    med[i]=x;
    i++;
    while(file>>x)
    {
        insert(&ptr,x);
        ptr=root;
        if(i%2==0)
            j=i/2;
        else
            j=(i+1)/2;
        med[i]=median(&ptr,j);
        i++;
    }
    for(int k=1;k<NODES;k++)
        sum=sum+med[k];
    sum=sum%10000;
    cout<<"ANS is "<<sum<<endl;
    file.close();
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<chrono::duration <double, milli> (diff).count()<<" ms"<<endl;
}
void insert(node **ptr,int x)
{
    static node* t=0;
    if((*ptr)==0)
    {
        node *tmp=new node;
        tmp->n=x;
        tmp->right=0;
        tmp->left=0;
        tmp->pa=t;
        tmp->sz=0;
        (*ptr)=tmp;
    }
    else if(x>(*ptr)->n)
    {
        t=(*ptr);
        insert(&((*ptr)->right),x);
    }
    else
    {
        t=(*ptr);
        insert(&((*ptr)->left),x);
    }
    ++((*ptr)->sz);
}
int median(node **ptr,int i)
{
    int a;
    if((*ptr)->left!=0)
        a=((*ptr)->left)->sz;
    else
        a=0;
    if(a==i-1)
        return (*ptr)->n;
    else if(a>=i)
        return median(&((*ptr)->left),i);
    else
         return median(&((*ptr)->right),i-a-1);
}