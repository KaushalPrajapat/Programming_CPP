#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};


class AA : public A
{
public:
    void func1(int &num)
    {
        func(num);
        //cout<<"Num in A: "<<num<<endl;
    }
};

class BB : public B
{
public:
    void func1(int &num)
    {
        func(num);
        //cout<<"Num in A: "<<num<<endl;
    }
};

class CC : public C
{
public:
    void func1(int &num)
    {
        func(num);
        //cout<<"Num in A: "<<num<<endl;
    }
};

class D : public A, public B , public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {while(new_val%2 == 0) {
                A::func(val);
                new_val /= 2;
                //cout<<new_val<<" 1"<<" ";
            }
            //cout<<endl;
            while(new_val%3 == 0) {
                B::func(val);
                new_val /= 3;
                //cout<<new_val<<" 2"<<" ";
            }
            //cout<<endl;
            while(new_val%5 == 0) {
                C::func(val);
                //cout<<new_val<<" 3"<<" ";
                new_val /= 5;
            }
         }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};



void D::check(int new_val)
{
    //cout<<"Check"<<endl;
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
    //cout<<new_val;

}
