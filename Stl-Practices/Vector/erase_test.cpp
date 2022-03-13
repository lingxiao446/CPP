/*
iterator erase (const_iterator position);
iterator erase (const_iterator first, const_iterator last);

    Removes from the vector either a single element (position) or a range of elements ([first,last)).

    This effectively reduces the container size by the number of elements removed, which are destroyed.

    Because vectors use an array as their underlying storage, erasing elements in positions other than 
       the vector end causes the container to relocate all the elements after the segment erased to 
       their new positions. This is generally an inefficient operation compared to the one performed for 
       the same operation by other kinds of sequence containers (such as list or forward_list).  
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
    vector<int> v1({12, 34, 51, 78, 23});
    printItem(v1, "v1=");   // v1=12, 34, 51, 78, 23, 

    v1.erase(v1.begin());
    printItem(v1, "v1=");   // v1=34, 51, 78, 23,
    //v1.erase(v1.end()); // CAN NOT erase the v1.end()!!!!!!!!
    v1.erase(v1.end()-1); 
    printItem(v1, "v1=");   // v1=34, 51, 78,

    v1.erase(v1.begin(), v1.begin() + 2);
    printItem(v1, "v1=");   // v1=78,

    return 0;
}


