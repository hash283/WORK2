#include<iostream>
struct node
{
    int n;
    node* left;
    node* right;
};
node *root=0;
void insert(node **ptr,int x);
void print(node **ptr);
using namespace std;
int main()
{
    int x1,x2;
    cout<<"Construct Binary tree"<<endl;
    cin>>x1;
    insert(&root,x1);
    node* ptr=root;
    while(cin>>x2)
    {
        insert(&ptr,x2);
        if(ptr==0)
            cout<<"ptr is nULL"<<endl;
        ptr=root;
        if(ptr==0)
            cout<<"ptr is nULL"<<endl;
    }
    print(&ptr);
}
void insert(node **ptr,int x)
{
    node* head=*ptr;
    if(head==0)
    {
        node* tmp=new node;
        tmp->n=x;
        tmp->left=0;
        tmp->right=0;
        *ptr=tmp;
        return;
    }
    else if(x>head->n)
    {
        insert(&(head->right),x);
        return;
    }
    else if(x<head->n)
    {
        insert(&(head->left),x);
        return;
    }
}
void print(node **ptr)
{
    node *head=*ptr;
    if(head==0)
        {
            cout<<"NULL"<<endl;
            return;
        }
    if((head->left)!=0)
        print(&(head->left));
    cout<<head->n<<endl;
    if((head->right)!=0)
        print(&(head->right));
}