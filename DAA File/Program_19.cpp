#include <iostream>
using namespace std;
int S[100], subset[100];
int n, d;
bool found = false;
void sumOfSubsets(int index, int currentSum) 
{
    if (currentSum == d) 
    {
        found = true;
        cout << "{ ";
        for (int i = 0; i < index; i++) 
        {
            if (subset[i] == 1)
            {
                cout << S[i] << " ";
            }
        }
        cout << "}" << endl;
        return;
    }
    
    if (index == n || currentSum > d) 
    { 
        return;
    }
    
    subset[index] = 1;
    sumOfSubsets(index + 1, currentSum + S[index]);
    subset[index] = 0;
    sumOfSubsets(index + 1, currentSum);
}

int main() 
{ 
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> S[i];
    }
    
    cout << "Enter target sum: ";
    cin >> d;
    cout << "Subsets with sum " << d << ":\n";
    sumOfSubsets(0, 0);
    if (!found) 
    { 
        cout << "No solution exists.";
    }
    return 0;
}