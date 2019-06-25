#include<iostream>
using namespace std;
int main()
    {
    int t, arr[1300]={0};
    cin>>t;
    for(int i=0; i<50; i++)
        {
        arr[(i*(i+1))/2] = i;
        }
    int base = 0;
    for(int i=0; i<=50; i++)
        {
        if(arr[i] == 0)
            arr[i] = base;
        else
            base = arr[i];
        }
    for(int i=0; i<20; i++)
        cout<<arr[i]<<" ";
    // for(int test=1; test<=t; test++)
    //     {
    //     int r, b;
    //     cin>>r>>b;
    //     cout<<"Case #"<<test<<": "<<test<<"\n";
    //     }
    return 0;
    }