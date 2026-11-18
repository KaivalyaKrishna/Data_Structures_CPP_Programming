#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX
void dijkstra(int n, vector<vector<int>>& graph, int src) 
{
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) 
    {
        int u = -1;
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
            {    
                u = i;      
            }
        }

        visited[u] = true;
        for (int v = 0; v < n; v++) 
        {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "Vertex " << i << " : ";
        if (dist[i] == INF)
        {
            cout << "Not reachable";
        }
        else 
        {
            cout << dist[i];
        }
        cout << endl; 
    }
}
int main() 
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> graph[i][j]; 
        } 
    }
    int src;
    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> src;
    if (src < 0 || src >= n) 
    {
        cout << "Invalid source vertex.";
        return 0;  
    }
    dijkstra (n, graph, src);
    return 0;
}