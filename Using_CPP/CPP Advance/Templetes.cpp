//template is  used to generalizing signature of function for multiple data type
//
//like -- int,float etc..
//Kaushal Prajapat 10.05.2021

#include<iostream>
using namespace std;

//Template Defination
template <class X, class Y> // Class X Y is may be different data type...
Y add(X a , Y  b) // Function defination
{
    return a+b;
}
int main()

{
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;
    cout<<"Sum is : "<<add(45.4857,25.41);
}


//Class Templete is also known as generic class
//Templete class
/*template <class Z> class temp // Z may be int float double etc as per user choice
                              // Used to make a general class
{

}
*/
