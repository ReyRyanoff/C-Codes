#include <bits/stdc++.h>
using namespace std;
#define ll long long
void countingSort(vector<ll> &arr, int n, int m)
{
    vector<ll> temp(n);
    vector<ll> cnt(10, 0);
    for (int i = 0; i < n; i++) cnt[(arr[i] / m) % 10]++;
    for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / m) % 10;
        temp[cnt[digit] - 1] = arr[i];
        cnt[digit]--;
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}
void radixSort(vector<ll> &arr, int n)
{
    ll max = *max_element(arr.begin(), arr.end());
    for (int i = 1; max / i > 0; i *= 10) countingSort(arr, n, i);
}
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    radixSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
