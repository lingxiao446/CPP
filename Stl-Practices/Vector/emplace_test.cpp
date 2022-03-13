/*
template <class... Args>
iterator emplace (const_iterator position, Args&&... args);

    The container is extended by inserting a new element at position. 
    This new element is constructed in place using args as the arguments for its construction.
    This effectively increases the container size by one.
    An automatic reallocation of the allocated storage space happens if -and only if- the new vector size surpasses 
    the current vector capacity.

    Because vectors use an array as their underlying storage, inserting elements in positions other than 
    the vector end causes the container to shift all the elements that were after position 
    by one to their new positions. This is generally an inefficient operation compared to 
    the one performed by other kinds of sequence containers (such as list or forward_list). 
    See emplace_back for a member function that extends the container directly at the end.

    The element is constructed in-place by calling allocator_traits::construct with args forwarded.
    A similar member function exists, insert, which either copies or moves existing objects into the container.

    Parameters
        position
            Position in the container where the new element is inserted.
            Member type const_iterator is a random access iterator type that points to a const element.
        args
            Arguments forwarded to construct the new element.

    Return value
        An iterator that points to the newly emplaced element.
        Member type iterator is a random access iterator type that points to an element.

    If a reallocation happens, the storage is allocated using the container's allocator, 
    which may throw exceptions on failure (for the default allocator, bad_alloc is thrown 
    if the allocation request does not succeed).

template <class... Args>
void emplace_back (Args&&... args);
    Inserts a new element at the end of the vector, right after its current last element. 
    This new element is constructed in place using args as the arguments for its constructor.

    This effectively increases the container size by one, which causes an automatic reallocation of 
    the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.

    The element is constructed in-place by calling allocator_traits::construct with args forwarded.

    A similar member function exists, push_back, which either copies or moves an existing object into the container. 

Question:
    Why emplace_back is faster than push_back?
Answer:
    because emplace_back would construct the object immediately in the vector, 
    while push_back, would first construct an anonymous object and then would copy it to the vector
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
    vector<int> v1;

    v1.emplace_back(12);
    auto it = v1.emplace(v1.begin(), 34);
    v1.emplace(it, 98);
    printItem(v1, "v1=");  // v1=98, 34, 12, 

    v1.emplace_back(56);
    v1.emplace_back(100);
    v1.emplace_back(21);
    auto it2 = find(v1.begin(), v1.end(), 100);
    v1.emplace(it2, 300);
    printItem(v1, "v1="); // v1=98, 34, 12, 56, 300, 100, 21,


    return 0;
}



