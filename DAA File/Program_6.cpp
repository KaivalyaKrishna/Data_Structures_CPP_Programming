#include <iostream>
using namespace std;
void maxheapify(int arr[], int n, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n && arr[l] > arr[max])
        max = l;


    if (r < n && arr[r] > arr[max])
        max = r;


    if (max != i)
    {
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;


        maxheapify(arr, n, max);
    }}
void minheapify(int arr[], int n, int i)
{
    int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[min])
        min = l;
    if (r < n && arr[r] < arr[min])
        min = r;
    if (min != i)
    {
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        minheapify(arr, n, min);
    }}
void maxheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);
}
void minheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minheapify(arr, n, i);
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], maxArr[n], minArr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxArr[i] = arr[i];
        minArr[i] = arr[i];
    }
    maxheap(maxArr, n);
    minheap(minArr, n);
    cout << "\nMax Heap: ";
    for (int i = 0; i < n; i++)
        cout << maxArr[i] << " ";
    cout << "\nMin Heap: ";
    for (int i = 0; i < n; i++)
        cout << minArr[i] << " ";
    return 0;
}
