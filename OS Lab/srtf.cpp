#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    int n=4;
    int burst_time[] = {6, 8, 7, 3}, arrival_time[] = {1, 1, 2, 3}, wait_time[n]={0}, tat[n]={0};

    set<pair<int, int> > s;
    loop(i, 0, 100) {
        loop(j, 0, n) {
            if(arrival_time[j] == i)
                s.insert(make_pair(burst_time[j], j));
        }
        if(s.empty())
            continue;
        pair<int, int> p = *(s.begin());
        int x = p.second;
        int t = p.first;
        s.erase(s.begin());
        tat[x] += 1;
        if(t == 1) {
            tat[x] = (i+1) - arrival_time[x];
            wait_time[x] = tat[x] - burst_time[x];
        } else {
            s.insert(make_pair(t-1, x));
        }
    }

    cout<<"Process\t\tArrival-Time\t\tBurst-Time\tWait-Time\tTuraround-Time\n";
    loop(i, 0, n) {
        cout<<"  "<<i<<"\t\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<tat[i]<<"\n";
    }

    return 0;
}