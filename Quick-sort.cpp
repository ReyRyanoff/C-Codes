#include <bits/stdc++.h>
using namespace std;

void swap(long long* a, long long* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(long long arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        int x = i + 1;
        quickSort(arr, low, x - 1);
        quickSort(arr, x + 1, high);
    }
}

int main() 
{
    int i, n;
    long long arr[100005];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    for (i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}