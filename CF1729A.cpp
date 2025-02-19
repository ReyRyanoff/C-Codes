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
        int a, b, c;
        cin >> a >> b >> c;
        int lift1, lift2;
        lift1 = a - 1;
        lift2 = abs(b-c) + (c-1);
        if(lift1 < lift2) cout << "1" << endl;
        else if(lift1 > lift2) cout << "2" << endl;
        else if(lift1 == lift2) cout << "3" << endl;
    }
    return 0;
}