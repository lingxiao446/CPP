/*
assign:
range (1)	
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last);
fill (2)	
    void assign (size_type n, const value_type& val);
initializer list (3)	
    void assign (initializer_list<value_type> il);

In the range version (1), the new contents are elements constructed from each of the elements in the range 
  between first and last, in the same order.
In the fill version (2), the new contents are n elements, each initialized to a copy of val.
In the initializer list version (3), the new contents are copies of the values passed as initializer list,   
  the same order.
The internal allocator is used (through its traits) to allocate and deallocate storage if a reallocation happens. 
  It is also used to destroy all existing elements, and to construct the new ones.

Any elements held in the container before the call are destroyed and replaced by newly constructed elements 
  (no assignments of elements take place).
This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses
  the current vector capacity.
*/

#include <iostream>
#include <vector>
#include <array>

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
    vector<int> v1(12);
    v1.assign(5, 99);
    printItem(v1, "v1="); // v1=99, 99, 99, 99, 99, 

    vector<int> v2;
    v2.assign({1, 2, 3, 4, 5});
    printItem(v2, "v2="); // v2=1, 2, 3, 4, 5,

    array<int, 8> a1={11, 12, 13, 14, 15, 16};

    vector<int> v3;
    v3.assign(a1.begin(), a1.end());
    printItem(v3, "v3="); // v3=11, 12, 13, 14, 15, 16, 0, 0,

    vector<int> v4;
    v4.assign(a1.rbegin(), a1.rend());
    printItem(v4, "v4="); // v4=0, 0, 16, 15, 14, 13, 12, 11,

    return 0;
}


