// Kaushal Prajapat 17.05.2021
// Pattern Creation
// Pattern

//1        1
//12      21
//123    321
//1234  4321
//1234554321



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of rows to print : (<10)";
  cin>>n;


  for(int i = 1 ; i <= n ; i++)
  {
      int x = 1;
    for(int j = 1 ; j <= 2*n - 1; j++)
    {
        if(i>=j)
        {
          cout<<x++;
        }
        else if(i>=2*n-j)
        {
            cout<<--x;
        }
        else
        {
          cout<<" ";
        }
    }
    cout<<endl;
  }



  return 0;
}
