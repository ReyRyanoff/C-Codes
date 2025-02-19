#include <bits/stdc++.h>
using namespace std;

#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define mod 10
#define pi 3.1416
#define ll long long int
#define ull unsigned long long int
#define endl '\n'

#define yes    cout << "YES" << endl
#define no     cout << "NO" << endl

#define test_cases()    int t; cin >> t; while(t--)

#define FOR(i, start, end)      for(int i = start; i < end; i++)
#define REV_FOR(i, start, end)      for(int i = start; i >= end; i--)
vector<double> v, w;

void sieve(int n) //---- print all prime numbers from 1 to n
{
    vector<int> prime(n + 3, 0);

    for (int i = 2; i * i <= n; i++)
    {

        if (prime[i] == 0)
        {

            for (int j = i * i; j <= n; j += i)
                prime[j] = 1;
        }
    }

    for (int i = 2; i <= n; i++)
        if (prime[i] == 0)
            v.push_back(i);
}
void solve()
{

    double x, y, z , k;
    int a, b ,c ;
    int n , ans , sum=0 , f=0 , cnt=0;
    string str, str1, str2; 
 
    vector<pair<int, int>> p;
    list<int> l ; 
    set<int> s1;
    map <double,int> mp;
    map <double,int> :: iterator it;
    priority_queue<int>pq;  // used for max heap

    sieve(50);
    
    cin >> a >> b >> c;
    double s = double(a + b + c) / 2;
    double area = s * ((s - a) * (s - b) * (s - c));
    double r = area / pow(s, 2);
    ///cout << r << endl;
    if(r - (int) r == 0){
        cout << r << "/1" <<endl;
    }
    else{
        FOR(i,0,v.size())
        {
            x = r*v[i];

            y = fmod(x,v[i]);

            if(x - (int) x == 0){
                cout<<x <<"/"<<v[i]<<endl;
                break;
            }
            
        }
    }
}

int main()
{

    test_cases()
    solve();
    
    return 0;
}