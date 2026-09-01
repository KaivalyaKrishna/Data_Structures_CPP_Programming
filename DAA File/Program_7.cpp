#include <iostream>
using namespace std;
void countsort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max)
            max = arr[i];}
    int count[max + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    int k = 0;
    for (int i = 0; i <= max; i++){
        while (count[i] > 0){
            arr[k] = i;
            k++;
            count[i]--;}}}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    countsort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
