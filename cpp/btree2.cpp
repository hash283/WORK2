#include<iostream>
struct node
{
    int n;
    node *left,*right,*pa;
};
node *root=0;
void insert(int x,node **ptr);
void print(node** ptr);
using namespace std;
int main()
{
    int x;
    cout<<"Insert nos\n";
    cin>>x;
    insert(x,&root);
    node *ptr=root;
    while(cin>>x)
    {
        insert(x,&ptr);
        ptr=root;
    }
    print(&ptr);
}
void insert(int x,node **ptr)
{
    static node* t=0;
    if(*ptr==0)
    {
        node *tm=new node;
        tm->n=x;
        tm->left=0;
        tm->right=0;
        tm->pa=t;
        *ptr=tm;
    }
    else if(x<(*ptr)->n)
    {
        t=*ptr;
        insert(x,&((*ptr)->left));
    }
    else
    {
        t=*ptr;
        insert(x,&((*ptr)->right));
    }
}
void print(node** ptr)
{
    if((*ptr)->left!=0)
        print(&((*ptr)->left));
    cout<<(*ptr)->n<<endl;
    if((*ptr)->right!=0)
        print(&((*ptr)->right));
}