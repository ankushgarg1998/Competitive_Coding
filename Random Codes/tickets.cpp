#include<iostream>
#include <string>
using namespace std;

struct inp
  {
  string a;
  string b;
  inp *next;
}*inpHEAD = NULL, *inpTEMP, *inpCOUNT;

struct ans
  {
  string info;
  ans *next;
}*ansHEAD = NULL, *ansTEMP, *ansCOUNT;

int main()
  {
  int T;
  cin>>T;
  while(T--)
    {
    int N, i;
    cin>>N;

    inpHEAD = new inp;
    cin>>inpHEAD->a;
    cin>>inpHEAD->b;
    inpHEAD->next = NULL;

    inpCOUNT = inpHEAD;
    for(i=1; i<N; i++)
      {
      inpTEMP = new inp;
      cin>>inpTEMP->a;
      cin>>inpTEMP->b;
      inpTEMP->next = NULL;

      inpCOUNT->next = inpTEMP;
      inpCOUNT = inpTEMP;
      }

    ansHEAD = new ans;
    ansHEAD->info = inpHEAD->a;

    ansTEMP = new ans;
    ansTEMP->info = inpHEAD->b;
    ansTEMP->next = NULL;
    ansHEAD->next = ansTEMP;
    ansCOUNT = ansTEMP;

    string search = inpHEAD->b;
    inpHEAD = inpHEAD->next;

    inpTEMP = inpHEAD;
    inp *previnpTEMP = inpHEAD;
    while(inpTEMP != NULL)
      {
      // cout<<"\ninput a"<<inpTEMP->a;
      if(search == inpTEMP->a)
        {
        // cout<<"\nsearch : "<<search;
        ansTEMP = new ans;
        ansTEMP->info = inpTEMP->b;
        ansTEMP->next = NULL;

        ansCOUNT->next = ansTEMP;
        ansCOUNT = ansTEMP;
        search = inpTEMP->b;

        if(inpTEMP->a == inpHEAD->a)
          inpHEAD = inpHEAD->next;
        else
          previnpTEMP->next = inpTEMP->next;
        inpTEMP = inpHEAD;
        //ans insert
        // inp del
        //re-search
        }
      else
        {
        previnpTEMP = inpTEMP;
        inpTEMP = inpTEMP->next;
        }
      }

    search = ansHEAD->info;
    inpTEMP = inpHEAD;
    previnpTEMP = inpHEAD;
    while(inpTEMP != NULL)
      {
      if(search == inpTEMP->b)
        {
        ansTEMP = new ans;
        ansTEMP->info = inpTEMP->a;
        ansTEMP->next = ansHEAD;
        ansHEAD = ansTEMP;

        search = inpTEMP->a;

        if(inpTEMP->a == inpHEAD->a)
          inpHEAD = inpHEAD->next;
        else
          previnpTEMP->next = inpTEMP->next;
        inpTEMP = inpHEAD;
        }
      else
        {
        previnpTEMP = inpTEMP;
        inpTEMP = inpTEMP->next;
        }
      }
    ansTEMP = ansHEAD;
    while(ansTEMP->next != NULL)
      {
      cout<<ansTEMP->info<<"-"<<ansTEMP->next->info<<" ";
      ansTEMP = ansTEMP->next;
      }
    }
  return 0;
  }
