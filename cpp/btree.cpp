#include<iostream>
#include<climits>
struct node
{
    int n;
    int sz;
    node* left;
    node* right;
    node* pa;
};
node* root=0;
void insert(node **ptr,int x);
void print(node **ptr);
void del(node **ptr);
bool search(node **ptr,int no);
node* searchp(node **ptr,int no);
int min(node **ptr);
node* max(node **ptr);
node* pred(node **ptr,int x);
int size(node **ptr);
int select(node **ptr,int i);
using namespace std;
int main()
{
    int x1,x2,no,i,d;
    cout<<"Construct Binary tree"<<endl;
    cin>>x1;
    insert(&root,x1);
    node* ptr=root;
    while(cin>>x2)
    {
        if(x2==9999)
            break;
        insert(&ptr,x2);
        ptr=root;
    }
    cout<<"size of tree is "<<size(&ptr)<<endl;
    cout<<"Enter no for search"<<endl;
    cin>>no;
    bool c=search(&ptr,no);
    if(c)
        cout<<"FOUND"<<endl;
    else
        cout<<"NOT Found"<<endl;
    cout<<"Minimum value of tree is "<<min(&ptr)<<endl;
    cout<<"Maximum value of tree is "<<(max(&ptr))->n<<endl;
    cout<<"Enter the no for predeccesor"<<endl;
    cin>>no;
    node* key=searchp(&ptr,no);
    if(key->left!=0)
        cout<<"predecessor of "<<no<<" is "<<(max(&(key->left)))->n<<endl;
    else
        cout<<"predecessor of no is "<<(pred(&key,no))->n<<endl;
    cout<<"Enter ith order statistic"<<endl;
    ptr=root;
    cin>>i;
    cout<<"The "<<i<<"th order statistic is "<<select(&ptr,i)<<endl;
    cout<<"select element for deletion"<<endl;
    cin>>d;
    ptr=searchp(&ptr,d);
    del(&ptr);
    ptr=root;
    print(&ptr);
}
int size(node **ptr)
{
    if((*ptr)->left==0 && (*ptr)->right==0)
    {
        (*ptr)->sz=1;
        return (*ptr)->sz;
    }
    else if((*ptr)->left==0)
    {
        (*ptr)->sz=size(&((*ptr)->right))+1;
        return (*ptr)->sz;
    }
    else if((*ptr)->right==0)
    {
        (*ptr)->sz=size(&((*ptr)->left))+1;
        return (*ptr)->sz;
    }
    else
    {
        (*ptr)->sz=size(&((*ptr)->left))+size(&((*ptr)->right))+1;
        return (*ptr)->sz;
    }
}
void insert(node **ptr,int x)
{
    static node *t=0;
    if(*ptr==0)
    {
        node *tmp=new node;
        tmp->n=x;
        tmp->left=0;
        tmp->right=0;
        tmp->sz=0;
        tmp->pa=t;
        (*ptr)=tmp;
        return;
    }
    else if(x>(*ptr)->n)
    {
        t=*ptr;
        insert(&((*ptr)->right),x);
    }
    else
    {
        t=*ptr;
        insert(&((*ptr)->left),x);
    }
}
bool search(node **ptr,int no)
{
    if(*ptr==0)
        return 0;
    else if((*ptr)->n==no)
        return 1;
    else if(no>(*ptr)->n)
        return search(&((*ptr)->right),no);
    else
        return search(&((*ptr)->left),no);
}
node* searchp(node **ptr,int no)
{
    if(*ptr==0)
        return 0;
    else if((*ptr)->n==no)
        return *ptr;
    else if(no>(*ptr)->n)
        return searchp(&((*ptr)->right),no);
    else
        return searchp(&((*ptr)->left),no);
}
void print(node **ptr)
{
    if(((*ptr)->left)!=0)
        print(&((*ptr)->left));
    cout<<(*ptr)->n<<endl;
    if(((*ptr)->right)!=0)
        print(&((*ptr)->right));
}
int select(node **ptr,int i)
{
    int a;
    if((*ptr)->left!=0)
        a=((*ptr)->left)->sz;
    else
        a=0;
    if(a==i-1)
        return (*ptr)->n;
    else if(a>=i)
        return select(&((*ptr)->left),i);
    else
        return select(&((*ptr)->right),i-a-1);
}
int min(node **ptr)
{
    if((*ptr)->left==0)
        return (*ptr)->n;
    else
        return min(&(*ptr)->left);
}
node* max(node **ptr)
{
    if((*ptr)->right==0)
        return (*ptr);
    else
        return max(&(*ptr)->right);
}
node* pred(node **ptr,int x)
{
    if((*ptr)->n<x)
            return (*ptr);
    else if((*ptr)->pa==0)
        return 0;
    else
        return pred(&((*ptr)->pa),x);
}
void del(node **ptr)
{
    if((*ptr)->left==0 && (*ptr)->right==0)
    {
        delete *ptr;
        *ptr=0;
    }
    else if((*ptr)->left==0)
    {
        node* trv=*ptr;
        ((*ptr)->right)->pa=(*ptr)->pa;
        node tmp=*((*ptr)->right);
        *((*ptr)->right)=*(*ptr);
        *(*ptr)=tmp;
        if((*ptr)->right!=0)
        ((*ptr)->right)->pa=*(ptr);
        if((*ptr)->left!=0)
        ((*ptr)->left)->pa=*(ptr);
        delete trv;
        trv=0;
    }
    else if((*ptr)->right==0)
    {
        node* trv=*ptr;
        ((*ptr)->left)->pa=(*ptr)->pa;
        node tmp=*((*ptr)->left);
        *((*ptr)->left)=*(*ptr);
        *(*ptr)=tmp;
        if((*ptr)->right!=0)
            ((*ptr)->right)->pa=*(ptr);
        if((*ptr)->left!=0)
            ((*ptr)->left)->pa=*(ptr);
        delete trv;
        trv=0;
    }
    else
    {
        node* key=0;
        if((*ptr)->left!=0)
            key=max(&((*ptr)->left));
        else
            key=pred(ptr,(*ptr)->n);
        int tmp=(*ptr)->n;
        (*ptr)->n=key->n;
        key->n=tmp;
        del(&key);
    }
}