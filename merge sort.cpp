#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(ll arr[], int left, int mid, int right) {
    ll leftArr[500];
    ll rightArr[500];

    for(int i = 0; i <= mid - left; i++) leftArr[i] = arr[left + i];
    for(int i = 0; i < right - mid; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < mid - left + 1 && j < right - mid){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        } 
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < mid - left + 1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < right - mid){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(ll arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() 
{
    ll n, arr[100005];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    ///cout << "After sorting array : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}