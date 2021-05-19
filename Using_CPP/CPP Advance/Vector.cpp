// Kaushal Prajapat 13.05.2021

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;

    // SYNTAX for creating a vector is: vector< object_type > vector_name;
    //vector<int> v;
    // Vector initializer
    vector<string> v = {"Pankaj" ,"The" ,"Java" ,"Coder","Rojer","stok","ROni"};
    //Method two initialize a vector
    //vector<string> v1;
    //vector<string> v2 (v1.begin(), v1.end());
    // The above code initialize the vector by elements pointed by iterators returned by v2.begin() and v2.end(), begin() and end() are the same function we have studied with array, they work same with vectors.

    //Method two initialize a vector
    //vector<string> v4(4 , "test");
    // You can also initialize a vector with one element a certain number of times, like :

    // Member Functions of Vector
    // push_back function
    v.push_back("Kaushal Pushing");

    // insert function
    // insert(itr, element) method inserts the element in vector before the position pointed by iterator itr.
    auto it = v.begin();
    v.insert(it+4,"Insert Function,120");  //insert(itrator, No_of_times_insert, element_to_insert)

    // pop_back function
    // pop_back() is used to remove the last element from the vector. It reduces the size of the vector by one.
    v.pop_back();

    //     erase function
    // erase(itr_pos) removes the element pointed by the iterator itr_pos
    v.erase(v.begin(), v.end() - 5 ); //v.earse(start_it,end_it)

    // resize function
    // resize(size_type n, value_type val)
    //     method resizes the vector to n elements. If the current size of the vector is greater than n then the trailing elements are removed from the vector and if the current size is smaller than n than extra val elements are inserted at the back of the vector.

    // For example, If the size of the vector is 4 right now, with elements {10, 20, 30, 40} and we use resize method to resize it to size 5. Then by default a fifth element with value 0 will be inserted in the vector. We can specify the data to not be zero, by explicitly mentioning it as the val while calling the resize method.

    // swap function
    // This method interchanges value of two vectors.

    // If we have two vectors v1 and v2 and we want to swap the elements inside them, you just need to call v1.swap(v2), this will swap the values of the two vectors.

    // clear function
    // This method clears the whole vector, removes all the elements from the vector but do not delete the vector.

    // SYNTAX: clear()

    // For a vector v, v.clear() will clear it, but not delete it.

    // size function
    // This method returns the size of the vector.
    cout<<"Size of Vector :  "<<v.size();
    // empty function
    // This method returns true if the vector is empty else returns false.
    // capacity function
    // This method returns the number of elements that can be inserted in the vector based on the memory allocated to the vector.
    cout<<endl<<"Max Capicity : "<<v.max_size()<<endl;

    // at function
    // This method works same in case of vector as it works for array. vector_name.at(i) returns the element at ith index in the vector vector_name.
    cout<<"Value at 3rd Index is : "<<v.at(3)<<endl;
    // front and back functions
    // vector_name.front() retuns the element at the front of the vector (i.e. leftmost element). While vector_name.back() returns the element at the back of the vector (i.e. rightmost element).






    cout<<"Key Value Pairs\n";
    for(auto itr = v.begin(); itr != v.end(); itr++)
    {
        cout<<*itr<<endl;
    }
}
