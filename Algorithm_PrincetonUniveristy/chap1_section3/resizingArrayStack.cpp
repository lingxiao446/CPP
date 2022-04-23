/*
 Page#141:
 Resizing array implement:
 1) initialize array_size to 1.
 2) If N == array_size, resize the array to 2*array_size;
 3) If N == array_size / 4, resize the array to array_size / 2;
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

template <typename T>
class ResizingArrayStack
{
public:
    ResizingArrayStack(): N(0) {  v.resize(1); }

    bool empty() { return N == 0; }
    int size() { return N;}

    void push (T item) {
        if (N == v.size()) {
            resize(2 * v.size());
        }
        v[N++] = item;
    }

    T top() {
        return v[N-1];
    }

    void pop() {
        v.pop_back();
        N--;

        if (N > 0 && N <= v.size() / 4) {
            resize(v.size() / 2);
        } 
    }

private:
    void resize(int max) {
        vector<T> tmp(max);
        for (int i = 0; i < N; i++) {
            tmp[i] =  v[i];
        }
        v = move(tmp);

        cout << "N = " << N << ", v.size=" << v.size() << endl;
    }

private:
    vector<T> v;
    int N;
};

int main()
{
    ResizingArrayStack<string> myStack;

    string str;
    cout << "Please input strings: ";
    getline(cin, str);

    istringstream iss(str);
    string subs;
    while(iss >> subs) {
        if (subs == "-") {
            if (!myStack.empty()) {
                cout << myStack.top() << " ";
                myStack.pop();
            }
        } else {
            myStack.push(subs);
        }
    }
    cout << endl;

    return 0;
}

