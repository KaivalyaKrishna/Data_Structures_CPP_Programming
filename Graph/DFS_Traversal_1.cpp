#include <iostream>
#include <vector>
using namespace std;

void DFS_Visit(vector<int> Adj[], vector<int> &status, int i)
{
    status[i] = 1;
    cout << i << " ";

    for (int j = 0; j < Adj[i].size(); j++)
    {
        if (status[Adj[i][j]] == 0)
        {
            DFS_Visit(Adj, status, Adj[i][j]);
        }
    }
}

void DFS(vector<int> Adj[], int V)
{
    vector<int> status(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (status[i] == 0)
        {
            DFS_Visit(Adj, status, i);
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<int> Adj[v];

    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cout << "Enter the endpoints of edge " << i + 1 << ": ";
        cin >> src >> dest;

        Adj[src].push_back(dest);
        Adj[dest].push_back(src); // For undirected graph
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < Adj[i].size(); j++)
        {
            cout << Adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nOrder of DFS is: ";
    DFS(Adj, v);

    return 0;
}