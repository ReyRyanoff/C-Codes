#include <bits/stdc++.h>
using namespace std;
int minMultRec(vector<int> &arr, int i, int j,
               vector<vector<int>> &memo) {
    if (i + 1 == j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];

    int res = INT_MAX;
    for (int k = i + 1; k < j; k++) {
        int curr = minMultRec(arr, i, k, memo) +
        minMultRec(arr, k, j, memo) + arr[i] * arr[k] * arr[j];

        res = min(curr, res);
    }
    memo[i][j] = res;
    return res;
}

int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return minMultRec(arr, 0, n - 1, memo);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    int res = matrixMultiplication(arr);
    cout << res << endl;
    return 0;
}
