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
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        int sum1, sum2;
        sum1 = a + b + c;
        sum2 = x + y;

        int a1 = 0;
        int b1 = 0;
        if(a < x) a1 = x - a;
        if (b < y) b1 = y - b;
        if (c >= a1 + b1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}