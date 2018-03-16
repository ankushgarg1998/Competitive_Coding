#include <iostream>
using namespace std;

string X;
char S[10];
int n;
bool present;

bool find(int x)
    {
    for(int i=0; i<n; i++)
        {
        if(S[i] == x)
            return true;
        }
    return false;
    }

int main()
    {
    int i, beg, now, endd, ans=0;
    cin>>X>>n;
    for(i=0; i<n; i++)
        cin>>S[i];
    for(i=0; i<X.size(); i++)
        {
        beg = i;
        if(find(X[i]))
            {
            ++i;
            while(X[i] && find(X[i]))
                ++i;
            --i;
            endd = i;
            now = endd - beg + 1;
            ans += ((now)*(now+1)/2);
            }
        }
    cout<<ans;
    return 0;
    }
