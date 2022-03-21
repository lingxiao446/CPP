/*
         string (1)     string& replace (size_t pos,        size_t len,        const string& str);
                        string& replace (const_iterator i1, const_iterator i2, const string& str);
      substring (2)	    string& replace (size_t pos,        size_t len,        const string& str,
                                        size_t subpos, size_t sublen = npos);
       c-string (3)	    string& replace (size_t pos,        size_t len,        const char* s);
                        string& replace (const_iterator i1, const_iterator i2, const char* s);
         buffer (4)	    string& replace (size_t pos,        size_t len,        const char* s, size_t n);
                        string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);
           fill (5)	    string& replace (size_t pos,        size_t len,        size_t n, char c);
                        string& replace (const_iterator i1, const_iterator i2, size_t n, char c);
          range (6)	    template <class InputIterator>
                        string& replace (const_iterator i1, const_iterator i2,
                                    InputIterator first, InputIterator last);
initializer list (7)	string& replace (const_iterator i1, const_iterator i2, initializer_list<char> il);

Replaces the portion of the string that begins at character pos and spans len characters 
     (or the part of the string in the range between [i1,i2)) by new contents

Exception safety
Strong guarantee: if an exception is thrown, there are no changes in the string.

If s does not point to an array long enough, or if the range specified by [first,last) is not valid, it causes undefined behavior.

If pos is greater than the string length, or if subpos is greater than str's length, an out_of_range exception is thrown.
If the resulting string length would exceed the max_size, a length_error exception is thrown.
A bad_alloc exception is thrown if the function needs to allocate storage and fails.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // string (1)  :  string& replace (size_t pos,        size_t len,        const string& str);
    //                string& replace (const_iterator i1, const_iterator i2, const string& str);
    string s11 = "I can make this promise";
    string s12 = "cannot";
    s11.replace(2, 3, s12);
    cout << "s11=" << s11 << endl;  // s11=I cannot make this promise
    s11.replace(s11.begin(), s11.begin() + 9, s12);
    cout << "s11=" << s11 << endl;  // s11=cannotmake this promise

    // substring (2) : string& replace (size_t pos, size_t len, const string& str, size_t subpos, size_t sublen = npos);
    string s21 = "Hello World";
    string s22 = "Hi there";
    s21.replace(0, 5, s22, 0, 2);
    cout << "s21=" << s21 << endl;  // s21=Hi World

    // c-string (3)	 :  string& replace (size_t pos,        size_t len,        const char* s);
    //                  string& replace (const_iterator i1, const_iterator i2, const char* s);
    string s31 = "Hello World";
    char s32[] = "Welcome to the";
    s31.replace(0, 5, s32);
    cout << "s31=" << s31 << endl; // s31=Welcome to the World
    s31.replace(s31.begin(), s31.end(), "Hi");
    cout << "s31=" << s31 << endl; // s31=Hi

    // buffer (4) :	 string& replace (size_t pos,        size_t len,        const char* s, size_t n);
    //               string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);
    string s41 = "Hello World";
    char s42[] = "Hi there";
    s41.replace(0, 5, s42, 2);
    cout << "s41=" << s41 << endl; // s41=Hi World
    s41.replace(s41.begin(), s41.end(), s42, 12); // n > real len, added gabarge.
    cout << "s41=" << s41 << "$$$, size=" << s41.size() << endl; // s41=Hi there@�$$$, size=12

    //  fill (5) : string& replace (size_t pos,        size_t len,        size_t n, char c);
    //             string& replace (const_iterator i1, const_iterator i2, size_t n, char c);
    string s51 = "Welcome to the World";
    s51.replace(3, 4, 2, 'D');
    cout << "s51=" << s51 << endl; // s51=WelDD to the World
    s51.replace(14, 20, 3, 'D'); // len > npos, used: real length.
    cout << "s51=" << s51 << ", size=" << s51.size() << endl; // s51=WelDD to the WDDD, size=17

    // range (6) : template <class InputIterator>
    //             string& replace (const_iterator i1, const_iterator i2, InputIterator first, InputIterator last);
    string s61 = "ACBDEFG";
    string s62 = "abcdefghijk";
    s61.replace(s61.begin(), s61.end(), s62.begin(), s62.end());
    cout << "s61=" << s61 << endl; // s61=abcdefghijk

    // initializer list (7)	string& replace (const_iterator i1, const_iterator i2, initializer_list<char> il);
    string s71 = "WWW";
    s71.replace(s71.begin(), s71.end(), {'a','b','c'});
    cout << "s71=" << s71 << endl; // s71=abc

    return 0;
}


