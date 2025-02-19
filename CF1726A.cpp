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
        int n, i, j;
        cin >> n;
        vector <int> v;
        int min1 = 1000;
        int max1 = -100000;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.pb(x);
            if(min1 > v[i]){
                min1 = v[i];
            }
            if(max1 < v[i]){
                max1 = v[i];
            }
        }
        
        if(n == 1) cout << "0" << endl;

        else{
            cout << max1 - min1 << endl;
        }

    }
    return 0;
}