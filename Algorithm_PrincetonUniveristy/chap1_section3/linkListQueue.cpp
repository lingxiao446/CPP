/*
 Page#151
 implement queue with Linked List:
 1) add item to the end of the list.
 2) remove item from the beginning of the list.

 Note:
 1) no-throw guarantee for standard non-empty containers. (exit)
 2) in STL, using dequeue to implement queue.
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
struct Node {
    T item;
    Node *next;

    //Node(): next(nullptr);
    Node(T _item): item(_item), next(nullptr) {}
};

template <typename T>
class Queue {
public:
    Queue<T>(): head(), tail(), N(0) {}

    bool empty() { return head == nullptr; }
    int size() { return N; }

    void push(T item) {
        Node<T> *node = new Node(item);
        if (tail) {
            tail->next = node;
        }
        tail = node;

        if (empty()) {
            head = tail;
        }

        N++;
    }

    T front() {
        try {
            if (!head) {
                throw head;
            }
        } catch (exception& e) {
            exit(0);
        }

        return head->item;
    }

    void pop() {
        if (empty()) {
            return;
        }

        Node<T> *node = head;
        head = head->next;
 
        node->next = nullptr;
        delete node;

        if (empty()) {
            tail = nullptr;
        }

        N--;
    }
    
private:
    Node<T> *head;
    Node<T> *tail;
    int N;
};

int main()
{
    Queue<string> q;

    string str;
    cout << "Please input strings: ";
    getline(cin, str);

    istringstream iss(str);
    string subs;
    while(iss >> subs) {
        if (subs == "-") {
            if (!q.empty()) {
                cout << q.front() << " ";
                q.pop();
            }
        } else {
            q.push(subs);
        }
    }
    cout << endl;

    return 0;    
}

