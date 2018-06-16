// The whole point is to fasten the segment tree range-update

// NOT TESTED
// RANGE SUM
#include<iostream>
#include<climits>
#define N 5
using namespace std;

int arr[N]; // Stores the Input Array
int tree[4*N + 1]; // stores Segment Tree
int lazy[4*N + 1] = {0}; // stores Lazy Values

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
    
    tree[index] = tree[2*index] + tree[2*index + 1];
    }

void lazy_update(int index, int s, int e, int rs, int re, int inc)
    {
    if(lazy[index] != 0)
        {
        tree[index] += (e-s+1)*lazy[index];
        if(s!=e)    
            {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
            }
        lazy[index] = 0;
        }

    if(re<s || e<rs)
        return;
    
    if(rs<=s && e<=re)
        {
        tree[index] += (e-s+1)*inc;
        if(s!=e)
            {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
            }
        return;
        }
    
    int mid = (s+e)/2;
    lazy_update(2*index, s, mid, rs, re, inc);
    lazy_update(2*index + 1, mid+1, e, rs, re, inc);
    tree[index] = tree[2*index] + tree[2*index + 1];
    }

int lazy_query(int index, int s, int e, int rs, int re)
    {
    if(lazy[index] != 0)
        {
        tree[index] += (e-s+1)*lazy[index];
        if(s!=e)    
            {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
            }
        lazy[index] = 0;
        }

    if(re<s || e<rs)
        return INT_MAX;
    
    if(rs<=s && e<=re)
        return tree[index];

    int mid = (s+e)/2;
    return lazy_query(2*index, s, mid, rs, re) + lazy_query(2*index + 1, mid+1, e, rs, re);
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
        cout<<lazy_query(1, 0, N-1, a, b);
        }

    return 0;
    }