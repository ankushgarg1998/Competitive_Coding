#include<iostream>
#include<climits>
#define N 5
using namespace std;

int arr[N]; // Stores the Input Array
int tree[4*N + 1]; // stores Segment Tree

void buildTree(int index, int s, int e)
    {
    if(s == e)
        {
        tree[index] = arr[s];
        return;
        }
    
    int mid = (s+e)/2;
    buildTree(2*index, s, mid);
    buildTree(2*index + 1, mid+1, e);
    
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    }

int query(int index, int s, int e, int rs, int re)
    {
    // No Overlapping
    if(re<s || e<rs)
        return INT_MAX;

    // Complete Overlapping
    if(s>=rs && e<=re)
        return tree[index];

    // Partial Overlapping
    int mid = (s+e)/2;
    return min(query(2*index, s, mid, rs, re), query(2*index + 1, mid+1, e, rs, re));
    }

void updateNode(int index, int s, int e, int i, int val)
    {
    if(i<s || i>e)
        return;

    if(s == e)
        {
        tree[index] = val;
        return;
        }

    int mid = (s+e)/2;
    updateNode(2*index, s, mid, i, val);
    updateNode(2*index + 1, mid+1, e, i, val);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    }

void updateRange(int index, int s, int e, int rs, int re, int inc)
    {
    if(re<s || e<rs)
        return;
    
    if(s==e)
        {
        tree[index] += inc;
        return;
        }

    int mid = (s+e)/2;
    updateRange(2*index, s, mid, rs, re, inc);
    updateRange(2*index + 1, mid+1, e, rs, re, inc);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
    }

int main()
    {
    int a, b, q, x;

    cout<<"Enter the Elements : \n";
    for(int i=0; i<N; i++)
        cin>>arr[i];
    buildTree(1, 0, N-1);

    // for(int i=0; i<4*N; i++)
    //     cout<<tree[i]<<" ";
    
    cout<<"Enter no. of queries : ";
    cin>>q;
    cout<<"Enter queries : \n";
    while(q--)
        {
        cin>>a>>b;
        cout<<query(1, 0, N-1, a, b);
        }

    return 0;
    }