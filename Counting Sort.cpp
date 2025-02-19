#include <bits/stdc++.h>
using namespace std;
#define ll long long
void countingSort(vector<ll> &arr, int n)
{
    ll mini = *min_element(arr.begin(), arr.end());
    ll max = *max_element(arr.begin(), arr.end());
    ll N = max - mini + 1;
    vector<ll> cnt(N, 0);
    vector<ll> temp(n);
    for (int i = 0; i < n; i++) cnt[arr[i] - mini]++;
    for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        temp[cnt[arr[i] - mini] - 1] = arr[i];
        cnt[arr[i] - mini]--;
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}
int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
