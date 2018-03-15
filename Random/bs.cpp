#include<iostream>
#include<vector>
using namespace std;

int bs(long int arr[], long int n)
    {
    return -1;
    }

int main() {
	long int N, arr[], M;
  cin>>N;
	for(long int i=0; i<N; i++)
	    cin>>arr[i];
	cin>>M;
	cout<<bs(arr, M);
	return 0;
}
