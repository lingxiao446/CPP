/*
string (1)	 :          string& operator= (const string& str);
c-string (2) :          string& operator= (const char* s);
character (3) :         string& operator= (char c);
initializer list (4):   string& operator= (initializer_list<char> il);
move (5)	:           string& operator= (string&& str) noexcept;
*/
#include <iostream>
#include <string>

using namespace std;


int main()
{
    // string (1) : string& operator= (const string& str)
    string s("Hello world.");
    string s1 = s;
    cout << "s1=" << s1 << endl; // s1=Hello world.

    // c-string (2) : string& operator= (const char* s)
    char s21[] = "Welcome to C++ world.";
    string s22 = s21;
    cout << "s22=" << s22 << endl; // s22=Welcome to C++ world.
    cout << "address: s21=" << &s21 << ", s22=" << &s22 << endl; // address: s21=0x3dbbffa98, s22=0x3dbbffa70

    // character (3) : string& operator= (char c)
    string s3 ;
    s3 = 'A';   // can NOT string s3 = 'A' !!!!!!
    cout << "s3=" << s3 << endl; // s3=A

    // initializer list (4):   string& operator= (initializer_list<char> il)
    string s4 = {'a', 'b', 'c'}; // error:() or ({})
    cout << "s4=" << s4 << endl; // s4=abc
    string s41;
    s41 = ('a', 'B', 'C'); 
    cout << "s41=" << s41 << endl; // s41=C ????
    cout << "s41.size()=" << s41.size() << endl; // s41.size()=1

    // move (5) : string& operator= (string&& str) noexcept;
    string s5 = move(s4);
    cout << "s4=" << s4 << ", s5=" << s5 << endl; // s4=, s5=abc

    return 0;
}