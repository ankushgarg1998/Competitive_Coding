#include<iostream>
using namespace std;

int count=0;

void move(int x, int t1, int t2)
    {
    cout<<"Move "<<x<<"th disc from T"<<t1<<" to T"<<t2<<"\n";
    ++count;
    }

void hanoi(int f, int n, int t1, int t2, int t3)
    {
    if(n==1)
        move(f, t1, t2);
    else
        {
        hanoi(f, n-1, t1, t3, t2);
        move(n, t1, t2);
        hanoi(f, n-1, t3, t2, t1);
        }
    }

int main()
    {
    int n;
    cin>>n;
    hanoi(1, n, 1, 2, 3);
    cout<<count;
    return 0;
    }
