#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define revall(x) (x).rbegin(), (x).rend()
#define Tolower(x) transform((x).begin(), (x).end(), (x).begin(), ::tolower)
#define sz(n) (int)(n).size()
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define maxarr(a) *max_element(a.begin(), a.end());
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define maxint 2147483647
#define maxll 9223372036854775807
#define EL cout << endl

const double PI = 3.14159;
 
typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef vector<bool> vbl;
typedef vector<pair<ll, ll>> vll;
typedef pair<ll, ll> pll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    optimize();
        
    int t;
    cin >>t;
    while(t--)
    {
        int i, n,arr[50], cnt_even = 0, cnt_odd = 0;
        cin >> n;
        for(i = 0; i < n; i++){
            cin >> arr[i];
            if(i % 2 != 0 && arr[i] % 2 == 0) cnt_even++;
            else if(i % 2 == 0 && arr[i] % 2 != 0) cnt_odd++;
        }
        if(cnt_even == cnt_odd) cout << cnt_even << endl;
        else cout << "-1" << endl;
    }

    return 0;
} 