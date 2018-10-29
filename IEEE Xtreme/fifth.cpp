#include <bits/stdc++.h>
#include <cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
int main() {
    map<string, vector<int> > data;
    int n;
    string str;
    cin>>n;
    cin.ignore();
    loop(i, 0, n) {
        getline(cin, str);
        int x = str.find("full_name");
        x += 13;
        string name = "";
        while(true) {
            if(str[x] == '"')
                break;
            name += str[x];
            ++x;
        }
        cout<<"\n\n"<<name<<" ";
        int y = str.find("citing_paper_count");
        y += 21;
        cout<<str[y]<<"\n";
    }
    return 0;
}