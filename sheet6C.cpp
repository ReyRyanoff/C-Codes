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

    ll n, a, b;
    cin >> a >> b;
    if(a > b) {
        ll t = b;
        b = a;
        a = t;
    }
    n = b - a + 1;
    ll sum = (n * (a + b)) /2;
    cout << sum << endl;
    ll nodd, neven;
    ll odd = a;
    if((a+b) % 2 != 0){
        nodd = n / 2;
        neven = n / 2;
        if(a % 2 != 0) odd = a + 1;
    }
    else {
        if(a % 2 == 0){
            odd = a + 1;
            nodd = (n / 2);
            neven = ((n + 1) / 2);
        }
        else {
            odd = a;
            nodd = ((n + 1) / 2);
            neven = (n / 2);
        }
    }
    ll sum1 = nodd * ((2 * odd) + ((nodd - 1) * 2)) / 2;
    
    ///ll sum1 = (odd * nodd) + (nodd * (nodd - 1));
    cout << sum - sum1 << endl;
    cout << sum1 << endl;
        
    return 0;
}
 