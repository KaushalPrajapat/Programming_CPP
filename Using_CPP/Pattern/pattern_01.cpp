#include<iostream>

using namespace std;

int pattern()
{
    int row;
    cout<<"Enter, Rows! ";
    cin>>row;
    for(int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j <= i ; j++)
        {
            cout<<char(65+i)<<" ";
        }
        cout<<endl;
    }

        for(int i = row - 2 ; i > 0 ; i--)
    {
        for (int j = 0 ; j <= i ; j++)
        {
            cout<<char(65+i)<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    pattern();
}
