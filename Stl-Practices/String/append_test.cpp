/*
Extends the string by appending additional characters at the end of its current value:

         string (1)	    string& append (const string& str);
      substring (2)	    string& append (const string& str, size_t subpos, size_t sublen = npos); // if sublen>npos?
       c-string (3)	    string& append (const char* s);
         buffer (4)	    string& append (const char* s, size_t n);
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

using namespace std;

int main()
{


    return 0;
}