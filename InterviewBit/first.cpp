#include<bits/stdc++.h>
using namespace std;

int main() {
    int A[] = {4, 2, 1, 4};
    map<int, int> m;
    int maxCount = 0, maxNum;
    for(int x: A) {
        ++m[x];
        if(m[x] > maxCount) {
            maxCount = m[x];
            maxNum = x;
        }
    }
    cout<<4-maxCount;
}