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
        long long n, i, j, sum = 0, prod = 1;
        cin >> n;
        vector <int> v;

        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            prod = prod * x;
            ///cout << prod << " ";
            v.pb(x);
        }
        v[0] = prod;
        for (i = 1; i < n; i++)
        {
            v[i] = 1;
        }
        sum = prod + n - 1;
        prod = sum * 2022;
        cout << prod << endl;
        
    }
    return 0;
}