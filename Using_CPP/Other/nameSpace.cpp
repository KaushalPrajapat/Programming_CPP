#include<iostream>
#include"kaushal.h"
using namespace std;
namespace mySpace{

    int a;
    void f1();
}
namespace mySpace{
    int b;
    void f2();
    class cls
        {
        public:
            void fun1();
        };
}
using namespace kaushal;
kaushal::var2 = 20;
kaushal::func()
{
    cout<<"Function inside Kaushal NameSpace";

}
//namespace can be extented --- two variable a,b two function f1 and f2, one class cls
//Two namespace with same name
using namespace mySpace;
//using namespace mySpace1;
void mySpace::f1() //Defining a Function
{
    cout<<"End F1"<<endl;
}

void mySpace::cls::fun1()
{
    cout<<"Inside Class function fun1"<<endl;
}
int main()
{
    mySpace::a=10; // Assigning a variable
    cout<<mySpace::a<<endl;
    cout<<"Main";
    f1();
    mySpace::cls cl;
    cl.fun1();
    cout<<"Kaushal's Variable : "<<kaushal::var1<<" "<<kaushal::var2;
    cout<<endl<<"Kaushal's Function : "<<kaushal::func();
}
