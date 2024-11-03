#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // Insert at the beginning of the circular linked list
    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Points to itself, making it circular
        } else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at the end of the circular linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Points to itself, making it circular
        } else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
        }
    }

    // Delete from the beginning of the circular linked list
    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* curr = head;
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete curr;
        }
    }

    // Delete from the end of the circular linked list
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* curr = head;
            Node* prev = NULL;

            while (curr->next != head) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = head;
            delete curr;
        }
    }

    // Display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList obj;
    obj.insertAtEnd(10);
    obj.insertAtEnd(20);
    obj.insertAtEnd(30);
    obj.insertAtBeginning(5);
    obj.insertAtBeginning(2);

    obj.display();  // Output: 2 5 10 20 30

    obj.deleteAtBeginning();
    obj.display();  // Output: 5 10 20 30

    obj.deleteAtEnd();
    obj.display();  // Output: 5 10 20

    return 0;
}
