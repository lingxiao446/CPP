/*
void push_back (char c);

void pop_back();                // If is a empty string, will cause undefined behavior.

void swap (string& str);
*/

#include <iostream>
#include <string>

using namespace std;


int main()
{
    string s("Hello ");
    s.push_back('W');
    s.push_back('o');
    s.push_back('r');
    s.push_back('l');
    s.push_back('d');
    cout << "s=" << s << endl; // s=Hello World

    s.pop_back();
    s.pop_back();
    s.pop_back();
    cout << "s=" << s << endl; // s=Hello Wo

    string s1;
    s1.swap(s);
    cout << "s=" << s << endl;   // s=
    cout << "s1=" << s1 << endl; // s1=Hello Wo

    return 0;
}
