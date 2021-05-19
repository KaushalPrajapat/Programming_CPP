#include <bits/stdc++.h>
using namespace std;

int main()
{
  int cases,st_num[10],seq[10];
  cout<<"Number of cases ";
  cin>>cases;
  for(int i=0;i<cases;i++)
  {
    cin>>st_num[i];
  }

    for(int i=0;i<cases;i++)
  {
    int z=st_num[i];
    while(z>1)
    {
        cout<<z<<" ";
        if(z%2==0)
        {
            //cout<<z<<" ";
            z=sqrt(z);
        }
        else
        {
            //cout<<z<<" ";
            z=z*sqrt(z);
        }

    }
    cout<<"1"<<endl;


  }


  //for(int i=0;i<cases;i++)
  //{
  //  cout<<st_num[i]<<" ";
  //}

  return 0;
}
