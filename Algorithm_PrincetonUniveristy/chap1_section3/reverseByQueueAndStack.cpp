/*
 <<Algorithm>>:Page#127: Reverse
 Given a string, using queue and stack to reverse it.
*/

#include <string>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    string src;
    cout << "Input a string: ";
    cin >> src;
    cout << src << endl;

    queue<char> q;
    int i =0;
    while(i < src.size()) {
        q.push(src[i]);  
        i++;     
    } 

    stack<char> s;
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
