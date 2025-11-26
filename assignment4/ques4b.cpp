#include <iostream>
using namespace std;

#define SIZE 100

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
        }
        return false;
    }

    bool isFull() {
        if (rear == SIZE - 1) {
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return val;
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

class StackUsingOneQueue {
private:
    Queue q;

public:
    void push(int x) {
        q.enqueue(x);
        
        int s = q.size();
        for (int i = 0; i < s - 1; i++) {
            q.enqueue(q.dequeue());
        }

        cout << x << " added to stack" << endl;
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        int popped = q.dequeue();
        cout << popped << " removed from stack" << endl;
    }

    void peek() {
        if (q.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element is: " << q.getFront() << endl;
    }
};

int main() {
    StackUsingOneQueue st;
    int choice, val;

    do {
        cout << "\nStack Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                cout << "Bye!" << endl;
                break;
            default:
                cout << "Wrong choice!" << endl;
        }
    } while(choice != 4);

    return 0;
}