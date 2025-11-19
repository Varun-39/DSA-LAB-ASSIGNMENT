#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int isCircle; // 1 for circular, 0 for not circular
    cin >> isCircle;
    if (isCircle == 1 && tail != NULL) {
        tail->next = head;
    }

    Node* temp = head ? head->next : NULL;
    bool circular = false;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    if (temp == head && head != NULL) {
        circular = true;
    }

    if (circular) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}
