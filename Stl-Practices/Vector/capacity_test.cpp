/*
size_type size() const noexcept;
    Returns the number of elements in the vector.
    This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.

size_type max_size() const noexcept;
    Returns the maximum number of elements that the vector can hold.
    This is the maximum potential size the container can reach due to known system or library implementation limitations, 
      but the container is by no means guaranteed to be able to reach that size: 
      it can still fail to allocate storage at any point before that size is reached.

void resize (size_type n);
void resize (size_type n, const value_type& val);
    Resizes the container so that it contains n elements.
    If n is smaller than the current container size, the content is reduced to its first n elements, 
       removing those beyond (and destroying them).
    If n is greater than the current container size, the content is expanded by inserting at the end as 
       many elements as needed to reach a size of n. 
       If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
    If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space 
      takes place.
    Notice that this function changes the actual content of the container by inserting or erasing elements from it.

size_type capacity() const noexcept;
    Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
    This capacity is not necessarily equal to the vector size. It can be equal or greater, 
       with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
    Notice that this capacity does not suppose a limit on the size of the vector. 
       When this capacity is exhausted and more is needed, it is automatically expanded by the container 
         (reallocating it storage space). The theoretical limit on the size of a vector is given by member max_size.
    The capacity of a vector can be explicitly altered by calling member vector::reserve.

bool empty() const noexcept;
    Returns whether the vector is empty (i.e. whether its size is 0).
    This function does not modify the container in any way. To clear the content of a vector, see vector::clear.

void reserve (size_type n);
    Requests that the vector capacity be at least enough to contain n elements.
    If n is greater than the current vector capacity, the function causes the container to reallocate 
       its storage increasing its capacity to n (or greater).
    In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
    This function has no effect on the vector size and cannot alter its elements.

void shrink_to_fit();
    Requests the container to reduce its capacity to fit its size.
    The request is non-binding, and the container implementation is free to optimize otherwise and leave the vector 
       with a capacity greater than its size.
    This may cause a reallocation, but has no effect on the vector size and cannot alter its elements.

*/
#include <iostream>
#include <vector>

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
    // size(), max_size(), capacity().
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(5);
    cout << "v1 size =" << v1.size() << ", max size=" << v1.max_size() << ", capacity =" << v1.capacity() << endl;
    // v1 size =3, max size=2305843009213693951, capacity =4

    // resize(n)
    v1.resize(10);
    cout << "after resize to 10:" <<  endl;
    cout << "v1 size =" << v1.size() << ", max size=" << v1.max_size() << ", capacity =" << v1.capacity() << endl;
    // v1 size =10, max size=2305843009213693951, capacity =10

    printItem(v1, "v1="); // v1=1, 2, 5, 0, 0, 0, 0, 0, 0, 0,

    // resize(n, val);
    v1.resize(12, 99);
    printItem(v1, "v1="); // v1=1, 2, 5, 0, 0, 0, 0, 0, 0, 0, 99, 99,

    // reserve(n)
    v1.reserve(6);   // nothing to be changed.
    cout << "v1 size =" << v1.size() << ", max size=" << v1.max_size() << ", capacity =" << v1.capacity() << endl;
    // v1 size =12, max size=2305843009213693951, capacity =20
    printItem(v1, "v1="); // v1=1, 2, 5, 0, 0, 0, 0, 0, 0, 0, 99, 99,

    v1.resize(8);
    cout << "v1 size =" << v1.size() << ", max size=" << v1.max_size() << ", capacity =" << v1.capacity() << endl;
    // v1 size =8, max size=2305843009213693951, capacity =20
    printItem(v1, "v1="); // v1=1, 2, 5, 0, 0, 0, 0, 0,

    // shrink_to_fit()
    v1.shrink_to_fit();
    cout << "v1 size =" << v1.size() << ", max size=" << v1.max_size() << ", capacity =" << v1.capacity() << endl;
    // v1 size =8, max size=2305843009213693951, capacity =8

    v1.reserve(100);
    v1.shrink_to_fit();
    cout << "v1 size =" << v1.size() << ", max size=" << v1.max_size() << ", capacity =" << v1.capacity() << endl;
    // v1 size =8, max size=2305843009213693951, capacity =8

    return 0;
}