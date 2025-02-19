#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define space " "
#define vc vector
#define pb push_back
#define all(v) (v).begin(), (v).end()

const double PI = 3.14159;

int main()
{
    optimize();

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j, k;
        cin >> n >> k;
        vc <int> a;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.pb(x);
        }
        vc <int> v = a;
        sort(v.begin(), v.end());
        int x = v[k - 1];
        int cnt = 0;
        for (i = 0; i < k; i++)
        {
            if(a[i] > x){
                cnt++;
            }
        }
        cout << cnt << endl;

    }
    
        
    return 0;
}