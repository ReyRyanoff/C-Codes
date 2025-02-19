#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define revall(x) (x).rbegin(), (x).rend()
#define Tolower(x) transform((x).begin(), (x).end(), (x).begin(), ::tolower)
#define sz(n) (int)(n).size()
#define forn(i, n) for(int i = 0; i < n; ++i)
#define maxarr(a) *max_element(a.begin(), a.end());
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define maxint 2147483647
#define maxll 9223372036854775807
#define EL cout << endl
 
const double PI = 3.14159;
 
typedef string str;
typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef vector<bool> vbl;
typedef vector<pair<ll, ll>> vll;
typedef pair<ll, ll> pll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Find x such that the sum of digits of x is close to n/2
        int x = max(1, n / 2 - 1);
        int bestDiff = abs(sumOfDigits(x) - sumOfDigits(n - x));

        for (int i = max(1, n / 2 - 1); i <= n; ++i) {
            int diff = abs(sumOfDigits(i) - sumOfDigits(n - i));
            if (diff < bestDiff) {
                x = i;
                bestDiff = diff;
            }
        }

        int y = n - x;

        cout << x << " " << y << endl;
    }

    return 0;
}