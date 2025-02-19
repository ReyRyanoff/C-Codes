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
        int n, i, j;
        cin >> n;
        vector <int> v(n);
        for(i = 0; i < n; i++){
            cin >> v[i];
        }
        for(auto u : v) cout << u << " ";

    }
    
        
    return 0;
}