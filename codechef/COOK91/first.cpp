#include<iostream>
#define test int t; cin>>t; while(t--)
using namespace std;
int main()
    {
    int sum, i, x;
    string arr[6] = {"Beginner", "Junior Developer", "Middle Developer", "Senior Developer", "Hacker", "Jeff Dean"};
    test
        {
        sum = 0;
        for(i=0; i<5; i++)
            {
            cin>>x;
            sum += x;
            }
        cout<<arr[sum]<<"\n";
        }
    return 0;
    }