//Nested Class -- Class inside a class
//Can't access inner class private variable or function outside inner class

//Kaushal Prajapat -- 11.05.2021


#include<iostream>
#include<string.h>
using namespace std;

class student
{
private:
    int roll,id,cls;
public:
    class address
    {
    private:
        int b_no,pin;
        string street,state;
    public:
        void setAdd(int building, int pin1 ,string str, string st)
        {
            b_no = building;
            pin = pin1;
            street = str;
            state = st;
        }
        void show()
        {
            cout<<"\nAddress : \nBuilding No."<<b_no<<"\nStreet : "<<street<<endl<<"Pin No. : "<<pin<<endl<<"State : "<<state<<endl<<"All Done";
        }
    };

    address ad;
    void setData(int r, int id1, int cl, int b , int p ,string str, string s)
    {
        roll = r;
        id = id1;
        cls = cl;
        ad.setAdd(b,p,str,s);
    }
    void show()
    {
        cout<<"Roll : "<<roll<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Class : "<<cls<<endl;
        ad.show();
    }
};

int main()
{
    student st;
    st.setData(1,1001,10,120,321219,"10 Jan Path","raj");
    st.show();
}
