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
    string s1, s2;
    cin >> s1;
    cin >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 > s2){
        string t = s1;
        s1 = s2;
        s2 = t;
    }
    int n, i, j;
    n = s1.size();
    string s;
    map <char, int> cnt1;
    map <char, int> cnt2;
    for (i = 0; i < n; i++)
    {
        if(s1[i] == s1[0]) cnt1[s1[0]]++;
        if(s2[i] == s2[0]) cnt1[s2[0]]++;
    }
    if(cnt1[s[0]] == n || cnt2[s[0]] == n){
        cout << "impossible";
    } 
    else {
        for(i = 0; i < n; i++){
            s[i] = s1[i] - s2[i];
        }
        cout << s << endl;
    }

    return 0;
}