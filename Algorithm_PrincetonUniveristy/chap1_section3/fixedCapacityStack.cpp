/*
 Generics: using tamplate 
*/

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class FixedCapacityStack
{
public:
    FixedCapacityStack<T>(int cap): N(0) {
        v.resize(cap);
    }

    bool empty() { return N == 0; }
    int size() { return N; }

    void push(T& item) { v[N++] = item; }
    T top() { return v[N-1]; }  // assume N > 0.
    void pop() { 
        v.pop_back(); 
        N--;
    }

private:
    vector<T> v;
    int N;
};

/*
  Test: reads strings from standard input and pushed each string into a stack, 
  unless it is "-", when it pops the stack and prints the result.
*/
int main()
{
    FixedCapacityStack<string> s(100);

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

    // if input is even, print.
    FixedCapacityStack<int> iStack(100);

    string strInt;
    cout << "Please input integers: ";
    getline(cin, strInt);

    istringstream isInt(strInt);
    string subs1;
    while (isInt >> subs1) {
        int ii = stoi(subs1);
        iStack.push(ii);
    }

    cout << "Even numbers=";
    while (!iStack.empty()) {
        if (iStack.top() %2 == 0) {
            cout << iStack.top() << " ";
        }
        iStack.pop();
    }
    cout << endl;

    return 0;
}

