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
        long long int sum = 0;
        cin >> n;
        vector <long long int> v;

        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.pb(x);
        }
        sort(v.begin(), v.end());
        int x = n/2;
        for(i = 0; i < n; i++)
        {
            sum += v[i];
        }
        sum = abs(sum);
        cout << sum << endl;

    }
    return 0;
}