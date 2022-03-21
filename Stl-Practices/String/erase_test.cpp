/*
sequence (1)	string& erase (size_t pos = 0, size_t len = npos);
character (2)	iterator erase (const_iterator p);
range (3)	    iterator erase (const_iterator first, const_iterator last);

Erases part of the string, reducing its length:

Exception safety
For (1) and (3), if an exception is thrown, there are no changes in the string (strong guarantee).
For (2), it never throws exceptions (no-throw guarantee).

If pos is greater than the string length, an out_of_range exception is thrown.

An invalid range in (3), causes undefined behavior.
*/
#include <string>
#include <iostream>


using namespace std;

int main()
{
    string s = "A comprehensive workbook";

    // sequence (1)	: string& erase (size_t pos = 0, size_t len = npos)
    s.erase(18, 20);  // len > npos
    cout << "s=" << s << ", size=" << s.size() << endl; // s=A comprehensive wo, size=18
    //s.erase(20, 1); // pos > npos
    // cout << "s=" << s << endl;  // throwing an instance of 'std::out_of_range'

    // character (2) : iterator erase (const_iterator p);
    //s.erase(s.back());  // Core dump???? 
    s.erase(s.begin() + 1);  
    cout << "s=" << s << endl;  // s=Acomprehensive wo

    // range (3)  :  iterator erase (const_iterator first, const_iterator last);
    //string::iterator it = s.begin();  // using iterator also is ok.
    s.erase(s.cbegin(), s.cend());
    cout << "s=" << s << endl;  // s=

    return 0;
}


