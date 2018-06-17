#include<iostream>
#include<climits>
using namespace std;

long long int arr[50005];
struct Tree
    {
    long long int prefix, suffix, maxsum, total; 
    };
Tree tree[200021];

void buildTree(long long int i, long long int s, long long int e)
    {
    if(s==e)
        {
        tree[i].prefix = arr[s];
        tree[i].suffix = arr[s];
        tree[i].maxsum = arr[s];
        tree[i].total = arr[s];
        return;
        }

    long long int mid = (s+e)/2;
    buildTree(2*i, s, mid);
    buildTree(2*i + 1, mid+1, e);
    tree[i].prefix = max(tree[2*i].total + tree[2*i + 1].prefix, tree[2*i].prefix);
    tree[i].suffix = max(tree[2*i].suffix + tree[2*i + 1].total, tree[2*i + 1].suffix);
    tree[i].maxsum = max(tree[2*i].suffix + tree[2*i + 1].prefix, max(tree[2*i].maxsum, tree[2*i + 1].maxsum));
    tree[i].total = tree[2*i].total + tree[2*i + 1].total;
    }

Tree query(long long int i, long long int s, long long int e, long long int rs, long long int re)
    {
    Tree t;
    if(re<s || e<rs)
        {
        t.prefix = t.suffix = t.maxsum = INT_MIN;
        t.total = 0;
        return t;
        }
    
    if(rs<=s && e<=re)
        return tree[i];

    long long int mid = (s+e)/2;
    Tree t1 = query(2*i, s, mid, rs, re);
    Tree t2 = query(2*i + 1, mid+1, e, rs, re);
    t.prefix = max(t1.prefix, t1.total + t2.prefix);
    t.suffix = max(t2.suffix, t1.suffix + t2.total);
    t.maxsum = max(max(t1.maxsum, t2.maxsum), t1.suffix + t2.prefix);
    t.total = t1.total + t2.total;
    return t;
    }

int main()
    {
    long long int n, q, a, b;
    Tree ans;
    cin>>n;

    for(long long int i=0; i<n; i++)
        cin>>arr[i];
    
    buildTree(1, 0, n-1);

    cin>>q;
    while(q--)
        {
        scanf("%lld %lld", &a, &b);
        ans = query(1, 0, n-1, a-1, b-1);
        printf("%lld\n", ans.maxsum);
        }
    return 0;
    }