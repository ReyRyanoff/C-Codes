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
        int n, x, y, i, j;
        string s;
        cin >> s;
        char c;
        cin >> c;

        n = s.size();
        if (n == 1 && s[0] != c){
            cout << "NO" << endl;
        }
        else if (n == 1 && s[0] == c){
            cout << "YES" << endl;
        }
        else if(n > 1)
        {
            j = 50;    
            for(i = 0; i < n; i++)
            {
                if(s[i] == c && i % 2 == 0){
                    j = i+1;
                }
            }
            x = j - 1;
            y = n - j;
            if(x % 2 == 0 && y % 2 == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
             
        }

    }
    
        
    return 0;
}