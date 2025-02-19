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
#define maxint -999999999
#define minint 999999999
#define maxll -9223372036854775807
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

    int n, i;
    cin >> n;
    string a, b;
    string s, x, s1;
    cin >> s;
    vector<string> v(n-1);
    map<string, int> cnt;
    int max = maxint;

    for(i = 1; i < n; i++){
        a = s[i-1];
        b = s[i];
        x = a + b;
        v[i-1] = x;
    }
    
    for(i = 0; i < (n-1); i++)
    {
        cnt[v[i]]++;
        if(cnt[v[i]] > max){
            max = cnt[v[i]];
            s1 = v[i];
        }
    }
    cout << s1 << endl;
    

    return 0;
}
 