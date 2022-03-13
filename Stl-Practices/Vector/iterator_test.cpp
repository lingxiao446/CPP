/*
begin --  Return iterator to beginning (public member function )
end   --  Return iterator to end (public member function )

rbegin -- Return reverse iterator to reverse beginning (public member function )
rend --   Return reverse iterator to reverse end (public member function )

cbegin -- Return const_iterator to beginning (public member function )
cend   -- Return const_iterator to end (public member function )

crbegin -- Return const_reverse_iterator to reverse beginning (public member function )
crend   -- Return const_reverse_iterator to reverse end (public member function )
*/

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1({1, 2, 3, 4, 5});

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        *it = *it + 10;
    }

    cout << "v1 = ";     // v1 = 11,12,13,14,15,
    for (vector<int>::const_iterator cit = v1.cbegin(); cit != v1.cend(); cit++) {
        cout << *cit << ","; 
    }
    cout << endl;

    // vector<int>::reverse_iterator
    vector<int> v2(v1.rbegin(), v1.rend());
    cout << "from begin to end, v2 = ";  // from begin to end, v2 = 15, 14, 13, 12, 11, 
    for (vector<int>::const_iterator cit = v2.cbegin(); cit != v2.cend(); cit++) {
        cout << *cit <<", ";
    }
    cout << endl;

    cout << "from end to begin, v2 = "; // from end to begin, v2 = 11, 12, 13, 14, 15, 
    for (vector<int>::const_reverse_iterator cit = v2.crbegin(); cit != v2.crend(); cit++) {
        cout << *cit <<", ";
    }
    cout << endl;

    return 0;
}


