#include <iostream>
#include <algorithm>
using namespace std;

struct Item 
{
    float weight, value;
};

bool compare (Item a, Item b) 
{
    return (a.value / a.weight) > (b.value / b.weight);
}

void fractionalKnapsack (float capacity, Item items[], int n) {
    sort(items, items + n, compare);
    float totalValue = 0;
    cout << "\nSelected Items:\n";
    for (int i = 0; i < n; i++) 
    {
        if (capacity == 0)
        {  
            break;
        }
        
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;
            cout << "Weight: " << items[i].weight << ", Value: " << items[i].value << " (Full item)" << endl;
        }

        else
        {   
            float fraction = capacity / items[i].weight;
            float fractionValue = items[i].value * fraction;
            totalValue += fractionValue;
            cout << "Weight: " << capacity<< ", Value: " << fractionValue<< " (Fraction)" << endl;
            capacity = 0;  
        } 
    }
    
    cout << "\nMaximum Value = " << totalValue << endl;
}

int main() 
{ 
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    Item items[100];
    for (int i = 0; i < n; i++) 
    {
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> items[i].weight;
        cout << "Enter value of item " << i + 1 << ": ";
        cin >> items[i].value;
    }
    
    float capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    
    fractionalKnapsack(capacity, items, n);
    return 0;
}
