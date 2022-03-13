
/*
default (1)	            string();
copy (2)	            string (const string& str);
substring (3)           string (const string& str, size_t pos, size_t len = npos); // if n is greater than the length of s, there will ba some cabager,
from c-string (4)       string (const char* s);
from buffer (5)	        string (const char* s, size_t n);  // if n is greater than the length of s, there will ba some cabager,
fill (6)	            string (size_t n, char c);
range (7)	            template <class InputIterator>    // the first param should be a string .??
                        string  (InputIterator first, InputIterator last); // if the last is greater than the real legth, then...
initializer list (8)	string (initializer_list<char> il);
move (9)	            string (string&& str) noexcept;
*/
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    // default (1): string()
    string s1;
    cout << "empty s1, size=" << s1.size() << ", capacity="<< s1.capacity() << ", max_size=" << s1.max_size() << endl;
    // empty s1, size=0, capacity=15, max_size=4611686018427387903

    // copy (2) : string (const string& str)
    string s21 = "copy string";
    string s22(s21);
    cout << "s2=" << s22 << endl;
    cout << "size=" << s22.size() << ", capacity=" << s22.capacity() << ", max_size=" << s22.max_size() << endl;
    // s2=copy string
    // size=11, capacity=15, max_size=4611686018427387903

    // substring (3) : string (const string& str, size_t pos, size_t len = npos) 
    string s31(s21, 4);
    string s32(s21, 2, 6);
    string s33(s21, 0, 4);
    cout << "s31=" << s31 << endl;  // s31= string
    cout << "s32=" << s32 << endl;  // s32=py str
    cout << "s33=" << s33 << endl;  // s33=copy

    //string s34(s21, 5, 12); 
    //cout << "s34=" << s34 << endl;    // throw a exception: terminate called after throwing an instance of 'std::out_of_range'
                                        //  what():  basic_string::basic_string: __pos (which is 12) > this->size() (which is 11)
    //string s35(s21, 12, 3);            
    //cout << "s35=" << s35 << endl;    // throw a exception: terminate called after throwing an instance of 'std::out_of_range'
                                        // what():  basic_string::basic_string: __pos (which is 12) > this->size() (which is 11)
 
    // from c-string (4) : string (const char* s)
    string s4("constructor from C-style string");
    cout << "s4=" << s4 << endl;
    cout << "size=" << s4.size() << ", capacity=" << s4.capacity() << ", max_size=" << s4.max_size() << endl;
    // s4=constructor from C-style string
    // size=31, capacity=31, max_size=4611686018427387903

    // from buffer (5) : string (const char* s, size_t n)
    // Note: compare with substring: in here, the first param is char[], in substring it is string.
    char s51[] = "I am a c string.";
    string s52(s51, 6);
    cout << "s52=" << s52 << endl; // s52=I am a

    string s53(s51, 24);  // if the len is greater than s51, there will be filled something after s53.!!!!!!
    cout << "s53=" << s53 << endl; // s53=I am a c string.b��
    cout << "s53, length=" << s53.length() << ", size=" << s53.size() << ", capacity=" << s53.capacity() << endl;
    // s53, length=24, size=24, capacity=24 //??????
    for (auto& c: s53) {
        cout << c << ","; // I, ,a,m, ,a, ,c, ,s,t,r,i,n,g,.,,,,P,,,,,
    }
    cout << endl;

    s53 += "append.";
    cout << "s53=" << s53 << endl; // s53=I am a c string.b��append.
    cout << "s53, length=" << s53.length() << ", size=" << s53.size() << ", capacity=" << s53.capacity() << endl;
    // s53, length=31, size=31, capacity=48
    for (auto& c: s53) {
        cout << c << ","; // I, ,a,m, ,a, ,c, ,s,t,r,i,n,g,.,,,,P,,,,,a,p,p,e,n,d,.,
    }
    cout << endl;

    // fill (6): string (size_t n, char c)
    string s6(12, 'N');
    cout << "s6=" << s6 << endl; // s6=NNNNNNNNNNNN

    // range (7): string  (InputIterator first, InputIterator last)
    string s71("Test InputerIterator.");
    string s72(s71.begin(), s71.begin()+4);  // the first param should be a string .
    cout << "s72=" << s72 << endl; // s72=Test

    string s73(s71.begin() + 5, s71.begin() + 30);
    cout << "s73=" << s73 << endl; // s73=InputerIterator.��������
    cout << "s73, size=" << s73.size() << endl;  // s73, size=25

    // initializer list (8):	string (initializer_list<char> il)
    string s8({'1', '2', '3'});
    cout << "s8=" << s8 << endl; // s8=123

    // move (9)	  :          string (string&& str) noexcept;
    string s9(move(s8));
    cout << "s8=" << s8 << ", size=" << s8.size() << endl; // s8=, size=0
    cout << "s9=" << s9 << endl; // s9=123

    return 0;
}



