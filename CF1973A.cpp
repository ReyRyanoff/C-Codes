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
    cin >> t;
    while(t--)
    {
        int a, b, c, cnt = 0;
        cin >> a >> b >> c;

        ///if(a==b && b==c && c==a && a!=0 && b!=0 && c != 0) cout << "-1" << endl;
        if((a+b+c) % 2 != 0) cout << "-1" << endl;
        else{
            if((a + b) <= c) cout << a+b << endl;
            else{
                int k = 0;
                k =  (a + b - c) / 2;
                cout << c+k << endl;
            }
        }    
    }

    return 0;
}
 