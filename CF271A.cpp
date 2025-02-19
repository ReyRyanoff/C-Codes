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

    int n;
    cin >> n;
    n++;
    int f = 1, s[10];
    while(f){
        s[4] = n % 10;
        s[3] = (n / 10) % 10;
        s[2] = (n / 100) % 10;
        s[1] = (n / 1000) % 10;

        int flag = 0;
        for(int i = 1; i <= 4; i++){
            for(int j = 1; j != i; j++){
                if(s[i] == s[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }
        if(flag == 1) n++;
        else f = 0;
    }
    cout << n << endl;

    return 0;
}
 