#include <bits/stdc++.h>
using namespace std;

void insertion_sort(long long n, vector<long long>& arr)
{
    long long temp, i;
    for(i = 1; i < n; i++){
        temp = arr[i];
        long long j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    optimize();

    ///Insertion Sort:
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        arr[i] = x;
    }
    insertion_sort(n, arr);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
 