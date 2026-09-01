#include <iostream>
using namespace std;
void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, k = 0;
    int temp[end - beg + 1];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j]){
            temp[k++] = arr[i++];}
        else{
            temp[k++] = arr[j++];}
    }
    while (i <= mid){
        temp[k++] = arr[i++];}
    while (j <= end){
        temp[k++] = arr[j++];}
    for (i = beg, k = 0; i <= end; i++, k++){
        arr[i] = temp[k];}
}
void mergesort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergesort(arr, beg, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
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
    mergesort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
