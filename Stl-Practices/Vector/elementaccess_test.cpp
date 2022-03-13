/*
      reference operator[] (size_type n);
const_reference operator[] (size_type n) const;
    Returns a reference to the element at position n in the vector container.
    A similar member function, vector::at, has the same behavior as this operator function, 
      except that vector::at is bound-checked and signals if the requested position is out of range by 
      throwing an out_of_range exception.
    Portable programs should never call this function with an argument n that is out of range, 
      since this causes undefined behavior.

      reference at (size_type n);
const_reference at (size_type n) const;
    Returns a reference to the element at position n in the vector.
    The function automatically checks whether n is within the bounds of valid elements in the vector, 
      throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size). 
      This is in contrast with member operator[], that does not check against bounds.

      reference front();
const_reference front() const;
    Returns a reference to the first element in the vector.
    Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
    Calling this function on an empty container causes undefined behavior.

      reference back();
const_reference back() const;
    Returns a reference to the last element in the vector.
    Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
    Calling this function on an empty container causes undefined behavior.

      value_type* data() noexcept;
const value_type* data() const noexcept;
    Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
    Because elements in the vector are guaranteed to be stored in contiguous storage locations in the same order as 
      represented by the vector, the pointer retrieved can be offset to access any element in the array.
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
    vector<int> v1(12);

    v1.at(2) = 15;
    v1.front() = 9;
    v1.back() = 99;
    v1[10] = 66;
    printItem(v1, "v1="); // v1=9, 0, 15, 0, 0, 0, 0, 0, 0, 0, 66, 99,

    // data()
    int *p = v1.data();
    *p = 100;
    p++;
    *p = 990;
    p[8] = 44;
    printItem(v1, "v1="); // v1=100, 990, 15, 0, 0, 0, 0, 0, 0, 44, 66, 99,

    return 0;
}

