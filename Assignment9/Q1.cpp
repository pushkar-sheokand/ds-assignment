#include <iostream>
#define INF 1000000
using namespace std;

int V;
int adj[20][20];

void bfs(int start)
{
    int queue[20], front = 0, rear = 0;
    bool visited[20] = {0};
    queue[rear++] = start;
    visited[start] = true;
    while (front < rear)
    {
        int u = queue[front++];
        cout << u << " ";
        for (int v = 0; v < V; v++)
            if (adj[u][v] && !visited[v])
            {
                queue[rear++] = v;
                visited[v] = true;
            }
    }
    cout << endl;
}

void dfs_util(int u, bool visited[])
{
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !visited[v])
            dfs_util(v, visited);
}

void dfs(int start)
{
    bool visited[20] = {0};
    dfs_util(start, visited);
    cout << endl;
}

int find(int parent[], int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int parent[], int x, int y)
{
    int a = find(parent, x);
    int b = find(parent, y);
    parent[a] = b;
}

void kruskal()
{
    int edges[100][3], ecount = 0;
    for (int i = 0; i < V; i++)
        for (int j = i; j < V; j++)
            if (adj[i][j])
            {
                edges[ecount][0] = i;
                edges[ecount][1] = j;
                edges[ecount][2] = adj[i][j];
                ecount++;
            }
    for (int i = 0; i < ecount - 1; i++)
        for (int j = i + 1; j < ecount; j++)
            if (edges[i][2] > edges[j][2])
            {
                int temp0 = edges[i][0], temp1 = edges[i][1], temp2 = edges[i][2];
                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];
                edges[j][0] = temp0;
                edges[j][1] = temp1;
                edges[j][2] = temp2;
            }
    int parent[20];
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int cost = 0;
    for (int i = 0; i < ecount; i++)
    {
        int u = edges[i][0], v = edges[i][1];
        int set_u = find(parent, u);
        int set_v = find(parent, v);
        if (set_u != set_v)
        {
            cost += edges[i][2];
            union_set(parent, set_u, set_v);
        }
    }
    cout << cost << endl;
}

void prim()
{
    int key[20], mstSet[20] = {0}, parent[20];
    for (int i = 0; i < V; i++)
        key[i] = INF;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int min = INF, u = -1;
        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adj[u][v];
            }
    }
    int cost = 0;
    for (int i = 1; i < V; i++)
        cost += adj[i][parent[i]];
    cout << cost << endl;
}

void dijkstra(int start)
{
    int dist[20], visited[20] = {0};
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[start] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int min = INF, u = -1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] < min)
            {
                min = dist[v];
                u = v;
            }
        if (u == -1)
            break;
        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (adj[u][v] && !visited[v] && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }
    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main()
{
    int E;
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    bfs(0);
    dfs(0);
    kruskal();
    prim();
    dijkstra(0);
    return 0;
}
