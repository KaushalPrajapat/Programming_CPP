//Kaushal Prajapat 12.05.2021
//Container Library is collection of classes
//These are implements as generic class templates
//used to implement simple and complex data structure easily -- eg. stake, list tree associative array
//These are used to held different kind of object
//Common containers
//Vector<DynamicArray>,Queue,Stack,Priority Queue<Heap>,List<linkedList>Set<Tree>,Map<Associative array etc

//Classification of container
//1.Sequence -- array,LinkedList -- linear data
//2.Associative -- Map,set --
//3.Unordered Associative -- Unordered Data Structure
//4.Container Adapters -- Interface to sequence container

#include<iostream>
using namespace std;
#include<array>
int main()
{
    //Example
    array <int , 4> array_name = {11,22,33,44};
    cout<<array_name.at(3)<<endl;
    cout<<array_name.size();
}
