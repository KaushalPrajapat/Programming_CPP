#include<iostream>
using namespace std;
namespace mySpace{
public:
    int a;
    void f1();
}
namespace mySpace1{
public:
    int a;
    void f1();
}

using namespace mySpace;
using namespace mySpace1;

int main()
{
    a=10;
    cout<<a<<endl;
    cout<<"Main";


}
