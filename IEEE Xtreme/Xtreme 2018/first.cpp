#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))

using namespace std;

string in, pre;
char ch[90][90];
int rightest=0;
int downest=0;

void tree(int ina, int inb, int prea, int preb, unordered_map<char, int> &mp, int i, int j) {
    // cout<<ina<<" "<<inb<<" "<<prea<<" "<<preb<<":\n";
    if(ina>inb || prea > preb)
        return;
    char x = pre[prea];
    int left = mp[x] - ina;
    int right = inb - mp[x];
    ch[j][i+left] = x;
    rightest = max(rightest, i+left);
    downest = max(downest, j);
    // cout<<j<<" "<<i+left<<" "<<x<<"\n";
    tree(ina, mp[x]-1, prea+1, prea+left, mp, i, j+1);
    tree(mp[x]+1, inb, prea+left+1, preb, mp, i+left+1, j+1);
}

void buildTree(int a, int len) {
    unordered_map<char, int> mp;
    loop(i, 0, len) {
        mp[in[i]] = i;
        // cout<<in[i]<<" "<<i<<"\n";
    }
    tree(0, len-1, 0, len-1, mp, 0, 0);
}

int main() {
    while(cin>>in>>pre) {
        init(ch, ' ');
        buildTree(0, in.size());
        
        loop(i, 0, downest+1) {
            loop(j, 0, rightest+1)
                cout<<ch[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}