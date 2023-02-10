#include <iostream>
using namespace std;
int main()
    {
    int n, a, even=0, odd=0;
    cin>>n;
    while(n--)
        {
        cin>>a;
        if(a&1)
            ++odd;
        else
            ++even;
        }
    if(even > odd)
        cout<<"READY FOR BATTLE\n";
    else
        cout<<"NOT READY\n";
    return 0;
    }
