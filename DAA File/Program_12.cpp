#include <iostream>
#include <algorithm>
using namespace std;
int parent[100];
int find(int i)
{   
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void unite(int i, int j)
{   
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

struct Edge {int u, v, w;};
bool compare(Edge a, Edge b)
{ 
    return a.w < b.w;
}

void kruskal(int n, Edge edges[], int e)
{   
    sort(edges, edges + e, compare);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    int count = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";
    
    for (int i = 0; i < e; i++)
    {   
        int a = find(edges[i].u);
        int b = find(edges[i].v);
        if (a != b)
        {
            cout << edges[i].u << " - "<< edges[i].v << " : "<< edges[i].w << endl;
            totalCost += edges[i].w;
            unite(a, b);
            count++;
            if (count == n - 1)
            {  
                break; 
            } 
        }
    }
    
    if (count == n - 1)
    {
        cout << "\nMinimum Cost = " << totalCost;
    }
    else
    {
        cout << "\nSpanning tree is not possible.";
    }
}

int main()
{   
    int n, e;
    Edge edges[100];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;  
    }

    kruskal(n, edges, e);
    return 0;
}