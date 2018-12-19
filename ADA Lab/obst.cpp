#include <iostream>
#include <climits>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int freq_sum(int freq[], int i, int j) {
    int sum = 0;
    loop(a, i, j)
        sum += freq[a];
    return sum;
}

int obst(int freq[], int keys[], int n) {
    int cost[n+1][n+1];
    loop(i, 0, n+1)
        cost[i][i] = 0;
    loop(l, 1, n+1) {
        loop(i, 0, n-l+1) {
            int j = i+l;
            cost[i][j] = INT_MAX;
            loop(k, i, j) {
                int c = cost[i][k] + cost[k+1][j];
                cost[i][j] = min(cost[i][j], c);
            }
            cost[i][j] += freq_sum(freq, i, j);
        }
    }
    loop(i, 0, n+1) {
        loop(j, 0, n+1)
            cout<<cost[i][j]<<" ";
        cout<<"\n";
    }
    return cost[0][n-1];
}

int main() {
    int n = 4;
    int freq[] = {4, 2, 6, 3};
    int keys[] = {10, 20, 30, 40};

    cout<<obst(freq, keys, n);
    return 0;
}