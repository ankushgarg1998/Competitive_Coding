#include <iostream>
#include<math.h>
using namespace std;
int main() {
    long int factors[100000], N, i, price, sq, x, q, A, k;
    cin>>N;
    for(i=0; i<N; i++)
        {
        cin>>price;
        sq = sqrt(price);
        for(x=1; x<sq; x++)
            {
            if(price%x == 0)
                {
                ++factors[x];
                ++factors[price/x];
                }
            }
        if(price%sq==0)
            ++factors[sq];
        }
    cin>>q;
    while(q--)
        {
        cin>>A>>k;
        cout<<factors[A];
        if(factors[A] == k)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        }
    
}

