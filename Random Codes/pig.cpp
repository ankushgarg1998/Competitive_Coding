#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	    {
	    int i;
	    bool ch[10];
	    for(i=0; i<10; i++)
	        {
	        ch[i]=false;
	        }
	        
	    string N;
	    cin>>N;
	    int size = strlen(N);
	    
	    for(i=0; i<size; i++)
	        {
	        ch[(N[i]-'0')]=true;
	        }
	        
	    }
	return 0;
}
