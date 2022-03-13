/*
string (1)	            string& operator+= (const string& str);
c-string (2)	        string& operator+= (const char* s);
character (3)	        string& operator+= (char c);
initializer list (4)	string& operator+= (initializer_list<char> il);
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1("Hello");
    string s2 = "World";

    // character(3) :string& operator+= (char c)
    s1 += ' ';

    // string (1): string& operator+= (const string& str)
    s1 += s2;

    cout << "s1=" << s1 << endl; // s1=Hello World

    // c-string (2) : string& operator+= (const char* s)
    s1 += ", Good morning";
    cout << "s1=" << s1 << endl; // s1=Hello World, Good morning

    // initializer list (4):	string& operator+= (initializer_list<char> il)
    string s3 = "How are";
    s3 += {' ', 'y', 'o', 'u'};  // compile Error:({}); only get last character:() !!!!!!
    cout << "s3=" << s3 << endl; // s3=How are you

    s3 += (' ', 'd', 'e', 'a', 'r'); // only get last character:() !!!!!!
    cout << "s3=" << s3 << endl; // 3=How are your

    return 0;
}