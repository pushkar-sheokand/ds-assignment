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

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return -1;
        }
        int data = arr[front];
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return data;
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be EVEN!" << endl;
        return;
    }

    int half = n / 2;
    int firstHalf[SIZE], secondHalf[SIZE];
    int i = 0;

    for (i = 0; i < half; i++) {
        firstHalf[i] = q.dequeue();
    }

    for (int j = 0; j < half; j++) {
        secondHalf[j] = q.dequeue();
    }

    for (i = 0; i < half; i++) {
        q.enqueue(firstHalf[i]);
        q.enqueue(secondHalf[i]);
    }
}

int main() {
    Queue q;
    int n, value;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "\nOriginal Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "After interleaving: ";
    q.display();

    return 0;
}