#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
string a[1000];
int n, m, p, q;
string moves[] = {"", "R\n", "U\n", "D\n", "L\n"};

bool possibleMove(int mov, int i, int j) {
    if(mov == 1) {
        if(j+2 < (2*m)+1 && a[i][j+1] != '#')
            return true;
    } else if(mov == 2) {
        if(i-2 >= 0 && a[i-1][j] != '#')
            return true;
    } else if(mov == 3) {
        if(i+2 <= (2*n)+1 && a[i+1][j] != '#')
            return true;
    } else {
        if(j-2 >= 0 && a[i][j-1] != '#')
            return true;
    }
    return false;
}

void run(int p, int q, int mov) {
    // cout<<p<<" "<<q<<" "<<mov<<"\n";
    string str;
    loop(i, 1, 5) {
        if(mov != (5-mov)) {
            if(possibleMove(i, p, q)) {
                if(i == 1) {
                    cout<<moves[i];
                    cin>>str;
                    if(str.size() > 1)
                        exit(0);
                    run(p, q+2, 1);
                } else if(i == 2) {
                    cout<<moves[i];
                    cin>>str;
                    if(str.size() > 1)
                        exit(0);
                    run(p-2, q, 2);
                } else if(i == 3) {
                    cout<<moves[i];
                    cin>>str;
                    if(str.size() > 1)
                        exit(0);
                    run(p+2, q, 3);
                } else {
                    cout<<moves[i];
                    cin>>str;
                    if(str.size() > 1)
                        exit(0);
                    run(p, q-2, 4);
                }
            }
        }
    }
    if(possibleMove(mov, p, q)) {
        int i = mov;
        if(i == 1) {
            cout<<moves[i];
            cin>>str;
            if(str.size() > 1)
                exit(0);
            run(p, q+2, 1);
        } else if(i == 2) {
            cout<<moves[i];
            cin>>str;
            if(str.size() > 1)
                exit(0);
            run(p-2, q, 2);
        } else if(i == 3) {
            cout<<moves[i];
            cin>>str;
            if(str.size() > 1)
                exit(0);
            run(p+2, q, 3);
        } else {
            cout<<moves[i];
            cin>>str;
            if(str.size() > 1)
                exit(0);
            run(p, q-2, 4);
        }
    }
}

int main() {
    cin>>n>>m;
    loop(i, 0, (2*n)+1) {
        cin>>a[i];
        loop(j, 0, (2*m)+1)
            if(a[i][j] == '1') {
                p = i;
                q = j;
                break;
            }
    }

    run(p, q, 1);
    // string s;
    // while(true) {
    //     cout<<"W\n";
    //     cin>>s;
    //     if(s.size() == 2)
    //         break;
    // }
    return 0;
}