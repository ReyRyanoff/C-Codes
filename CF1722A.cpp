#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define space " "
#define vc vector
#define pb push_back

const double PI = 3.14159;

int main()
{
    optimize();

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, cnt = 0, cntt = 0;
        cin >> n;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        string x = "Timur";
        sort(x.begin(), x.end());
        
        if(s == x) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}