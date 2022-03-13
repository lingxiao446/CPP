/*
begin   Return iterator to beginning (public member function )
end     Return iterator to end (public member function )
rbegin  Return reverse iterator to reverse beginning (public member function )
rend    Return reverse iterator to reverse end (public member function )
cbegin  Return const_iterator to beginning (public member function )
cend    Return const_iterator to end (public member function )
crbegin Return const_reverse_iterator to reverse beginning (public member function )
crend   Return const_reverse_iterator to reverse end (public member function )
*/

#include <iostream>
#include <string>


using namespace std;

int main()
{
    string s1("User your smartphone for it.");

    string s2(s1.begin(), s1.end()) ;
    cout << "s2=" << s2 << endl; // s2=User your smartphone for it.

    string s3(s1.rbegin(), s1.rend());
    cout << "s3=" << s3 << endl; // s3=.ti rof enohptrams ruoy resU

    string::const_iterator cit1 = s1.cbegin();
    string::const_iterator cit2 = s1.cend();
    string s4(cit1, cit2);
    cout << "s4=" << s4 << endl; // s4=User your smartphone for it.

    string::const_reverse_iterator crit1 = s1.crbegin();
    string::const_reverse_iterator crit2 = s1.crend();
    string s5(crit1, crit2);
    cout << "s5=" << s5 << endl; // s5=.ti rof enohptrams ruoy resU

    return 0;
}