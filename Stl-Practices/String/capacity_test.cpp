/*
size_t size() const noexcept;       //Return length of string (public member function )

size_t length() const noexcept;     //Return length of string (public member function )

size_t max_size() const noexcept;   //Return maximum size of string (public member function )

void resize (size_t n);
void resize (size_t n, char c);     //Resize string (public member function )
                                    //If n is smaller than the current string length, 
                                    //  the current value is shortened to its first n character, 
                                    //  removing the characters beyond the nth.
                                    //If n is greater than the current string length, 
                                    //  the current content is extended by inserting at the end as many 
                                    //  characters as needed to reach a size of n. If c is specified, 
                                    //  the new elements are initialized as copies of c, 
                                    //  otherwise, they are value-initialized characters (null characters).

size_t capacity() const noexcept;   //Return size of allocated storage (public member function )

void reserve (size_t n = 0);        //Request a change in capacity (public member function )
                                    //If n is greater than the current string capacity, the function causes 
                                    //  the container to increase its capacity to n characters (or greater).
                                    //In all other cases, it is taken as a non-binding request to shrink 
                                    //  the string capacity: the container implementation is free to 
                                    //  optimize otherwise and leave the string with a capacity greater than n.

void clear() noexcept;              //Clear string (public member function )

bool empty() const noexcept;        //Test if string is empty (public member function )

void shrink_to_fit();               //Shrink to fit (public member function )

// Learned:
 reserve() and shrink_to_fit() will change the size of capacity.
*/
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string v1("This is an amazing booking!");
    cout << "v1, size=" << v1.size() << ", capacity=" << v1.capacity() << ", max_size=" << v1.max_size() << endl;
    // v1, size=27, capacity=27, max_size=4611686018427387903

    v1.reserve(64); // Explain: n > size(), don't change the size, but changed the capacity.
    cout << "reserve(64), size=" << v1.size() << ", capacity=" << v1.capacity() << endl;
    // reserve(64), size=27, capacity=64

    v1.reserve(12);  // Explain: n < size(),don't change the size and the capacity. 
    cout << "reserve(12), v1=" << v1 << "###" << endl; 
    cout << "reserve(12), size=" << v1.size() << ", capacity=" << v1.capacity() << endl;
    // reserve(12), v1=This is an amazing booking!###
    // reserve(12), size=27, capacity=64

    v1.resize(32); // Explain: n > size(), change the size, but the content??????Add garbage??
    cout << "resize(32): v1=" << v1 << "###" << endl; 
    cout << "resize(32), size=" << v1.size() << ", capacity=" << v1.capacity() << endl;
    // resize(32): v1=This is an amazing booking!###
    // resize(32), size=32, capacity=64         

    v1.resize(24); // Explain: n < size(), cut the content.
    cout << "resize(24): v1=" << v1 << "###" << endl; 
    cout << "resize(24), size=" << v1.size() << ", capacity=" << v1.capacity() << endl;
    // resize(24): v1=This is an amazing booki###
    // resize(24), size=24, capacity=64

    v1.resize(30, '$'); // Explain: n > size(), change the size and append the character.
    cout << "resize(30): v1=" << v1 << "###" << endl; 
    cout << "resize(30), size=" << v1.size() << ", capacity=" << v1.capacity() << endl;
    // resize(30): v1=This is an amazing booki$$$$$$###
    // resize(30), size=30, capacity=64

    v1.resize(12, '*'); //Explain: n< size(), change the size and cut the content.
    cout << "resize(12): v1=" << v1 << "###" << endl; 
    cout << "resize(12), size=" << v1.size() << ", capacity=" << v1.capacity() << endl;
    // resize(12): v1=This is an a###
    // resize(12), size=12, capacity=64

    v1.clear();
    v1.reserve(100); 
    cout << "reserve(100), size=" << v1.size() << ", capacity=" << v1.capacity() << endl;
    // reserve(100), size=0, capacity=128
    
    v1.shrink_to_fit(); // Explain: seems the smallest of capacity is 15 in this environment.
    cout << "shrink_to_fit, size=" << v1.size() << ", capacity=" << v1.capacity() << endl;
    // shrink_to_fit, size=0, capacity=15

    return 0;
}

