#include <iostream>
using namespace std;
void shellsort(int arr[], int n){
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap = gap / 2){
        for (i = gap; i < n; i++){
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp; }}}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    shellsort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
