// Kaushal Prajapat 14.05.2021

#include<iostream>
#include<vector>
// #include<pair>
#include<map>
#include<utility>
#include<list>
#include<tuple>

using namespace std;

int main()
{
    tuple<int , string , string , string> t1 {1,"kaushal","Kumar","Prajapat"};

    cout<<get<0>(t1)<<endl;
    cout<<get<1>(t1)<<endl;
    cout<<get<2>(t1)<<endl;
    cout<<get<3>(t1)<<endl;

    vector<int> v{1,2};
    cout<<"capasity : " << v.capacity()<<endl; //2
    v.push_back(12);
    cout<<"capasity : " << v.capacity()<<endl; //4
    v.push_back(13);
    v.push_back(14);
    cout<<"capasity : " << v.capacity()<<endl; //8

}
