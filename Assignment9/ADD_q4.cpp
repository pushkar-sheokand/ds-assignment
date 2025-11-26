#include <iostream>
using namespace std;

int m, n;
char grid[20][20];
bool visited[20][20];

void dfs(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return;
    if (grid[i][j] == '0' || visited[i][j])
        return;
    visited[i][j] = true;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;
    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '1' && !visited[i][j])
            {
                dfs(i, j);
                count++;
            }
    cout << count << endl;
    return 0;
}
