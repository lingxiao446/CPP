/*
      char& operator[] (size_t pos);
const char& operator[] (size_t pos) const;         // If pos >= size(), will cause undefined behavior.

      char& at (size_t pos);
const char& at (size_t pos) const;                 // If pos >= size(),throwing an out_of_range exception.

      char& back();
const char& back() const;                          // If is empty, will cause undefined behavior.

      char& front();
const char& front() const;                         // If is empty, will cause undefined behavior.
*/

#include <iostream>
#include <string>


using namespace std;

int main()
{
    string s("hello World!");
    cout << "s=" << s << endl; // s=hello World!

    s[0] = 'H';
    cout << "s=" << s << endl; // s=Hello World!
    s[30] = 'W';
    cout << "s=" << s << endl; // s=Hello World!   Danger!!!!!!! out of boundary!!!

    s.at(4) = '-';
    cout << "s=" << s << endl; // s=Hell- World!
    //s.at(15) = '$';             
    //cout << "s=" << s << endl; // terminate called after throwing an instance of 'std::out_of_range'
                               // what():  basic_string::at: __n (which is 15) >= this->size() (which is 12)

    s.front() = 'P';
    s.back() = 'T';
    cout << "s=" << s << endl; // s=Pell- WorldT
 
    s.clear();
    s.front() = 'K';
    s.back() = 'G';
    cout << "s=" << s << endl; // s= Danger!!!!!!! out of boundary!!!

    // should use checking:
    if (!s.empty()) {
        s.front() = 'K';
        s.back() = 'G';
        cout << "s=" << s << endl;        
    }

    return 0;
}

