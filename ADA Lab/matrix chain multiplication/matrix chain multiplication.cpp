#include<bits/stdc++.h>
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int m[100][100], s[100][100];
void print(int i, int j) {
    if(i == j)
        cout<<(char)(65+i);
    else {
        cout<<"(";
        print(i, s[i][j]);
        print(s[i][j]+1, j);
        cout<<")";
    }
}
int main()
    {
    int p[] = {5, 4, 6, 2, 7}, n=4;
    init(m, -1); init(s, -1);
    loop(i, 0, n)
        m[i][i] = 0;
    loop(l, 1, n) {
        loop(i, 0, n-l) {
            int j = i+l;
            m[i][j] = INT_MAX;
            loop(k, i, j) {
                int q = m[i][k] + m[k+1][j] + (p[i]*p[k+1]*p[j+1]);
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout<<"Ans: ";
    print(0, n-1);
    }