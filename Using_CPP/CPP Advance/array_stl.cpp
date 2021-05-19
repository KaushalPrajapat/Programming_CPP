// kaushal Prajapat may.13.2021

#include<iostream>
using namespace std;

#include<array> // Including array header file
int main()
{
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;


    //Array initializer
  // 1.double-braces required
  array<int, 5> array1{{3, 4, 5, 1, 2}};
  // 2.construction uses aggregate initialization
  array<int, 5> array2 = {1, 2, 3, 4, 5};
  array<string, 2> array3 = {{string("a"), "b"}};


  // Member Functions of Array Template
  //   1.at() function -- throws a error If the given range is greater than the array size, out_of_range exception is thrown.
    //Example
    cout << array1.at(2)<<endl;     // prints 3
    cout << array2.at(4)<<endl;     // prints 5
    // cout << array3.at(2)<<endl;     It will throw a error "out of Index"

    // 2. [ ] Operator -- Works as at function
    // Example
    cout << array3[1]<<endl;

    // 3.front() function
    // This method returns the first element in the array.
    //Example --
    cout<<array1.front()<<endl;

    // 4.back() function
    // This method returns the last element in the array.
    //Example
    cout<<array1.back()<<endl;

    // 5.fill() function
    // This method assigns the given value to every element of the array,
    // Example :
    array<char , 5> array4;
    array4.fill('k');
    for(int i=0; i < 5; i++)
    {
    cout << array4[i] <<" ";
    }

    // 6.swap function
    // used to swap two array with same size and same type
    // Example
        array<int,8> a = {1,2,3,4,5,6,7,8};
    array<int,8> b = {8,7,6,5,4,3,2,1};

    a.swap(b);  // swaps array a and b

    cout << "a is : ";
    for(int i=0; i < 8; i++) {
    cout << a[i] <<" ";
    }
    cout << endl;
    cout << "b is : ";
    for(int i=0; i < 8; i++) {
    cout << a[i] <<" ";
    }
    /* output will be
    a is : 8 7 6 5 4 3 2 1
    b is : 1 2 3 4 5 6 7 8 */


    //   7.empty function
    // This method can be used to check whether the array is empty or not.
    // Syntax: array_name.empty(), returns true if array is empty else return false.

    cout<<endl<<array1.empty()<<endl;


    // 8.size function
    // This method returns the number of element present in the array.
    cout<<"Size of array " <<array1.size();

    // 9. max_size function
    // This method returns the maximum size of the array.
    cout<<"Max size of array : "<<array1.max_size();

    // begin function --end function
    // This method returns the iterator pointing to the first -- last element of the array
    //cout<<"Array1's first element : "*(array1.begin());
    // auto itr = array1.end();
    // cout<<*itr;  ---
    // Printing NULL or 0 value don't know why

    // EXTRA
    //     operators ( == , != , > , < , >= , <= )
    // All these operators can be used to lexicographically compare values of two arrays.
}
