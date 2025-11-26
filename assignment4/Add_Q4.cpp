#include <iostream>
#include <queue>
using namespace std;

int countStudents(int students[], int sandwiches[], int n) {
    queue<int> q;
    for (int i = 0; i < n; i++) q.push(students[i]);

    int i = 0, count = 0;
    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            count = 0;
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.size();
}

int main() {
    int students[] = {1,1,0,0};
    int sandwiches[] = {0,1,0,1};
    int n = 4;
    cout << countStudents(students, sandwiches, n);
    return 0;
}

