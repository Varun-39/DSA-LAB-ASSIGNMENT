#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        Node* newNode = new Node();
        newNode->data = ch;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* left = head;
    Node* right = tail;
    bool isPalin = true;
    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            isPalin = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }

    if (isPalin) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}
