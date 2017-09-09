#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
        int data;
        node *next;
    };

node *top = NULL;

void push(int x)
{
    node *n = (node*)malloc(sizeof(node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop()
{
    if(top != NULL)
        top = top->next;
}

void max()
{
    int max = top->data;
    node *t = top->next;
    while(t)
    {
        if(max < t->data)
            max = t->data;
        t = t->next;
    }
    cout<<max<<"\n";
}

void printnode()
{
    node *t = top;
    cout<<"Stack : ";
    while(t != NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<"\n";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i, N, type, x;
    cin>>N;
    for(i=0; i<N; i++)
    {
        cin>>type;
        if(type == 1)
            cin>>x;
        switch(type)
        {
            case 1: push(x);
                    break;
            case 2: pop();
                    break;
            case 3: max();
                    break;
        }
        //printnode();
    }
    return 0;
}
