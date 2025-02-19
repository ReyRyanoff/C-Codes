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

ll fact(int n) {
   if (n == 0 || n == 1)
   return 1;
   else
   return n * fact(n - 1);
}
ll permutation(int n, int r){
    ll per;
    per = fact(n) / fact(n-r);
    return per;
}
ll combination(int n, int r){
    ll comb = fact(n) / (fact(r) * fact(n-r));
    return comb;
}

int main()
{
    optimize();

    int n, r;
    cin >> n >> r;
    ll per = permutation(n, r);
    ll comb = combination(n, r);
    cout << comb << " " << per << endl;
        
    return 0;
}