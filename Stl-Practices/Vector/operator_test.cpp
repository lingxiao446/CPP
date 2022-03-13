/*
copy (1)	
    vector& operator= (const vector& x);
move (2)	
    vector& operator= (vector&& x);
initializer list (3)	
    vector& operator= (initializer_list<value_type> il);
*/
#include <vector>
#include <iostream>

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
    // vector& operator= (const vector& x)
    vector<int> v1({9, 8, 7, 6});
    vector<int> v2 = v1;
    printItem(v1, "v1="); // v1=9, 8, 7, 6, 
    printItem(v2, "v2="); // v2=9, 8, 7, 6,

    // vector& operator= (vector&& x)
    vector<int> v3 = std::move(v2);
    printItem(v3, "v3="); // v3=9, 8, 7, 6,
    printItem(v2, "move v2="); // move v2=

    // vector& operator= (initializer_list<value_type> il)
    vector<int> v4 = {1, 2, 3, 4, 5};  // wrong:(); correct:({}) or {}
    printItem(v4, "v4="); // v4=1, 2, 3, 4, 5,

    return 0;
}