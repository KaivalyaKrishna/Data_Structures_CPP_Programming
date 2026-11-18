#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX
void prim (int n, vector<vector<int>>& graph) 
{
    vector<int> key(n, INF);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    key[0] = 0;
    int cost = 0;
    for (int count = 0; count < n; count++) 
    {
        int u = -1;
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;   
            }
        }
        
        if (u == -1 || key[u] == INF) 
        {
            cout << "MST cannot be formed.";
            return;      
        }

        visited[u] = true;
        cost += key[u];
        for (int v = 0; v < n; v++) 
        {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) 
            {
                key[v] = graph[u][v];
                parent[v] = u; 
            } 
        } 
    }
    
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 1; i < n; i++) 
    {
        cout << parent[i] << " - " << i<< " : " << graph[i][parent[i]] << endl;
    }
    cout << "Minimum Cost = " << cost << endl;
}

int main() 
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> graph (n, vector<int>(n));
    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> graph[i][j]; 
        }   
    }
    prim (n, graph);
    return 0;
}
