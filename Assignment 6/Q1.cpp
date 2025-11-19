#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = NULL; }
    
    void insertFirst(int val) {
        Node* temp = new Node();
        temp->data = val;
        temp->prev = NULL;
        temp->next = head;
        if (head != NULL) head->prev = temp;
        head = temp;
    }

    void insertLast(int val) {
        Node* temp = new Node();
        temp->data = val;
        temp->next = NULL;
        if (head == NULL) {
            temp->prev = NULL;
            head = temp;
            return;
        }
        Node* t = head;
        while (t->next != NULL) t = t->next;
        t->next = temp;
        temp->prev = t;
    }

    void insertAfter(int key, int val) {
        Node* t = head;
        while (t != NULL && t->data != key) t = t->next;
        if (t == NULL) return;
        Node* temp = new Node();
        temp->data = val;
        temp->next = t->next;
        temp->prev = t;
        if (t->next != NULL) t->next->prev = temp;
        t->next = temp;
    }

    void insertBefore(int key, int val) {
        Node* t = head;
        while (t != NULL && t->data != key) t = t->next;
        if (t == NULL) return;
        Node* temp = new Node();
        temp->data = val;
        temp->prev = t->prev;
        temp->next = t;
        if (t->prev != NULL) t->prev->next = temp;
        else head = temp;
        t->prev = temp;
    }

    void deleteNode(int key) {
        Node* t = head;
        while (t != NULL && t->data != key) t = t->next;
        if (t == NULL) return;
        if (t->prev != NULL) t->prev->next = t->next;
        else head = t->next;
        if (t->next != NULL) t->next->prev = t->prev;
        delete t;
    }

    bool search(int key) {
        Node* t = head;
        while (t != NULL) {
            if (t->data == key) return true;
            t = t->next;
        }
        return false;
    }

    void print() {
        Node* t = head;
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
public:
    CNode* head;
    CircularLinkedList() { head = NULL; }

    void insertFirst(int val) {
        CNode* temp = new CNode();
        temp->data = val;
        if (head == NULL) {
            temp->next = temp;
            head = temp;
            return;
        }
        CNode* t = head;
        while (t->next != head) t = t->next;
        t->next = temp;
        temp->next = head;
        head = temp;
    }

    void insertLast(int val) {
        CNode* temp = new CNode();
        temp->data = val;
        if (head == NULL) {
            temp->next = temp;
            head = temp;
            return;
        }
        CNode* t = head;
        while (t->next != head) t = t->next;
        t->next = temp;
        temp->next = head;
    }

    void insertAfter(int key, int val) {
        if (head == NULL) return;
        CNode* t = head;
        do {
            if (t->data == key) {
                CNode* temp = new CNode();
                temp->data = val;
                temp->next = t->next;
                t->next = temp;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void insertBefore(int key, int val) {
        if (head == NULL) return;
        CNode* t = head;
        CNode* prev = NULL;
        do {
            if (t->data == key) {
                CNode* temp = new CNode();
                temp->data = val;
                if (t == head) {
                    temp->next = head;
                    CNode* end = head;
                    while (end->next != head) end = end->next;
                    end->next = temp;
                    head = temp;
                } else {
                    temp->next = t;
                    prev->next = temp;
                }
                return;
            }
            prev = t;
            t = t->next;
        } while (t != head);
    }

    void deleteNode(int key) {
        if (head == NULL) return;
        CNode *curr = head, *prev = NULL;
        do {
            if (curr->data == key) {
                if (curr == head) {
                    if (head->next == head) {
                        delete head;
                        head = NULL;
                        return;
                    }
                    CNode* end = head;
                    while (end->next != head) end = end->next;
                    head = head->next;
                    end->next = head;
                    delete curr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    bool search(int key) {
        if (head == NULL) return false;
        CNode* t = head;
        do {
            if (t->data == key) return true;
            t = t->next;
        } while (t != head);
        return false;
    }

    void print() {
        if (head == NULL) {
            cout << endl;
            return;
        }
        CNode* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, sub, val, key, type;
    while (1) {
        cout << "1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter type: ";
        cin >> type;
        if (type == 3) break;
        cout << "1. Insert\n2. Delete\n3. Search\n4. Print\n5. Back\nEnter choice: ";
        cin >> choice;
        if (choice == 5) continue;
        if (type == 1) {
            switch (choice) {
                case 1:
                    cout << "1. First\n2. Last\n3. After\n4. Before\nEnter insert type: ";
                    cin >> sub;
                    cout << "Enter value: ";
                    cin >> val;
                    if (sub == 1) dll.insertFirst(val);
                    else if (sub == 2) dll.insertLast(val);
                    else if (sub == 3) {
                        cout << "Enter key: ";
                        cin >> key;
                        dll.insertAfter(key, val);
                    }
                    else if (sub == 4) {
                        cout << "Enter key: ";
                        cin >> key;
                        dll.insertBefore(key, val);
                    }
                    break;
                case 2:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    dll.deleteNode(val);
                    break;
                case 3:
                    cout << "Enter value to search: ";
                    cin >> val;
                    if (dll.search(val)) cout << "Found\n";
                    else cout << "Not Found\n";
                    break;
                case 4:
                    dll.print();
                    break;
            }
        } else if (type == 2) {
            switch (choice) {
                case 1:
                    cout << "1. First\n2. Last\n3. After\n4. Before\nEnter insert type: ";
                    cin >> sub;
                    cout << "Enter value: ";
                    cin >> val;
                    if (sub == 1) cll.insertFirst(val);
                    else if (sub == 2) cll.insertLast(val);
                    else if (sub == 3) {
                        cout << "Enter key: ";
                        cin >> key;
                        cll.insertAfter(key, val);
                    }
                    else if (sub == 4) {
                        cout << "Enter key: ";
                        cin >> key;
                        cll.insertBefore(key, val);
                    }
                    break;
                case 2:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    cll.deleteNode(val);
                    break;
                case 3:
                    cout << "Enter value to search: ";
                    cin >> val;
                    if (cll.search(val)) cout << "Found\n";
                    else cout << "Not Found\n";
                    break;
                case 4:
                    cll.print();
                    break;
            }
        }
    }
    return 0;
}
