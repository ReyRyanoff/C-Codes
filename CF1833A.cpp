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
        int i, j, k, n;
        cin >> n;
        char s[55];
        cin >> s;
        set <string> v;

        for(i = 0, k = 0; i < n-1; i++)
        {
            string s1;
            for(j = i; j <= i+1; j++)
            {
                s1 += s[j];
            }
            v.insert(s1);
        }
        int x = v.size();
        cout << x << endl;

    }
    
        
    return 0;
}