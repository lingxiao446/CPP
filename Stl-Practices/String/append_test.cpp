/*
Extends the string by appending additional characters at the end of its current value:

         string (1)	    string& append (const string& str);
      substring (2)	    string& append (const string& str, size_t subpos, size_t sublen = npos); 
                                        // if sublen>npos?, Seems no problem!!!!, in this case, would just append npos lenght.
       c-string (3)	    string& append (const char* s);
         buffer (4)	    string& append (const char* s, size_t n);
                                        // if n > s.length, undefined behavior.
           fill (5)	    string& append (size_t n, char c);
          range (6)	    template <class InputIterator>
                        string& append (InputIterator first, InputIterator last);
initializer list(7)	    string& append (initializer_list<char> il);

Exception safety
    Strong guarantee: if an exception is thrown, there are no changes in the string.

    If s does not point to an array long enough, or if the range specified by [first,last) is not valid, 
        it causes undefined behavior.

    If subpos is greater than str's length, an out_of_range exception is thrown.
    If the resulting string length would exceed the max_size, a length_error exception is thrown.
    A bad_alloc exception is thrown if the function needs to allocate storage and fails.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    string s1("Hello");
    string s2 = "Welcome to the World!";
    
    // string (1) : string& append (const string& str)
    s.append(s1);
    cout << "s=" << s << endl;  // s=Hello

    // substring (2) : string& append (const string& str, size_t subpos, size_t sublen = npos)
    s.append(s2, 14);
    cout << "s=" << s << endl; // s=Hello World!

    string s3;
    s3.append(s1);
    s3.append(s2, 14, 7);
    cout << "s3=" << s3 << endl; // s3=Hello World!

    string s4;
    s4.append(s1);
    s4.append(s2, 14, 10);   // 10 >npos. Seems no problem!!!!, in this case, would just append npos lenght.
    cout << "s4=" << s4 << ", len=" << s4.size() << endl; // s4=Hello World!, len=12 


    // c-string (3)	: string& append (const char* s)
    string s5;
    s5.append("Do you know this thing?");
    cout << "s5=" << s5 << endl; // s5=Do you know this thing?

    // buffer (4) : string& append (const char* s, size_t n)
    char arr[] = "cplusplus.com";
    string s6;
    s6.append(arr, 9);
    cout << "s6=" << s6 << endl; // s6=cplusplus

    string s7;
    s7.append(arr, 20); // 20 > att.length. something is wrong, will use the 20 as length.
    cout << "s7=" << s7 << ", len=" << s7.size() << endl; // s7=cplusplus.comp.6Z, len=20

    // fill : string& append (size_t n, char c)
    string s8;
    s8.append(10, 'A');
    cout << "s8=" << s8 << endl; // s8=AAAAAAAAAA

    // range (6)  template <class InputIterator> string& append (InputIterator first, InputIterator last);
    vector<char> v={'a', 'b', 'c', 'd', 'e'};
    string s9;
    s9.append(v.begin(), v.begin()+3);
    cout << "s9=" << s9 << endl; // s9=abc

    // initializer list(7) : string& append (initializer_list<char> il)
    string s10;
    s10.append({'a', '1', '2', '3'});
    cout << "s10=" << s10 << endl;  // s10=a123

    return 0;
}