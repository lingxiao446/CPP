/*
         string (1)	  string& insert (size_t pos, const string& str);
      substring (2)	  string& insert (size_t pos, const string& str, size_t subpos, size_t sublen = npos);
       c-string (3)	  string& insert (size_t pos, const char* s);
         buffer (4)	  string& insert (size_t pos, const char* s, size_t n);
           fill (5)	  string& insert (size_t pos, size_t n, char c);
                      iterator insert (const_iterator p, size_t n, char c);
single character (6)  iterator insert (const_iterator p, char c);
           range (7)  template <class InputIterator>
                      iterator insert (iterator p, InputIterator first, InputIterator last);
initializer list (8)  string& insert (const_iterator p, initializer_list<char> il);


Note by Ling:
in 5, 6, 7, If there has "iterator" in argument list, then will return iterator type.

Exception safety
Strong guarantee: if an exception is thrown, there are no changes in the string.

If s does not point to an array long enough, or if either p or the range specified by [first,last) is not valid, it causes undefined behavior.

If pos is greater than the string length, or if subpos is greater than str's length, an out_of_range exception is thrown.
If the resulting string length would exceed the max_size, a length_error exception is thrown.
A bad_alloc exception is thrown if the function needs to allocate storage and fails.
*/
#include <string>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    string str = "Hi, ";

    // string (1) : string& insert (size_t pos, const string& str)
    string s1 = "Do you like coding?";
    s1.insert(0, str);
    cout << "s1=" << s1 << endl; // s1=Hi, Do you like coding?

    // substring (2) : string& insert (size_t pos, const string& str, size_t subpos, size_t sublen = npos);
    string s21 = "Apple, Orange.";
    string s22 = "Fruits";
    
    //s22.insert(s22.back(), s21, 6); // Can not use back()!!(back() return iterator!!)  throwing an instance of 'std::out_of_range'
    s22.insert(s22.size(), s21, 6); 
    cout << "s2=" << s22 << endl;    // s2=Fruits Orange.
    
    //s22.insert(s22.front(), s21, 0, 3);   // throwing an instance of 'std::out_of_range'!!!!! (front() return iterator.)  
    s22.insert(0, s21, 0, 3);      
    cout << "s2=" << s22 << endl;    // s2=AppFruits Orange.
    
    s22.insert(0, s21, 7, 9);        // sublen > really len. Note: used npos!!!!
    cout << "s2=" << s22 << endl;    // s2=Orange.AppFruits Orange. 


    // c-string (3)	: string& insert (size_t pos, const char* s)
    char s31[] = "ington";
    string s32 = "Wash State";
    s32.insert(4,s31);
    cout << "s32=" << s32 << endl; // s32=Washington State

    // buffer (4) : string& insert (size_t pos, const char* s, size_t n)
    char s41[] = "C & C++";
    string s42 = "Welcome to the World";
    s42.insert(strlen("Welcome to the "), s41, 2);
    cout << "s42=" << s42 << endl; // s42=Welcome to the C World

    // fill (5)	 : string& insert (size_t pos, size_t n, char c);
    //             iterator insert (const_iterator p, size_t n, char c);
    string s51 = "The Sea in Winter";
    s51.insert(0, 3, 'A');
    cout << "s51=" << s51 << endl;          // s51=AAAThe Sea in Winter

    string::iterator it = s51.insert(s51.cend(), 2, 'B');
    cout << "s51=" << s51 << endl;          // s51=AAAThe Sea in WinterBB
    if (it != s51.end()) {
        cout << "current=" << *it << endl;  // current=B    (Note: first B)
    } else {
        cout << "current in the end." << endl;
    }

    // single character (6)  iterator insert (const_iterator p, char c);
    string s61 = "East West Bank";
    s61.insert(s61.begin() + 4, 'W');
    cout << "s61=" << s61 << endl;     // s61=EastW West Bank

    // range (7)  template <class InputIterator>
    //                  iterator insert (iterator p, InputIterator first, InputIterator last);
    vector<char> v = {'a', 'b', 'c'};
    string s7 = "ABC";
    auto it7 = s7.insert(s7.begin() + 1, v.begin(), v.end());
    cout << "s7=" << s7 << ", *it7=" << *it7 << endl; // s7=AabcBC, *it7=a

    // initializer list (8) : string& insert (const_iterator p, initializer_list<char> il);
    string s8 = "The in Winter";
    s8.insert(s8.begin() + 4, {'S', 'e', 'a', ' '});
    cout << "s8=" << s8 << endl;  // s8=The Sea in Winter


    return 0;
}




