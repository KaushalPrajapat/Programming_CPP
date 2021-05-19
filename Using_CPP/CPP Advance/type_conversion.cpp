//Type Conversion
//Kaushal Prjapat 10.05.2021
//Example

#include<iostream>
using namespace std;

//1.Primative--Primative    ---- Direct assignment ,  Data lose may be possible
//2.Primative--Class        ---- Operator overloading
//3.Class--class
//Example 1
void primative_primative()
{
    int a = 10,c;
    float b = 20.15,d;
    c=b;
    d=a;
    cout<<"Convert int to float "<<d<<endl;
    cout<<"Convert float to int "<<c<<endl;
}
class test
{
private:
    int a,b;
public:
    void setData(int x =15 , int y=20)
    {
        a=x;
        b=y;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    void show()
    {
        cout<<"Value of A : "<<a<<endl<<"Value of B :"<<b<<endl;
    }
    operator int()
    {
        return (a);
    }

};
class check
{
private:
    int num1,num2;
public:
    check(test t1) //Constructor overloaded so we need to make default constructor manually
    {
        num1 = t1.getA();
        num2 = t1.getB();
    }
    check(){} //Default constructor manually created

    void show()
    {
        cout<<endl<<endl<<"Value of Num1 : "<<num1<<endl<<"Value of Num2 :"<<num2<<endl;
    }
    /*operator test()
    {
        return (test);
    }*/
    };
void class_class()
{
    //This has two methods
    //1.Constructor Creating in
    //2.Operator Overloading in assignment class

    //Using method one:
    test t2;
    t2.setData(15,16);
    check c1;
    c1=t2; //c1.constructor(t1) // It generated a problem of constructor overloading
    c1.show();
    //Using method two Operator Overloading --- Can't fix program Have a problem
    test t3;
    t3.setData(21,22);
    check c2;
    c2=t3;

    c2.show();

}
void primative_class()
{
    //Work need to assign value of test class into a int variable
    test t1;
    t1.setData(12,25);
    int z;
    z=t1;
    cout<<endl<<"After Operator OverLoading Z : "<<z;
}
int main()
{
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;
    cout<<endl;
    primative_primative();
    primative_class();
    class_class();
}
