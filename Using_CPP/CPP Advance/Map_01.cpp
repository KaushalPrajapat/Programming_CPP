// Kaushal Prajapat 13.05.2021

#include<iostream>
#include<map>
//#include<pair>
#include<utility>
using namespace std;

int main()
{
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;

    // Maps are used to replicate associative arrays. Maps contain sorted key-value pair,
    // We can search, remove and insert in a map within O(n) time complexity.
    // Creating a Map in C++ STL
    // map<key_type , value_type> map_name;
        map<int,int> m{ {1,2} , {2,3} , {3,4} };
    /* creates a map m with keys 1,2,3 and
        their corresponding values 2,3,4 */

    map<string,int> map1;
    /*  creates a map with keys of type character and
      values of type integer */

    map1["abc"]=100;    // inserts key = "abc" with value = 100
    map1["abd"]=200;      // inserts key = "b" with value = 200
    map1["abe"]=300;      // inserts key = "c" with value = 300
    map1["abf"]=400;    // inserts key = "def" with value = 400

    //map<char,int> map2 (map1.begin(), map1.end());
    /* creates a map map2 which have entries copied
        from map1.begin() to map1.end() */

    map<int,int> map3 (m);
    /* creates map map3 which is a copy of map m */

    // Member Functions of Map in C++ STL
    cout<<"Value at 2nd index : "<<map3[2]<<endl;
    cout<<"Value at 2nd index : "<<map1.at("abd")<<endl;

    // empty, size and max_size
    // empty() returns boolean true if the map is empty, else it returns Boolean false. size()
    // returns number of entries in the map, an entry consist of a key and a value. max_size()
    // returns the upper bound of the entries that a map can contain (maximum possible entries)
    // based on the memory allocated to the map.

    // insert and insert_or_assign
    // insert(pair) : In this variation, a pair of key and value is inserted in the map.
    // The inserted pair is always inserted at the appropriate position as keys are arranged in sorted order.
    // insert(start_itr , end_itr): This variation inserts the entries in range defined by start_itr
    // and end_itr of another map.
    // The insert_or_assing() works exactly as insert() except that if the given key is already present in
    // the map then its value is modified.

    map3.insert( pair<int,int> (4,5));
    /* make_pair() can also be used for creating a pair */
    map3.insert( make_pair(5, 6));

//    map3.insert_or_assign( make_pair(3,6));  // assign value = 6 to key =3

    // erase and clear
    // erase() removes the entry from the map pointed by the iterator (which is passed as parameter),
    // however if we want to remove all the elements from the map, we can use clear(), it clears the map and
    // sets its size to 0.

    // There are two variations of erase :

    // erase(iterator_itr) : This removes entry from the map pointed by iterator iterator_itr,
    // reducing the size of map by 1.
    // erase(start_iterator, end_iterator) : It removes the elements in range specified by the start_iterator
    // and end_iterator.

    // begin, end and find
    // begin, end and find returns an iterator. begin() returns the iterator to the starting entry of the map, end() returns the iterator next to the last entry in the map and find() returns the iterator to the entry having key equal to given key (passed as parameter).


    // Printing a MAP
    for(auto it = map3.begin() ; it != map3.end() ; it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }


}
