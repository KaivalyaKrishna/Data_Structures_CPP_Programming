#include <iostream>
using namespace std;
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void countSort(int arr[], int n, int pos)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / pos) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int pos = 1; max / pos > 0; pos = pos * 10)
        countSort(arr, n, pos);
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    radixsort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
