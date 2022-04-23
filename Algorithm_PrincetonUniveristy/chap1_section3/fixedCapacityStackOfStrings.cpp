/*
 Fixed-capacity stack:
  1) The items in the array are in their insertion order.
  2) The stack is empty when N is 0.
  3) The top of the stack(if it is nonempty) is at a[N-1].

*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class FixedCapacityStackOfStrings
{
public:
    FixedCapacityStackOfStrings(int cap) : N(0) {
        a.resize(cap);                             // CAN NOT use reverse().
        cout << "a.size=" << a.size() << endl;
    }

    bool empty() { return N == 0; }
    int size() { return N; }

    void push(const string& item) { a[N++] = item; }
    string top() { return a[N-1]; }  // assume N > 0.
    void pop() { 
        a.pop_back(); 
        N--;
    }

private:
    vector<string> a;
    int N;    
};

/*
  Test: reads strings from standard input and pushed each string into a stack, 
  unless it is "-", when it pops the stack and prints the result.
*/
int main()
{
    FixedCapacityStackOfStrings s(100);

    string str;
    cout << "Please input strings: ";
    getline(cin, str);

    istringstream iss(str);
    string subs;
    while(iss >> subs) {
        if (subs == "-") {
            if (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        } else {
            s.push(subs);
        }
    }
    cout << endl;

    return 0;
}

