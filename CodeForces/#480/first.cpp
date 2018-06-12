#include<iostream>
using namespace std;
int main()
    {
    string s;
    cin>>s;
    int pearl=0, link=0;
    for(char a: s)
        {
        if(a == 'o')
            ++pearl;
        else
            ++link;
        }
    // if(pearl == 0 || link%pearl == 0 ) //||link == 0 || pearl == 1)
    //     cout<<"YES\n";
    // else
    //     cout<<"NO\n";
    // if(pearl == 0)
    //     cout<<"y";
    // if(link == 0)
    //     cout<<"y";
    // if(link&1)
    //     cout<<"n";

    int i=2;
    while(pearl*i<link){
        i+=2;
    }
    if(pearl*i==link)
        cout<<"y";
    else
        cout<<"no";
    
    return 0;
    }