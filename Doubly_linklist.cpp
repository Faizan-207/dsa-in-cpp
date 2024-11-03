#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = NULL;

        if (head == NULL) {
            newNode->next = NULL;
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
    }

    void insertAtPosition(int position, int data) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node();
        newNode->data = data;

        Node* curr = head;
        int count = 0;

        while (curr != NULL && count < position - 1) {
            curr = curr->next;
            count++;
        }

        if (curr == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        newNode->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = newNode;
        }
        newNode->prev = curr;
        curr->next = newNode;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* curr = head;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = NULL;
        delete temp;
    }

    void deleteAtPosition(int position) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 0) {
            deleteAtBeginning();
            return;
        }

        Node* current = head;
        int count = 0;

        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == NULL || current->next == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = current;
        }
        delete temp;
    }

    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList obj;
    obj.insertAtEnd(50);
    obj.insertAtEnd(30);
    obj.insertAtEnd(70);
    obj.insertAtBeginning(20);
    obj.insertAtBeginning(10);
    obj.insertAtPosition(3, 40);
    obj.printList(); // Output: 10 20 30 40 50 70

    obj.deleteAtBeginning();
    obj.deleteAtEnd();
    obj.deleteAtPosition(2);
    obj.printList(); // Output: 20 30 50

    return 0;
}
