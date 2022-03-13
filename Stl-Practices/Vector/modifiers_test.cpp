
/*
void push_back (const value_type& val);
void push_back (value_type&& val);
    Adds a new element at the end of the vector, after its current last element. 
        The content of val is copied (or moved) to the new element.
    This effectively increases the container size by one, which causes an automatic reallocation of 
        the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.

void pop_back();
    Removes the last element in the vector, effectively reducing the container size by one.
    This destroys the removed element.
DANGER!!!!: CAN NOT pop_back a empty vector.

void swap (vector& x);
    Exchanges the content of the container by the content of x, which is another vector object of the same type. 
       Sizes may differ.
    After the call to this member function, the elements in this container are those which were in x before the call, 
       and the elements of x are those which were in this. All iterators, references and pointers remain valid for 
       the swapped objects.
    Notice that a non-member function exists with the same name, swap, overloading that algorithm with 
       an optimization that behaves like this member function.

void clear() noexcept;
    Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
    A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to 
    calling this function. A typical alternative that forces a reallocation is to use swap:
        vector<T>().swap(x);   // clear x reallocating 

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
    // push_back
    vector<int> v1;
    v1.push_back(23);
    v1.push_back(34);
    v1.push_back(1);
    v1.push_back(98);
    printItem(v1, "v1="); // v1=23, 34, 1, 98, 

    v1.pop_back();
    printItem(v1, "v1="); // v1=23, 34, 1,

    // pop_back
    vector<int> v2;
    cout << "before pop_back: size=" << v2.size() << ", capacity=" << v2.capacity() << ", maxsize=" << v2.max_size() << endl;
    // before pop_back: size=0, capacity=0, maxsize=2305843009213693951
    //v2.pop_back();   // undefined behavior!!!!, DANGER!!!!!!
    cout << "after  pop_back: size=" << v2.size() << ", capacity=" << v2.capacity() << ", maxsize=" << v2.max_size() << endl;
    // after  pop_back: size=18446744073709551615, capacity=0, maxsize=2305843009213693951

    v1.swap(v2);
    printItem(v1, "v1="); // v1=
    printItem(v2, "v2="); // v2=23, 34, 1,

    v1.clear();
    v2.clear();
    cout << "v1.size() = " << v1.size() << ", v2.size() = " << v2.size() << endl; //1.size() = 0, v2.size() = 0
    printItem(v1, "v1=");  // v1=
    printItem(v2, "v2=");  // v2=

    return 0;
}


