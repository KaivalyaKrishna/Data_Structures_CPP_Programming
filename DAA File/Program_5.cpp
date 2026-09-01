#include <iostream>
using namespace std;
int partition(int arr[], int beg, int end)
{
    int pivot = arr[end];
    int i = beg - 1;
    for (int j = beg; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;
    return i + 1;
}
void quicksort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int pivot = partition(arr, beg, end);


        quicksort(arr, beg, pivot - 1);
        quicksort(arr, pivot + 1, end);
    }}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
