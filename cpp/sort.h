#ifndef SORT_H
#define SORT_H
#include<iostream>
struct point
{
    int x;
    int y;
};

void sortx(point ar[],int sp,int ep);

void sorty(point ar[],int sp,int ep);

void mergex(point ar[],int sp,int mp,int ep);

void mergey(point ar[],int sp,int mp,int ep);
#endif