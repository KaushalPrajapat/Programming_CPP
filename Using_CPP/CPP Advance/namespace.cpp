//NameSpace in CPP
//Kaushal Prajapat on 11.05.2021
//Creating a header file to include here --- newNameSpace.h include namespace ns which is used below


//#include<iostream> ---- This header file is included inside newNameSpace.h header file
// --- That's why we don't need to include it here again
//#include"kaushal.h"

#include"newNameSpace.h"
using namespace ns;
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
    void ns::fun2()
    {
        cout<<"Inside Fun2";
    }

int main()
{
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;

    mySpace::a=10; // Assigning a variable
    cout<<mySpace::a<<endl;
    cout<<"Main";
    f1();
    mySpace::cls cl;
    cl.fun1();
    //    cout<<"Kaushal's Variable : "<<kaushal::var1<<" "<<kaushal::var2;
    //  cout<<endl<<"Kaushal's Function : "<<kaushal::func();
    ns::var2=250;
    ns::var3=1524.256;
    cout<<ns::var1<<" "<<ns::var2<<" "<<ns::var3<<endl;
    ns::fun1();
    ns::fun2();
}
