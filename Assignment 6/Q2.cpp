#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << head->data << endl; 
}

int main() {
    Node* n1 = new Node{20, NULL};
    Node* n2 = new Node{100, NULL};
    Node* n3 = new Node{40, NULL};
    Node* n4 = new Node{80, NULL};
    Node* n5 = new Node{60, NULL};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1; 

    Node* head = n1;

    display(head);

    return 0;
}
