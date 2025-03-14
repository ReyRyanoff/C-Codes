#include<bits/stdc++.h>
using namespace std;

///Insertion Sorting of Array:
void insertion_sort(int n, int arr[])
{
    int temp, i;
    for(i = 1; i < n; i++){
        temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int n, arr[1000];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertion_sort(n, arr);
    
    cout << "After sorting : ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}