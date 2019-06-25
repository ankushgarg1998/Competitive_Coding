#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    int n=4;
    int burst_time[] = {5, 7, 8, 2}, arrival_time[] = {2, 1, 0, 3}, wait_time[n], tat[n];

    pair<int, int> p[n];
    loop(i, 0, n)
        p[i] = make_pair(arrival_time[i], i);

    sort(p, p+n);

    cout<<"Process\t\tExecution-Time\t\tWait-Time\tTuraround-Time\n";
    int wt = p[0].first;
    loop(i, 0, n) {
        cout<<"  "<<p[i].second+1<<"\t\t\t"<<burst_time[p[i].second]<<"\t\t"<<wt<<"\t\t"<<wt+burst_time[p[i].second]<<"\n";
        wt += burst_time[p[i].second];
    }

    return 0;
}