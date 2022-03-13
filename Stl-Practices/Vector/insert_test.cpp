/*
single element (1)	
iterator insert (const_iterator position, const value_type& val);

fill (2)	
iterator insert (const_iterator position, size_type n, const value_type& val);

range (3)	
template <class InputIterator>
iterator insert (const_iterator position, InputIterator first, InputIterator last);

move (4)	
iterator insert (const_iterator position, value_type&& val);

initializer list (5)	
iterator insert (const_iterator position, initializer_list<value_type> il);

Explain: 
    The vector is extended by inserting new elements before the element at the specified position, 
    effectively increasing the container size by the number of elements inserted.

    This causes an automatic reallocation of the allocated storage space if -and only if- 
    the new vector size surpasses the current vector capacity.

    Because vectors use an array as their underlying storage, inserting elements in positions other than 
    the vector end causes the container to relocate all the elements that were after position to their new positions. 
    This is generally an inefficient operation compared to the one performed for the same operation 
    by other kinds of sequence containers (such as list or forward_list).

    The parameters determine how many elements are inserted and to which values they are initialized:

Return value
    An iterator that points to the first of the newly inserted elements.

    Member type iterator is a random access iterator type that points to elements.

    If reallocations happen, the storage is allocated using the container's allocator, 
    which may throw exceptions on failure (for the default allocator, bad_alloc is thrown 
    if the allocation request does not succeed).    
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void printItem(const std::vector<T>& v, const char *str)
{
    cout << str;

    for (const auto& e: v) {   
        cout << e <<", ";
    }
    cout << endl;

}

int main()
{
    vector<int> v1(4); // reserve 4 size.

    // iterator insert (const_iterator position, const value_type& val);
    v1.insert(v1.begin(), 5);
    v1[2] = 67;
    v1[3] = 78;
    v1.insert(v1.end(), 90);
    printItem(v1, "v1="); // v1=5, 0, 67, 78, 0, 90, 

    // iterator insert (const_iterator position, size_type n, const value_type& val);
    vector<int> v2(v1);
    auto it = find(v2.begin(), v2.end(), 78);
    auto it2 = v2.insert(it, 4, 999);
    v2.insert(v2.end(), 333);
    printItem(v2, "v2="); // v2=5, 0, 67, 999, 999, 999, 999, 78, 0, 90, 333, 

    // iterator insert (const_iterator position, InputIterator first, InputIterator last);
    vector<int> v3(v2.begin() + 4, v2.end());
    printItem(v3, "v3="); // v3=999, 999, 999, 78, 0, 90, 333,
    auto it3 = find(v3.begin(), v3.end(), 90);
    v3.insert(it3, v1.begin(), v1.end());
    printItem(v3, "v3="); // v3=999, 999, 999, 78, 0, 5, 0, 67, 78, 0, 90, 90, 333,

    // iterator insert (const_iterator position, initializer_list<value_type> il)
    vector<int> v4;
    v4.insert(v4.end(), {1, 2, 3, 4, 5});
    printItem(v4, "v4="); // v4=1, 2, 3, 4, 5, 

    return 0;
}



