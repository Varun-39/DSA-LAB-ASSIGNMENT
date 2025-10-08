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
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }
};

void reverseString(string &str) {
    Stack s;
    for (char c : str) s.push(c);
    for (int i = 0; i < str.size(); i++)
        str[i] = s.pop();
}

int main() {
    string myString = "DataStructure";
    cout << "Original string: " << myString << endl;
    reverseString(myString);
    cout << "Reversed string: " << myString << endl;
    return 0;
}
