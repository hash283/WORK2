// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"
typedef struct node
{
    bool x;
    struct node *next[27];
}
node;
node *root=NULL;
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node* ptr=root;
    int ch;
    int length=strlen(word);
    for(int i=0;i<length;i++)
    {
        if(word[i]=='\'')
            ch=26;
        else
            ch=(tolower(word[i]))-97;
        if(ptr->next[ch]==NULL)
            return false;
        else
        {
            ptr=ptr->next[ch];
        }
    }
    if(ptr->x)
        return true;
    else
        return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    root=malloc(sizeof(node));
    if(root==NULL)
        return false;
    for(int i=0;i<27;i++)
    {
            root->next[i]=NULL;
    }
    root->x=false;
    FILE* infile=fopen(dictionary,"r");
    if(infile==NULL)
        return false;
    else
    {
        char word[LENGTH+1];
        while(fscanf(infile,"%s",word)!=EOF)
            {
                int ch;
                node* ptr=root;
                int length=strlen(word);
                for(int i=0;i<length;i++)
                {
                    if(word[i]=='\'')
                        ch=26;
                    else
                        ch=word[i]-97;
                    if(ptr->next[ch]==NULL)
                    {
                        node* a=malloc(sizeof(node));
                        if(a==NULL)
                            return false;
                        for(int j=0;j<27;j++)
                        {
                            a->next[j]=NULL;
                        }
                        a->x=false;
                        ptr->next[ch]=a;
                    }
                    ptr=ptr->next[ch];
                }
                ptr->x=true;
            }
        fclose(infile);
        return true;
    }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    node* ptr=root;
    node* ar[46];
    for(int i=0;i<46;i++)
    {
        ar[i]=NULL;
    }
    int count[46];
    ar[0]=root;
    int i=0,word=0,c=0,k=0;
    while(true)
    {
        if(i>=27)
        {
            if(ptr==root)
                break;
            else
            {
                ptr=ar[c-1];
                c--;
                i=(count[k-1]+1);
                k--;
            }
        }
        else if(ptr->next[i]==NULL)
            i++;
        else
        {
            ptr=ptr->next[i];
            count[k]=i;
            k++;
            i=0;
            c++;
            if(ptr->x==true)
                word++;
            ar[c]=ptr;
        }
    }
    return word;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node* ar[46];
    for(int i=0;i<46;i++)
    {
        ar[i]=NULL;
    }
    node *ptr=root;
    ar[0]=root;
    int count[46];
    int i=0,c=0,k=0;
    while(true)
    {
        if(i>=27)
        {
            if(ptr==root)
            {
                free(ptr);
                break;
            }
            free(ptr);
            c--;
            ptr=ar[c];
            i=(count[k-1]+1);
            k--;
        }
        else if((ptr->next[i])==NULL)
            i++;
        else
        {
            ptr=ptr->next[i];
            count[k]=i;
            k++;
            c++;
            ar[c]=ptr;
            i=0;
        }
    }
    return true;
}
