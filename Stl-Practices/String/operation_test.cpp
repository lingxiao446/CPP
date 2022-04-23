/*
Get C string equivalent:
    const char* c_str() const noexcept; // Both string::data and string::c_str are synonyms and return the same value.

Get string data:
    const char* data() const noexcept;

Copy sequence of characters from string:
    size_t copy (char* s, size_t len, size_t pos = 0) const; // Exception safety
                                                                Strong guarantee: if an exception is thrown, there are no changes in the string.
                                                                If s does not point to an array long enough, it causes undefined behavior.
                                                                If pos is greater than the string length, an out_of_range exception is thrown.

Generate substring:
    string substr (size_t pos = 0, size_t len = npos) const; // Exception safety
                                                                Strong guarantee: if an exception is thrown, there are no changes in the string.
                                                                If pos is greater than the string length, an out_of_range exception is thrown.
                                                                A bad_alloc exception is thrown if the function needs to allocate storage and fails.
*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using std::cout;
using std::endl;
using std::string;

int main()
{
    // const char* c_str() const noexcept
    string s1 = "hello world";
    char s2[128];
    strcpy(s2, s1.c_str());
    printf("s2=%s.\n", s2); // s2=hello world.

    // const char* data() const noexcept
    string address = "Kenmore";
    char state[] = "Kenmore WA";
    if (strlen(address.data()) > strlen(state) ) {  // address's lenght is not greater than state.
        cout << "address's lenght is greater than state" << endl;
    } else {
        cout << "address's lenght is not greater than state." << endl;
    }

    // size_t copy (char* s, size_t len, size_t pos = 0) const
    char buff3[32];
    string s3 = "buffer or string";
    int len = s3.copy(buff3, 6, 0);
    printf("buff3=%s, its length=%d.\n", buff3, len); // buff3=buffer, its length=6.

    char buff32[8];
    //int len32 = s3.copy(buff32, 10, 5); // Note: undefined behavior.
    //printf("buff32=%s, its length=%d.\n", buff32, len32); // buff32=r or strin��E, its length=10. ... 

    // string substr (size_t pos = 0, size_t len = npos) const
    string s41 = "good and bad";
    string s42 = s41.substr(5, 10); // len > npos: used real length.
    cout << "s42=" << s42 << ", size=" << s42.size() << endl; // s42=and bad, size=7

    string s43 = s41.substr(5); // pos=5, len = npos.
    cout << "s43=" << s43 << endl; // s43=and bad

    //string s44 = s41.substr(20); // pos = 20 > npos
    //cout << "s44=" << s44 << endl; // throwing an instance of 'std::out_of_range'

    return 0;
}