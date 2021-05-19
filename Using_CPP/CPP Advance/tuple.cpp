//Kaushal Prajapat  13.05.2021
   // tuple and pair are very similar in their structure. Just like in pair we can pair two heterogeneous object, in tuple we can pair three heterogeneous objects.

#include <iostream>
#include<utility>
#include<tuple>
using namespace std;
int main ()
{
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;

   tuple<int, int, int> tuple1;   //creates tuple of integers
   tuple<int, string, string> tuple2;    // creates pair of an integer an 2 string

   tuple1 = make_tuple(1,2,3);  // insert 1, 2 and 3 to the tuple1
   tuple2 = make_tuple(1,"Studytonight", "Loves You");
   /* insert 1, "Studytonight" and "Loves You" in tuple2  */

    // Assigning values to tuple using make_tuple()
    tuple <char ,int , float> geek = make_tuple('a', 10, 15.5);


// Printing a TUPLE
   cout<<"Print Tuple Geek "<<get<0>(geek)<<"  "<<get<1>(geek)<<"  "<<get<2>(geek)<<endl; // get<index>(tupleName)
//Tuple Size
    std::cout << "Geek tuple has ";
  std::cout << std::tuple_size<decltype(geek)>::value;
  std::cout << " elements." << '\n';
   int i_val;
    char ch_val;
    float f_val; 
    // Use of tie() with ignore
    // ignores char value
    tie(ch_val,ignore,f_val) = geek;
cout<<"Print Tuple Geek "<<ch_val<<"  "<<f_val<<"  "<<i_val<<endl; // get<index>(tupleName) //i_val contains garbage values


   int id;
   string first_name, last_name;

   tie(id,first_name,last_name) = tuple2;
   /* ties id, first_name, last_name to
   first, second and third element of tuple2 */

   cout <<"Printing Another Tuple : \n"<< id <<" "<< first_name <<" "<< last_name;
   /* prints 1 Studytonight Loves You  */

   // Tuple Template: Some Commonly used Functions
   // Similar to pair, tuple template has its own member and non-member functions, few of which are listed below :

   // A Constructor to construct a new tuple
   // Operator = : to assign value to a tuple
   // swap : to swap value of two tuples
   // make_tuple() : creates and return a tuple having elements described by the parameter list.
   // Operators( == , != , > , < , <= , >= ) : lexicographically compares two pairs.
   // Tuple_element : returns the type of tuple element
   // Tie : Tie values of a tuple to its refrences.

   return 0;
}
