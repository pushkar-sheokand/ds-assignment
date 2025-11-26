#include <iostream>
using namespace std;

int adj[100][100];
int visited[100];

void dfs(int v, int V)
{
    visited[v] = 1;
    for (int i = 0; i < V; i++)
    {
        if (adj[v][i] && !visited[i])
            dfs(i, V);
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, V);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
