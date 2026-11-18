#include <iostream>
using namespace std;
int n,graph[20][20], path[20];
bool found = false;
bool isSafe(int v, int pos)
{   
    if (graph[path[pos - 1]][v] == 0)
    {
        return false;
    }

    for (int i = 0; i < pos; i++) 
    { 
        if (path[i] == v)
        {
            return false;
        }
    }  
    return true;
}

void hamiltonianCycle (int pos)
{    
    if (pos == n) 
    {  
        if (graph[path[pos - 1]][path[0]] == 1) 
        {
            found = true;
            for (int i = 0; i < n; i++)
            {
                cout << path[i] << " ";
            }
            cout << path[0] << endl;    
        }    
        return;    
    }
    
    for (int v = 1; v < n; v++) 
    {
        if (isSafe(v, pos)) 
        {  
            path[pos] = v;
            hamiltonianCycle(pos + 1);
            path[pos] = -1;  
        }
    }
}

int main() 
{  
    cout << "Enter number of vertices: ";
    cin >> n;
    if (n < 3 || n > 20) 
    {  
        cout << "Enter vertices between 3 and 20.";     
        return 0; 
    }
    
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        {
            cin >> graph[i][j]; 
        } 
    }
    
    for (int i = 0; i < n; i++)
    {
        path[i] = -1;
    }
    
    path[0] = 0;
    cout << "\nHamiltonian Cycles:\n";
    hamiltonianCycle(1);
    if (!found)
    { 
        cout << "No Hamiltonian cycle exists.";
    }
    return 0;
}