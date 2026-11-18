#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
vector<int> merge(vector<int> left, vector<int> right);
vector<int> mergeSort(vector<int> arr) 
{
    if (arr.size() <= 1)
    {  
        return arr;
    }

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}
vector<int> merge (vector<int> left, vector<int> right) 
{
    vector<int> result;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) 
    {
        if (left[i] <= right[j])
        {
            result.push_back(left[i++]);
        }

        else
        { 
            result.push_back(right[j++]);
        }  
    }
    while (i < left.size())
    { 
        result.push_back(left[i++]);
    }

    while (j < right.size())
    { 
        result.push_back(right[j++]);
    }
    return result;
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
        vector<int> sortedArr = mergeSort(arr);
        auto end = high_resolution_clock::now();
        duration <double> elapsed = end - start;
        cout << "n = " << n<< ", Time taken = " << elapsed.count()<< " seconds" << endl;
        cout << "First 10 sorted elements: ";
        for (int i = 0; i < 10; i++)
        {  
            cout << sortedArr[i] << " ";
        }
        cout << "\n\n";    
    }
    return 0;
}