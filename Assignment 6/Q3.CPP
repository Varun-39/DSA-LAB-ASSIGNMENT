#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 1;
    second->data = 2;
    third->data = 3;

    first->next = second;
    first->prev = NULL;

    second->next = third;
    second->prev = first;

    third->next = NULL;
    third->prev = second;

    int count = 0;
    Node* temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Size of doubly linked list is: " << count << endl;
    return 0;
}
