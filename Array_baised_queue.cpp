#include <iostream>
using namespace std;

#define MAX_SIZE 100

class LinearQueue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    LinearQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++; 
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();  // Output: 10 20 30

    q.dequeue();
    q.display();  // Output: 20 30

    cout << "Front element: " << q.peek() << endl;  // Output: 20
    return 0;
}




//for circular



// void enqueue(int x) {
//     // Check if the queue is full
//     if ((rear + 1) % MAX_SIZE == front) {
//         cout << "Queue Overflow\n";
//         return; // Cannot enqueue, queue is full
//     }

//     // If the queue is empty, initialize front and rear
//     if (isEmpty()) {
//         front = 0; // Set front to 0 when the first element is added
//     }

//     // Update rear using modulo to wrap around
//     rear = (rear + 1) % MAX_SIZE;
//     arr[rear] = x; // Add the new element to the rear
// }
