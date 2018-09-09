#include<iostream>
#include<cmath>
#include<cfloat>
#include<utility>
#include"sort.h"
using namespace std;
pair<point,point> p1,p2,ptemp,p3;
float distance(void);
pair<point,point> closestpair(point px[],point py[],int sp,int ep);
pair<point,point> splitpair(point px[],point py[],int n,float dis);
int main()
{
    int n;
    cout<<"Enter the no of points\n";
    cin>>n;
    point px[n],py[n];
    cout<<"Enter the x & y coordinates\n";
    for(int i=0;i<n;i++)
    {
        cin>>px[i].x;
        cin>>px[i].y;
    }
    for(int i=0;i<n;i++)
        py[i]=px[i];
    sortx(px,0,n-1);
    sorty(py,0,n-1);
    pair<point,point> pfinal=closestpair(px,py,0,n-1);
    point pfinal1=pfinal.first,pfinal2=pfinal.second;
    cout<<"closest pair of points are"<<pfinal1.x<<" "<<pfinal1.y<<" & "<<pfinal2.x<<" "<<pfinal2.y;
}
float distance(void)
{
    point pa=p1.first,pb=p1.second,pc=p2.first,pd=p2.second;
    float i=sqrt(pow(pa.x-pb.x,2)+pow(pa.y-pb.y,2));
    float j=sqrt(pow(pc.x-pd.x,2)+pow(pc.y-pd.y,2));
    if(i<j)
    {
        ptemp=p1;
        return i;
    }
    else
    {
        ptemp=p2;
        return j;
    }
}
pair<point,point> closestpair(point px[],point py[],int sp,int ep)
{
    int n=ep-sp+1;
    pair<point,point> p;
    if(n==2)
    {
        p.first=px[sp];
        p.second=px[sp+1];
        return p;
    }
    else if(n==3)
    {
        float min=FLT_MAX;
        for(int i=sp;i<=ep;i++)
        {
            for(int j=i+1;j<=ep;j++)
            {
                float d=sqrt(pow(px[i].x-px[j].x,2)+pow(px[i].y-px[j].y,2));
                if(d<min)
                {
                    min=d;
                    p.first=px[i];
                    p.second=px[j];
                }
            }
        }
        return p;
    }
    else
    {
        int mp=(sp+ep)/2;
        p1=closestpair(px,py,sp,mp);
        p2=closestpair(px,py,mp+1,ep);
        float dis=distance();
        p3=splitpair(px,py,n,dis);
        pair<point,point> pfinal=p3;
        return pfinal;
    }
}
pair<point,point> splitpair(point px[],point py[],int n,float dis)
{
    pair<point,point> p=ptemp;
    point temp[n];
    int mp=(n-1)/2,c=0,k=0;
    int x=px[mp].x;
    float best=dis,min=x-dis,max=x+dis;
    while(c<n)
    {
        if((py[c].x)>=min && (py[c].x)<=max)
            {
                temp[k]=py[c];
                k++;
            }
        c++;
    }
    point sy[k];
    for(int i=0;i<k;i++)
        sy[i]=temp[i];
    for(int i=0;i<k-1;i++)
    {
        int l=k-i-1;
        if(l>7)
            l=7;
        for(int j=1;j<=l;j++)
        {
            float d=sqrt(pow(sy[i].x-sy[i+j].x,2)+pow(sy[i].y-sy[i+j].y,2));
            if(d<best)
            {
                best=d;
                p.first=sy[i];
                p.second=sy[i+j];
            }
        }
    }
    return p;
}