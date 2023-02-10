#include<iostream>
#include<deque>
using namespace std;

int main()
  {
  int T;
  cin>>T;
  for(int t=0;t<T;t++)
    {
    char in;
    deque <char> q;
    deque <char> check;
    cin>>in;
    while(in != '\n')
      {
      q.push_back(in);
      check.push_back(in);
      in = cin.get();
      }
      int count=0, x, i;// size = q.size();
    do
      {
      ++count;
      // int h = count%size;
      for(x=1; x<=count; x++)
        {
        q.push_back(q.front());
        q.pop_front();
        }

      deque<char>::iterator it1 = q.begin();
      deque<char>::iterator it2 = check.begin();
      deque<char>::iterator it1e = q.end();
      while(it1 != it1e)
        {
        // cout<<*it1<<" "<<*it2<<"\n";
        if((*it1++) != (*it2++))
          {
          // cout<<"\n-\n";
          break;
          }
        }
      if(it1 == it1e)
        {
        cout<<count<<"\n";
        break;
        }
      }while(1);
    }
  return 0;
  }
