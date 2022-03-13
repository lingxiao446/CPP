/*
A 2D vector is a vector of the vector. Like 2D arrays, we can declare and assign values to a 2D vector! 

define and initialize a 2D vector methods
*/

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<vector<int>> v({{1, 2, 3, 4}, {5, 6, 7, 8}});  // error: ({}, {})

    //for (int i = 0; i < v.size(); i++) {   // correct
    //   for(const auto& e: v[i]) {          // correct
    // for (const auto& col: v) {
    for (const vector<int>& col: v) {
        for (const auto& e: col) {      
            cout << e << ",";       // 1,2,3,4,
                                    // 5,6,7,8,
        }
        cout << endl;
    }
    cout <<  endl;

    // item number is different for every column.
    vector<vector<int>> v2({{1, 2}, {3, 4, 5}, {6, 7, 8, 9}});
    cout << "v2 = " << endl;
    for (vector<int>& col: v2) {
        for (auto& e: col) {
            cout << e << ",";    // 1, 2                // Note: no '0' to fill..
                                 // 3, 4, 5
                                 // 6, 7, 8, 9
        }
        cout << endl;
    }
    cout << endl;

    // 
    int row = 3;
    vector<int> column = {1, 2, 3, 4, 5};
    vector<vector<int>> v3(row);
    for (int i = 0; i < row; i++) {
        v3[i] = column;
    }
    cout << "v3 = " << endl;
    for (vector<int>& c: v3) {
        for (auto& e: c) {
            cout << e << ",";    // 1, 2, 3, 4, 5,                 
                                 // 1, 2, 3, 4, 5,
                                 // 1, 2, 3, 4, 5,
        }
        cout << endl;
    }
    cout << endl;
    
    //
    int row4 = 2;
    int col4 = 3;
    // vector<vector<int>> v4(row4, vector<int>(col4));
    vector<vector<int>> v4(row4, vector<int>(col4, 5));
    cout << "v4 = " << endl;
    for (vector<int>& c: v4) {
        for (auto& e: c) {
            cout << e << ",";    // 5, 5, 5,                 
                                 // 5, 5, 5,
        }
        cout << endl;
    }
    cout << endl;   


    return 0;
}
