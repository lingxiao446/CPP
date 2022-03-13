
/*
default (1)	
    explicit vector (const allocator_type& alloc = allocator_type());
fill (2)	
    explicit vector (size_type n);
    vector (size_type n, const value_type& val, const allocator_type& alloc = allocator_type());
range (3)	
    template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
copy (4)	
    vector (const vector& x);
    vector (const vector& x, const allocator_type& alloc);
move (5)	
    vector (vector&& x);
    vector (vector&& x, const allocator_type& alloc);
initializer list (6)	
    vector (initializer_list<value_type> il, const allocator_type& alloc = allocator_type());
*/
#include <iostream>
#include <vector>
#include <string>

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
    // explicit vector (const allocator_type& alloc = allocator_type());
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(7);
    printItem(v1, "v1="); // v1=2, 5, 7,

    // explicit vector (size_type n)
    vector<char> v2(6);
    v2[0] = 'k';
    v2[1] = 'p';
    // v2[6] = 'W';    // will core dump!
    v2.push_back('a');
    v2.push_back('b');
    v2.push_back('c');
    v2.push_back('d');
    printItem(v2, "v2="); // v2=k, p, , , , , a, b, c, d,

    // vector (size_type n, const value_type& val, const allocator_type& alloc = allocator_type())
    vector<int> v21(6, 11);
    printItem(v21, "v21="); // v21=11, 11, 11, 11, 11, 11,

    // template <class InputIterator>
    // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
    vector<char> v3(v2.begin(), v2.begin()+4);
    printItem(v3, "v3="); //v3=k, p, , ,

    // vector (const vector& x)
    vector<int> v4(v21);
    printItem(v4, "v4="); // v4=11, 11, 11, 11, 11, 11,

    // vector (vector&& x)
    //vector<int> v5(&v4); //???????
    vector<int> v5 (std::move(v4));
    printItem(v5, "v5="); // v5=11, 11, 11, 11, 11, 11,
    printItem(v4, "move: v4="); // move: v4=


    // vector (initializer_list<value_type> il, const allocator_type& alloc = allocator_type())
    vector<string> v6({"Bothell", "Bellevue", "Kenmore", "Lynnwood"}); // wrong:(); correct:({}) or {}
    printItem(v6, "v6="); // v6=Bothell, Bellevue, Kenmore, Lynnwood,

    return 0;
}


