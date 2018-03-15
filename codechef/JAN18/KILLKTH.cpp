#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
    {
    string S, temp="";
    bool bre = false;
    char ans;
    long int Q, P, M, G=0, len, K, i, j, k, count;
    vector<string> v;
    cin>>S>>Q;
    len = S.size();
    for(k=0; k<len; k++)
        {
        for(i=k; i<len; i++)
            {
            for(j=k; j<=i; j++)
                {
                temp += S[j];
                }
            v.push_back(temp);
            temp = "";
            }
        }
    sort(v.begin(), v.end());
    for(auto x:v)
        temp += x;
    // cout<<temp<<"\n";
    while(Q--)
        {
        cin>>P>>M;
        K = ((P*G)%M) + 1;
        // cout<<"K= "<<K<<"\n";
        cout<<temp[K-1]<<"\n";
        G += (int)temp[K-1];
        // cout<<"G="<<G<<"\n";
        }
    return 0;
    }
