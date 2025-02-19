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
        long long int a, x;
        cin >> a;
        x = a;
        int cnt = 0;
        while (x >= 10){
            x = x / 10;
            cnt++;
        }
        int n;
        n = pow(10, cnt);
        cout << (a - n) << endl;
    }
    
        
    return 0;
}