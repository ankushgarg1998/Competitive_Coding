#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

map<int, vector<int> > mp;
vector<bool> banks(100001);
vector<int> possible;

void answer(int C, int where, bool incl)
    {
    if(incl)
        {
        possible.push_back(C);
        for(auto a:mp[C])
            {
            if(a != where)
                answer(a, C, true);
            }
        }
    else
        {
        for(auto a:mp[C])
            {
            if(a != where)
                {
                if(banks[a])
                    answer(a, C, true);
                else
                    answer(a, C, false);
                }
            }
        }
    }
int main()
    {
    int t, N, M, i, U, V, ty, C, firstmax, secondmax;
    scanf("%d", &t);
    while(t--)
        {
        scanf("%d%d", &N, &M);
        mp.clear();
        // banks.clear();
        // possible.clear();
        for(i=0; i<=N; i++)
            banks[i]=false;
        for(i=0; i<N-1; i++)
            {
            scanf("%d%d", &U, &V);
            mp[U].push_back(V);
            mp[V].push_back(U);
            }
        // for(auto x:mp)
        //     {
        //     cout<<x.first<<" : [";
        //     for(auto y:x.second)
        //         cout << y <<", ";
        //     cout<<"\b\b]\n";
        //     }
        while(M--)
            {
            scanf("%d%d", &ty, &C);
            if(ty==1)
                banks[C] = true;
            else
                {
                possible.clear();
                if(banks[C])
                    answer(C, 0, true);
                else
                    answer(C, 0, false);

                // cout<<"SET : ";
                // for(auto y:possible)
                //     cout<<y<<" ";
                // cout<<"\n";

                int si = possible.size();
                if(si <= 1)
                    printf("-1\n");
                else
                    {
                    firstmax = possible[0];
                    secondmax = possible[1];
                    for(i=1; i<si; i++)
                        {
                        if(possible[i] > firstmax)
                            {
                            secondmax = firstmax;
                            firstmax = possible[i];
                            }
                        else if(possible[i] > secondmax)
                            {
                            secondmax = possible[i];
                            }
                        }
                    printf("%d\n", secondmax);
                    // sort(possible.begin(), possible.end());
                    // cout<<possible[si-2]<<"\n";
                    }
                }
            }
        }
    return 0;
    }
