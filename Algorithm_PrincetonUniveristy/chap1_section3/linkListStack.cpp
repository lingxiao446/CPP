/*
 Page#149
 Linked-list implemention:
 1) Insert at the beginning.
 2) Remove from the beginning.

 Note:
 1) no-throw guarantee for standard non-empty containers.  
 2) in STL, using dequeue to implement stack.
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
struct Node{
    T item;
    Node *next;

    Node(): item(nullptr) {}
    Node(T _item): item(_item), next(nullptr) {}
};

template <typename T>
class Stack {
public:
    Stack(): first(), N(0) {}

    bool empty () { return first == nullptr;}
    int size () { return N; }

    void push (T _item) {
        Node<T> *node = new Node(_item);
        node->next = first;
        first = node;
        N++;
    }

    T top () { return first->item; }
    void pop () {
        if (!first) {
            return;
        }

        Node<T> *node = first;
        first = first->next;

        node->next = nullptr;
        delete node;
    }

private:
    Node<T> *first;
    int N;
};


int main()
{
    Stack<string> s;

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
