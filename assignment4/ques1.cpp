#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (rear == SIZE - 1) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot add " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << value << " added to queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot remove" << endl;
            return;
        }
        cout << arr[front] << " removed from queue" << endl;
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
        } else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
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
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 5);

    return 0;
}