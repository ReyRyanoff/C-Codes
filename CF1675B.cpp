#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define translow(x) transform((x).begin(), (x).end(), (x).begin(), ::tolower)
#define sz(n) (int)(n).size()
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define maxarr(a) *max_element(a.begin(), a.end());
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define maxint 2147483647
#define maxll 9223372036854775807
#define EL cout << endl
#define space " "

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
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vi v(n, 0);
        for(i = 0; i < n; i++){
            int x;
            cin >> x;
            v[i] = x;
        }
        int f = 0;
        for(int i = n - 2; i >= 0; i--){
            while(v[i] >= v[i + 1] && v[i] > 0){
                v[i] /= 2;
                f++;
            }
            if(v[i] == v[i+1]){
                cout << -1 << '\n';
                f = -99;
                break;
            }
        }

        if(f != -99) cout << f << '\n';

    }    
    return 0;
}
 