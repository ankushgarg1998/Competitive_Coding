#include<bits/stdc++.h>
#define lli long long int
#define li long int
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
    int n, k, a[5][55], carsLeft=0, moves[20000][3], moveCount=0, car[110]={0}, occupied[110]={0};
    map<int, int> parkingLots, cars;
    cin>>n>>k;
    loop(i, 0, 4) {
        loop(j, 1, n+1) {
            cin>>a[i][j];
            if(a[i][j] != 0) {
                if(i == 0) {
                    parkingLots.insert(make_pair(a[i][j], j));
                    ++carsLeft;
                    car[a[i][j]] = 1;
                } else if(i == 3) {
                    parkingLots.insert(make_pair(a[i][j], (2*n)-j+1));
                    ++carsLeft;
                    car[a[i][j]] = 1;
                } else if(i == 1) {
                    cars.insert(make_pair(a[i][j], j));
                    occupied[j] = 1;
                } else if(i == 2) {
                    cars.insert(make_pair(a[i][j], (2*n)-j+1));
                    occupied[(2*n)-j+1] = 1;
                }
            }
        }
    }
    
    while(carsLeft !=0) {
        for(auto x: cars) {
            if(car[x.first] == 1) {
                if(parkingLots[x.first] == x.second) {
                    moves[moveCount][0] = x.first;
                    moves[moveCount][1] = x.second <= n ? 1: 4;
                    moves[moveCount][2] = x.second <= n ? x.second: (2*n)-x.second+1;
                    ++moveCount;
                    --carsLeft;
                    car[x.first] = 0;
                    occupied[x.second] = 0;
                }
            }
        }

        if(carsLeft == 2*n) {
            cout<<"-1\n";
            break;
        }

        for(auto& x: cars) {
            if(car[x.first] == 1) {
                int nextPos = x.second+1;
                if(nextPos != 2*n)
                    nextPos %= (2*n);
                if(occupied[nextPos] == 0) {
                    occupied[x.second] = 0;
                    occupied[nextPos] = 1;
                    x.second = nextPos;
                    moves[moveCount][0] = x.first;
                    moves[moveCount][1] = x.second <= n ? 2 : 3;
                    moves[moveCount][2] = x.second <= n ? x.second : (2*n)-x.second+1;
                    ++moveCount;
                }
            }
        }
    }

    if(carsLeft == 0) {
        cout<<moveCount<<"\n";
        loop(i, 0, moveCount) {
            cout<<moves[i][0]<<" "<<moves[i][1]<<" "<<moves[i][2]<<"\n";
        }
    }
    return 0;
}