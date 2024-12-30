#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class stack {
    private:
        node *top;

    public:
        stack() { top = nullptr; }

    void push(int data) {
        node *newnode = new node();
        newnode->data = data;
        newnode->next = top;
        top = newnode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isempty() { return (top == nullptr); }

    void display() {
        node *curr = top;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void reverseStack() {
        node *prev = nullptr;
        node *current = top;
        node *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        top = prev;
    }
};


int main() {
    stack obj;
    obj.push(5);
    obj.push(6);
    obj.push(7);
    obj.push(8);

    cout << "Before reversing the stack: ";
    obj.display();

    obj.reverseStack();

    cout << "After reversing the stack: ";
    obj.display();

    return 0;
}
