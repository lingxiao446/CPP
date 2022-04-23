/*
   string (1)	size_t find (const string& str, size_t pos = 0) const noexcept;
 c-string (2)   size_t find (const char* s, size_t pos = 0) const;
   buffer (3)	size_t find (const char* s, size_t pos, size_type n) const;
character (4)	size_t find (char c, size_t pos = 0) const noexcept;

Searches the string for the first occurrence of the sequence specified by its arguments.

Exception safety
    If s does not point to an array long enough, it causes undefined behavior.
    Otherwise, the function never throws exceptions (no-throw guarantee).

*/

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

int main()
{
    string s = "We're reading some boring old book, by some boring old dude.";

    // string (1) : size_t find (const string& str, size_t pos = 0) const noexcept;
    string s1 = "boring";
    int pos1 = s.find(s1);
    if (pos1 != string::npos){
        cout << "The first " << s1 << " in " << pos1 << endl; // The first boring in 19

        int pos2 = s.find(s1, pos1+1);
        if (pos2 != string::npos) {
            cout << "The second " << s1 << " in " << pos2 << endl; // The second boring in 44
        }
    }

    // c-string (2) :  size_t find (const char* s, size_t pos = 0) const;


    // buffer (3) :	size_t find (const char* s, size_t pos, size_type n) const;

    // character (4) : size_t find (char c, size_t pos = 0) const noexcept;


}