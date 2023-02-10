#include<iostream>
#include<cstdlib>
#include<vector>
typedef long long int ll;
using namespace std;

int correctSolver(vector <int> a, int N) {
  int min = a[0], i;
  int ind = 0;
  for(i=0; i<N; i++)
      {
      if(a[i]==1)
          {
          ind = i;
          break;
          }
      if(a[i]<min)
          {
          min = a[i];
          ind = i;
          }
      }
  return ind+1;
}

int wrongSolver(vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
    // cout<<prefSum[i]<<" ";
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}

int main()
    {
    int t;
    ll n, i, ans = 100000, x, a;
    cin>>t;
    while(t--)
        {
        cin>>n;
        vector<int> v;
        vector<unsigned int> v2;
        // for(i=0; i<n; i++)
        //     {
            // x = rand()%10;
            // cout<<ans-x<<" ";
            // v.push_back(ans);
            // v2.push_back(ans);
            // }


        for(i=1; i<=42949; i++)
            {
            // cout<<ans<<" ";
            v.push_back(ans);
            v2.push_back(ans);
            }
        // cout<<67296<<" ";
        v.push_back(67296);
        v2.push_back(67296);
        for(i=1; i<=42949; i++)
            {
            // cout<<ans<<" ";
            v.push_back(ans);
            v2.push_back(ans);
            }
        a = n - 85899;
        while(a--)
            {
            // cout<<"0 ";
            v.push_back(1);
            v2.push_back(1);
            }

        cout<<"\n";
        cout<<"Correct Ans: "<<correctSolver(v, n)<<"\n";
        cout<<"Wrong Ans: "<<wrongSolver(v2);
        }
    return 0;
    }
