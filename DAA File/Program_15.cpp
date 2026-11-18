#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
void merge (vector<int>& arr, int left, int mid, int right) 
{
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) 
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else 
        {
            arr[k++] = R[j++];
        } 
    }
    while (i < L.size())
    {
        arr[k++] = L[i++];
    }

    while (j < R.size())
    {
        arr[k++] = R[j++];
    }
}

void mergeSort (vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);  
    }
}

int main() 
{
    srand(time(0));
    int sizes[] = {6000, 10000, 15000, 20000, 30000, 50000};
    for (int n : sizes) 
    {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        { 
            arr[i] = rand() % 100000 + 1;
        }
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;
        cout << "Number of elements: " << n << endl;
        cout << "Time taken: " << elapsed.count() << " seconds" << endl;
        cout << "First 10 sorted elements: ";
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n\n"; 
    }
    return 0;
}