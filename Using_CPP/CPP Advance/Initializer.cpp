//initializer used to initialize a variable with some value
//initializer have to used in class when a const variable is decleard\
//Kaushal Prjapat 10.05.2021
//Example

#include<iostream>
using namespace std;

class test
{
private:
    int var1=12;
    const int var2; // We can't initialize a cont variable here
public:
test():var2(10) // This is use of initializer
                //We can't assign any value to var2 without this method
{
    var1=15;
}
void view()
{
    cout<<"Var1 is : "<<var1<<endl<<"Var2 is : "<<var2;
}
};
int main()
{
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;
    test t1;
    t1.view();
}
