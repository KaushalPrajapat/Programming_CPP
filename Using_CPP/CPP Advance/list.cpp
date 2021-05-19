
#include<iostream>
#include<list>
using namespace std;

int main()
{
    // list initializer
    cout<<"----------------KAUSHAL PRAJAPAT----------------------"<<endl;

    list <int> lt = {10,20,30,40,50};

    // insert function
    // This method, as the name suggests, inserts an element at specific position, in a list. There are 3 variations of insert(), they are as follows :

    // insert(iterator, element) : inserts element in the list before the position pointed by the iterator.
    // insert(iterator, count, element) : inserts element in the list before the position pointed by the iterator, count number of times.
    // insert(iterator, start_iterator, end_iterator): insert the element pointed by start_iterator to the element pointed by end_iterator before the position pointed by iterator

    list<int> l = {1,2,3,4,5};
    list<int>::iterator it = l.begin();

    l.insert (++it, 100);
    list<int> new_l = {10,20,30,40};   // new list
    new_l.insert (new_l.begin(), l.begin(), l.end());
    /*
        insert elements from beginning of list l to end of list l
        before 1 position in list new_l */

    /* now the list new_l is 1 100 2 3 4 5 10 20 30 40 */
    l.insert(l.begin(), 5, 10);  // insert 10 before beginning 5 times
    /* now l is 10 10 10 10 10 1 100 2 3 4 5 */

    //push_back and push_front functions
    //push_back(element) method is used to push elements into a list from the back.
    l.push_back(6);
    l.push_front(8);
    

    //     pop_back and pop_front functions
    // pop_front() removes first element from the start of the list. While pop_back() removes first element from the end of the list.

    // empty function
    // This method returns true if the list is empty else returns false.

    // size function
    // This method can be used to find the number of elements present in the list.

    // front and back function
    // front() is used to get the first element of the list from the start while back() is used to get the first element of the list from the back.

    //     reverse function
    // This method can be used to reverse a list completely.

    //     swap function
    // Swaps two list, if there is exception thrown while swapping any element, swap() throws exception. Both lists which are to be swapped must be of the same type, i.e you can’t swap list of an integer with list of strings.

    //     sort function
    // sort() method sorts the given list. It does not create new sorted list but changes the position of elements within an existing list to sort it. This method has two variations :

    // sort() : sorts the elements of the list in ascending order, the element of the list should by numeric for this function.
    // sort(compare_function) : This type of sort() is used when we have to alter the method of sorting. Its very helpful for the elements that are not numeric. We can define how we want to sort the list elements in compare_funtion. For example, list of strings can be sorted by the length of the string, it can also be used for sorting in descending order.

    //     splice function
    // splice() method transfers the elements from one list to another. There are three versions of splice :

    // splice(iterator, list_name) : Transfers complete list list_name at position pointed by the iterator.
    // splice(iterator, list_name, iterator_pos) : Transfer elements pointed by iterator_pos from list_name at position pointed by iterator.
    // splice(iterator, list_name, itr_start, itr_end) : Transfer range specified by itr_start and itr_end from list_name at position pointed by iterator.

    //     merge function
    // Merges two sorted list. It is mandatory that both the list should be sorted first. merge() merges the two list such that each element is placed at its proper position in the resulting list. Syntax for merge is list1.merge(list2).

    //     Lexicographically comparing Lists
    // Since lists are collection of elements, thus they do not have a standard value of their own. Thus in order to compare list or vectors we compare their elements in their lexicographical order.

    // For example, let list1 = { 1 , 2 , 3} and list2 = { 1 , 3 , 2 }, now if we want to check if the list1 is greater than list2 or not, we just check the element of each list in the order they appear in the lists. Since 1 in list1 is equal to 1 in list2, we proceed further, now 2 in list1 is smaller then 3 in list2, thus list2 is lexicographically greater than list1.

    // Operators == , > , < , <= , >= can be used to compare lists lexicographically.



    auto p=l.begin();
    while(p !=  l.end())
    {
        cout<<*p<<" ";
        p++;
    }
}
