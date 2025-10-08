#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Stack {
private:
    char arr[MAX_SIZE];
    int top;
public:
    Stack() { top = -1; }

    bool isFull() { return top == MAX_SIZE - 1; }
    bool isEmpty() { return top == -1; }

    void push(char c) {
        if (isFull()) return;
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const string& expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = s.pop();
            if (!isMatchingPair(topChar, ch)) return false;
        }
    }
    return s.isEmpty();
}

int main() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;
    if (isBalanced(input))
        cout << "Balanced parentheses" << endl;
    else
        cout << "Unbalanced parentheses" << endl;
    return 0;
}
