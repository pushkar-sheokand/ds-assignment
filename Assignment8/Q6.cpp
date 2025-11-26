#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> heap;

public:
    void insert(int x)
    {
        heap.push_back(x);
        int i = heap.size() - 1;

        // Up-heapify
        while (i != 0 && heap[(i - 1) / 2] > heap[i])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int getMin()
    {
        if (heap.empty())
            return -1;
        return heap[0];
    }

    int extractMin()
    {
        if (heap.empty())
            return -1;

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);
        return root;
    }

    void heapify(int i)
    {
        int n = heap.size();
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;

        if (l < n && heap[l] < heap[smallest])
            smallest = l;
        if (r < n && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    void display()
    {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap pq;
    int choice, x;

    while (1)
    {
        cout << "\n1. Insert\n2. Get Min\n3. Extract Min\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            pq.insert(x);
            break;

        case 2:
            cout << "Min = " << pq.getMin() << endl;
            break;

        case 3:
            cout << "Extracted = " << pq.extractMin() << endl;
            break;

        case 4:
            pq.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
