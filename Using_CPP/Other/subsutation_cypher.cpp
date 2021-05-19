#include<iostream>
using namespace std;
namespace mySpace{

    int a;
    void f1();
}
namespace mySpace{
    int b;
    void f2();
}

using namespace mySpace;
//using namespace mySpace1;
void mySpace::f1()
{
    cout<<"End F1"<<endl;
}
int main()
{
    mySpace::a=10;
    cout<<mySpace::a<<endl;
    cout<<"Main";
    f1();

}
