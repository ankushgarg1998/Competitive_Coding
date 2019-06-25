// Branch and bound Algorithm - Assignment Problem.

#include<iostream>
#include<climits>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int n, m;
int a[30][30];

struct format {
    int cost;
    int index;
};

format func(int r, string s) {
    int minax = INT_MAX, minai = 0;
    string s_copy = s;
    format f;
    loop(i, 1, n) {
        if(s[i] == '0') {
            s[i] = '1';
            int ans = a[r][i];
            loop(j, r+1, m) {
                // cout<<i<<" "<<j<<" "<<s<<"\n";
                int minx = INT_MAX;
                int mini = 0;
                loop(k, 1, n) {
                    // cout<<"->"<<i<<" "<<j<<" "<<k<<" "<<s<<"\n";
                    if(s[k] == '0' && a[j][k] < minx) {
                        minx = a[j][k];
                        mini = k;
                    }
                }
                ans += minx;
                s[mini] = '1';
            }
            if(ans < minax) {
                minax = ans;
                minai = i;
            } else if(ans == minax && r != m) {
                // cout<<"Bingo\n";
                string str = s_copy;
                str[minai] = '1';
                format z1 = func(r+1, str);
                str[minai] = '0';
                str[i] = '1';
                format z2 = func(r+1, str);
                // cout<<z1.cost<<" "<<z1.index<<"\n";
                // cout<<z2.cost<<" "<<z2.index<<"\n";
                if(z1.cost > z2.cost) {
                    minax = ans;
                    minai = i;
                }
                // cout<<minax<<" "<<minai<<"\n";
            }
            // s[i] = '0';
            s = s_copy;
        }
    }
    f.index = minai;
    f.cost = minax;
    return f;
}

int main() {
    cin>>n>>m;
    ++n; ++m;
    int assignments[30], maxnum = 0;
    loop(i, 1, m) {
        loop(j, 1, n) {
            cin>>a[i][j];
            if(a[i][j] > maxnum)
                maxnum = a[i][j];
        }
    }
    // For Maximizing
    loop(i, 1, m) {
        loop(j, 1, n) {
            a[i][j] = maxnum - a[i][j];
        }
    }
    string s = "000000000000000000000000000000";
    loop(i, 1, m) {
        format c = func(i, s);
        assignments[i] = c.index;
        s[assignments[i]] = '1';
        cout<<assignments[i]<<" ";
    }
    return 0;
}