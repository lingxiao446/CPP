/*
 <<Algorithm>:Page#129
 Dijkstra's Tow-Stack Algorithm for Expression Evaluation:
 For simplicity, assumes that expression is fully parenthesized,with numbers and characters separated by white space/
 1) Push operands onto the operans stack.
 2) Push operators onto operator stack.
 3) Ignore left parentheses.
 4) On encountering a right parentheses, pop an operator, pop the requisite number of operands,
    and pusj onto the operand stack the result of applying that operator to those operands.

 for example: 
    input: ( 1 + ( ( 2 + 3) * ( 4 * 5 ) ) )   
    result: 101        
*/
#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

bool isOperand(const string& str)
{
    if (str.empty()) {
        return false;
    }

    for (auto e: str) {
        if (!(e >= '0' && e <= '9')) {
            return false;
        }
    }

    return true;    
}

bool isOperator(const string& str) 
{
    if ( str == "+" || str == "-" || str == "*" || str == "/" || str == "sqrt") {
        return true;
    }

    return false;
}

double calculate(double v1, double v2, string op)
{
    if (op == "+") {
        return v1 + v2;
    }

    if (op == "-") {
        return v1 - v2;
    }

    if (op == "*") {
        return v1 * v2;
    }

    if (op == "/") {
        if (v2 == 0.0) {
            return 0;
        }
        return v1 / v2;
    }

    if (op == "sqrt") {
        return sqrt(v2);
    }

    return 0;
}

int main()
{
    string expr;

    cout << "please expression: ";
    getline(cin, expr);

    stack<double> vals;
    stack<string> ops;

    istringstream iss(expr);
    string subs;
     while (iss >>subs) {
        // Push operands onto the operans stack
        if (isOperand(subs)) {
            vals.push(atof(subs.c_str()));            
        } 
        // Push operators onto operator stack
        else if (isOperator(subs)) {
            ops.push(subs);
        } 
        // On encountering a right parentheses, pop an operator, pop the requisite number of operands,
        // and pusj onto the operand stack the result of applying that operator to those operands.
        else if (subs == ")" ) {
            string op = ops.top();
            ops.pop();

            double v1 = vals.top();
            vals.pop();

            double v2 = vals.top();
            vals.pop();

            double v = calculate(v1, v2, op);

            if (op == "sqrt") {
                vals.push(v2);
            }
            vals.push(v);
        }

    }

    cout << "result = " << vals.top() << endl;

    return 0;
}

