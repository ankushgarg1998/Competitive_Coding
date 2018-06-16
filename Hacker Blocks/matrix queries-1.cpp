#include<iostream>
using namespace std;

int r, n;
class matr
    {
    public:
        int a, b, c, d;

        matr()
            {}

        matr(int p, int q, int r, int s)
            {
            a = p;
            b = q;
            c = r;
            d = s;
            }

        void print()
            {
            cout<<a<<" "<<b<<"\n"<<c<<" "<<d<<"\n\n";
            }

        matr operator * (const matr& m)
            {
            matr res;
            res.a = (a*m.a + b*m.c)%r;
            res.b = (a*m.b + b*m.d)%r;
            res.c = (c*m.a + d*m.c)%r;
            res.d = (c*m.b + d*m.d)%r;
            return res;
            }

        void operator = (const matr& m)
            {
            a = m.a;
            b = m.b;
            c = m.c;
            d = m.d;
            }
    };
matr mat[100002];
matr tree[400009];
matr I(1, 0, 0, 1);

void buildTree(int i, int s, int e)
    {
    if(s==e)
        {
        tree[i] = mat[s];
        return;
        }

    int mid = (s+e)/2;
    buildTree(2*i, s, mid);
    buildTree(2*i + 1, mid+1, e);
    tree[i] = tree[2*i] * tree[2*i + 1];
    }

matr query(int i, int s, int e, int rs, int re)
    {
    if(re<s || e<rs)
        return I;

    if(s>=rs && e<=re)
        return tree[i];

    int mid = (s+e)/2;
    return query(2*i, s, mid, rs, re) * query(2*i + 1, mid+1, e, rs, re);
    }

int main()
    {
    int a, b, q;
    cin>>r>>n>>q;
    for(int i=0; i<n; i++)
        cin>>mat[i].a>>mat[i].b>>mat[i].c>>mat[i].d;

    buildTree(1, 0, n-1);
    while(q--)
        {
        cin>>a>>b;
        matr m = query(1, 0, n-1, a-1, b-1);
        m.print();
        }
    return 0;
    }