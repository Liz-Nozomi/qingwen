#include <bits/stdc++.h>
using namespace std;

struct Node {
    int num;
    char op;
    bool isOp;
};

map<char, int> priority;

vector<Node> toNodeVector(string expr) {
    vector<Node> nodes;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') {
            continue;
        }
        if (expr[i] >= '0' && expr[i] <= '9') {
            Node numNode;
            numNode.isOp = false;
            numNode.num = expr[i] - '0';
            nodes.push_back(numNode);
        } else {
            Node opNode;
            opNode.isOp = true;
            opNode.op = expr[i];
            nodes.push_back(opNode);
        }
    }
    return nodes;
}

vector<Node> toPostfixVector(vector<Node> infix) {
    vector<Node> postfix;
    stack<Node> opStack;
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i].isOp) {
            while (!opStack.empty() && priority[infix[i].op] <= priority[opStack.top().op]) {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(infix[i]);
        } else {
            postfix.push_back(infix[i]);
        }
    }
    while (!opStack.empty()) {
        postfix.push_back(opStack.top());
        opStack.pop();
    }
    return postfix;
}

double eval(vector<Node> postfix) {
    stack<double> numStack;
    for (int i = 0; i < postfix.size(); i++) {
        if (!postfix[i].isOp) {
            numStack.push(postfix[i].num);
        } else {
            double num2 = numStack.top();
            numStack.pop();
            double num1 = numStack.top();
            numStack.pop();
            if (postfix[i].op == '+') {
                numStack.push(num1 + num2);
            } else if (postfix[i].op == '-') {
                numStack.push(num1 - num2);
            } if (postfix[i].op == '*') {
                numStack.push(num1 * num2);
            } if (postfix[i].op == '/') {
                numStack.push(num1 / num2);
            }
        }
    }
    return numStack.top();
}

int main() {
    priority['+'] = priority['-'] = 0;
    priority['*'] = priority['/'] = 1;
    string expr;
    getline(cin, expr);
    vector<Node> infix = toNodeVector(expr);
    vector<Node> postfix = toPostfixVector(infix);
    printf("%.2f", eval(postfix));
    return 0;
}