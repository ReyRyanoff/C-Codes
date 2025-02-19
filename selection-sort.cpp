#include<bits/stdc++.h>
using namespace std;
void Selection_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]) min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[100], n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Selection_Sort(arr, n);
    cout << "After sorting array = ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}