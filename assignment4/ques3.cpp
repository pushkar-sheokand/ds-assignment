#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
private:
    char arr[SIZE];
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

    void enqueue(char ch) {
        if (isFull()) return;
        if (front == -1) front = 0;
        rear++;
        arr[rear] = ch;
    }

    char dequeue() {
        if (isEmpty()) return '\0';
        char data = arr[front];
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return data;
    }

    char getFront() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

void firstNonRepeating(string str) {
    Queue q;
    int freq[26] = {0};

    cout << "Output: ";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        freq[ch - 'a']++;

        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.getFront() - 'a'] > 1) {
            q.dequeue();
        }

        if (q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q.getFront() << " ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    firstNonRepeating(str);
    return 0;
}