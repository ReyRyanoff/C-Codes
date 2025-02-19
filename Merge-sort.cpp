#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void merge(int arr1[], int arr2[], int n1, int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1) arr3[k++] = arr1[i++];
    while (j < n2) arr3[k++] = arr2[j++];
}

int main() 
{
    int i, n1, n2, n3, arr1[1000], arr2[1000], arr3[2500] = {0};
    cin >> n1;
    for(i = 0; i < n1; i++){
        cin >> arr1[i];
    }
    cin >> n2;
    for(i = 0; i < n2; i++){
        cin >> arr2[i];
    }
    
    n3 = n1 + n2;
    cout << "Array after merging 2 sorted arrays: ";
    merge(arr1, arr2, n1, n2, arr3);
    for (i = 0; i < n3; i++) cout << arr3[i] << " ";
    cout << endl;

    return 0;
}