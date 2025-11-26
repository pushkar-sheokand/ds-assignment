#include <iostream>
#define INF 1000000
using namespace std;

int minDistance(int dist[], bool visited[], int V)
{
    int min = INF, min_index = -1;
    for (int i = 1; i <= V; i++)
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    return min_index;
}

int main()
{
    int N, E, K;
    cin >> N >> E >> K;
    int graph[101][101] = {0};
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    int dist[101];
    bool visited[101];
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[K] = 0;
    for (int count = 1; count <= N; count++)
    {
        int u = minDistance(dist, visited, N);
        if (u == -1)
            break;
        visited[u] = true;
        for (int v = 1; v <= N; v++)
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INF)
        {
            cout << -1 << endl;
            return 0;
        }
        if (dist[i] > ans)
            ans = dist[i];
    }
    cout << ans << endl;
    return 0;
}
