#include <bits/stdc++.h>
using namespace std;
#include<map>
void using_map();
int main()
{
    int n,price[10],qua[10];
    cout<<"Number of inputs : ";
    cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>qua[i]>>price[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(qua[i] <= 100)
        {
            cout<<qua[i]*price[i]<<endl;
        }
        else
        {
            cout<<qua[i]*price[i]*(0.8)<<endl;
        }
    }
}

void using_map()
{
    int n,num1,num2;
  map<int , int> m; // quantity price
  cout<<"Number of inputs : ";
    cin>>n;
      for(int i = 0 ; i < n ; i++)
      {
          cin>>num1>>num2;
        m.insert(make_pair(num1,num2));
      }
      for(auto it = m.begin() ; it != m.end() ; it++)
      {
          if(it->first <= 100)
          {
              cout<<it->first*it->second<<endl;
          }
          else
          {
              it->second = it->second*(0.8);
              cout<<it->first*it->second<<endl;
          }
          cout<<(*it).first<<" "<<(*it).second;
      }
}
