#include <iostream>
using namespace std;
int n, minCost = 999999, cost[10][10], bestPath[10], path[10];

void tsp (int path[], bool visited[], int count, int current, int totalCost)
{
    if (count == n)
    {   
        int finalCost = totalCost + cost[current][0];
        if (finalCost < minCost) 
            {
                minCost = finalCost;
                for (int i = 0; i < n; i++)
                {    
                    bestPath[i] = path[i];  
                } 
            }     
            
            return;    
        }
    
        for (int i = 1; i < n; i++)
        {
            if (!visited[i]) 
            {   
                visited[i] = true;
                path[count] = i;
                tsp (path, visited, count + 1, i, totalCost + cost[current][i]);
                visited[i] = false;     
            }
        }
    }

int main()
{   
    cout << "Enter number of cities: ";
    cin >> n;
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < n; j++)
        { 
            cin >> cost[i][j];
        }
    }
    
    bool visited[10] = {false};
    path[0] = 0;
    visited[0] = true;
    tsp (path, visited, 1, 0, 0);
    cout << "\nMinimum cost: " << minCost<< "\nOptimal path: ";
    for (int i = 0; i < n; i++)
    {  
        cout << bestPath[i] << " -> ";
    }

    cout << "0\n";
    return 0;
}