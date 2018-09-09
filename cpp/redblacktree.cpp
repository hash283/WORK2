#include<iostream>
struct node
{
    int n,sz;
    node *left,*right,*pa
    char color;
};
node *root=0;
using namespace std;
void insert(node **ptr,int x);
void color(node **ptr);
int main()
{
    int c,x;
    cout<<"Enter Nos"<<endl;
    cout<<"Enter 9999 for break"<<endl;
    cin>>c;
    insert(&root,c);
    node *ptr=root;
    while(cin>>x)
    {
        insert(&ptr,x);
        ptr=root;
    }
}
void insert(node **ptr,int x)
{
    static node* t=0;
    if(*ptr==0)
    {
        node *tmp=new node;
        tmp->n=x;
        tmp->left=0;
        tmp->right=0;
        tmp->pa=t;
        tmp->sz=0;
        (*ptr)=tmp;
        void color(ptr);
    }
    else if(x<(*ptr)->n)
    {
        t=*ptr;
        insert(&((*ptr)->left),x);
    }
    else
    {
        t=*ptr;
        insert(&((*ptr)->right),x);
    }
    ++((*ptr)->sz);
}
void color(node **ptr)
{
    if((*ptr)->pa==0)
        (*ptr)->color="B";
    else if(((*ptr)->pa)->color=="B")
        (*ptr)->color="R";
    else if(((*ptr)->pa)->color=="R")
    {
        node* par=(*ptr)->pa;
        if(par->right==(*ptr))
        {
            if(par->left!=NULL)
            {
                if((part->left)
            }
        }
        else
        {

        }
    }
}