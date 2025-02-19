#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd(ll a, ll b)
{
    if (a == 0)
    return b;
    return gcd(b % a, a);
}
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << "GCD of " << a << " & " << b << " = " << gcd(a, b);
    return 0;
}
