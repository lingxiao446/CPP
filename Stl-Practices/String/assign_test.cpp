/* Assigns a new value to the string, replacing its current contents.

          string (1)	string& assign (const string& str);
       substring (2)	string& assign (const string& str, size_t subpos, size_t sublen = npos);
                                        // sublen > npos, no problem!!!!
        c-string (3)	string& assign (const char* s);
          buffer (4)	string& assign (const char* s, size_t n);
                                        // n > s.length, undefined behavior!!!!!!!
            fill (5)	string& assign (size_t n, char c);
           range (6)	template <class InputIterator>
                        string& assign (InputIterator first, InputIterator last);
 initializer list(7)	string& assign (initializer_list<char> il);
            move (8)	string& assign (string&& str) noexcept;


Exception safety
For the move assign (8), the function does not throw exceptions (no-throw guarantee).
In all other cases, there are no effects in case an exception is thrown (strong guarantee).

If s does not point to an array long enough, or if the range specified by [first,last) is not valid, it causes undefined behavior.

If subpos is greater than str's length, an out_of_range exception is thrown.
If the resulting string length would exceed the max_size, a length_error exception is thrown.
A bad_alloc exception is thrown if the function needs to allocate storage and fails.
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    string s="This is a sweet home.";

    //string (1) : string& assign (const string& str);
    string s1;
    s1.assign(s);
    cout << "s1=" << s1 << endl; // s1=This is a sweet home.

    //substring (2)	: string& assign (const string& str, size_t subpos, size_t sublen = npos);
    string s2;
    s2.assign(s, 8);
    cout << "s2=" << s2 << endl; // s2=a sweet home.

    s2.assign(s, 8, 20);  // sublen > npos, no problem!!!!
    cout << "s2=" << s2 << ", len=" << s2.size() << endl; // s2=a sweet home., len=13
 
    //c-string (3) : string& assign (const char* s);
    s2.assign("A amazing move!");
    cout << "s2=" << s2 << ", len=" << s2.size() << endl; // s2=A amazing move!, len=15

    //buffer (4) : string& assign (const char* s, size_t n);
    const char *p = "nonfiction";
    string s3;
    s3.assign(p, 3);
    cout << "s3=" << s3 << endl; // s3=non

    s3.assign(p, 24); // n > s.length, undefined behavior!!!!!!!
    cout << "s3=" << s3 << ", len=" << s3.size() << endl; // s3=nonfictions3=basic, len=24

    //fill (5)	string& assign (size_t n, char c);
    s3.assign(6, 'B');
    cout << "s3=" << s3 << endl; // s3=BBBBBB

    //range (6)	template <class InputIterator>
    //                    string& assign (InputIterator first, InputIterator last);
    list<char> l={'1', 'a', 'b','2'};
    s3.assign(l.begin(), l.end());
    cout << "s3=" << s3 << endl;  // s3=1ab2

    //initializer list(7)	string& assign (initializer_list<char> il);
    string s4;
    s4.assign({'t', 'b', 'r', 'y'});
    cout << "s4=" << s4 << endl;  // s4=tbry

    //move (8)	string& assign (string&& str) noexcept;

    return 0;
}
