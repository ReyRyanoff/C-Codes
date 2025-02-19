#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define revall(x) (x).rbegin(), (x).rend()
#define Tolower(x) transform((x).begin(), (x).end(), (x).begin(), ::tolower)
#define sz(n) (int)(n).size()
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define maxarr(a) *max_element(a.begin(), a.end());
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define maxint 2147483647
#define maxll 9223372036854775807
#define EL cout << endl
 
const double PI = 3.14159;
 
typedef string str;
typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef vector<bool> vbl;
typedef vector<pair<ll, ll>> vll;
typedef pair<ll, ll> pll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int arr[maxint], n;

/// sum of n consequetive numbers:-
ll SUM (ll n){
    ll sum = n * (n + 1) / 2;
    return sum;
}

///GCD of 2 numbers:-
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
    return b; 
    return gcd(b % a, a); 
}
///GCD of an array with 'n' size:-
ll findGCD(vl& arr, int n) 
{ 
    ll result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
    result = gcd(arr[i], result); 

    if(result == 1) 
    { 
    return 1; 
    } 
    } 
    return result; 
} 

///Finding k-th divisor o 'n' :-
void findkth (ll n, ll k)
{
    vector <ll> v1;
    vector <ll> v2;
    
    for( ll i = 1 ; i * i <= n; i++ )
    {
        if ( n % i == 0 ) 
        {
            v1.push_back ( i );
             
            if ( i != sqrt ( n ) )
                v2.push_back ( n / i );
        }
    }
    
    reverse(v2.begin(), v2.end());
     
    // if k is greater than the size of vectors 
    // then no divisor can be possible
    if ( k > (v1.size() + v2.size())) cout << "Doesn't exist";
    // else print the ( k - 1 )th value of vector 
    else
    {
        // If K is lying in first vector
        if(k <= v1.size())  cout << v1[k-1];
        // If K is lying in second vector
        else
            cout<<v2[k-v1.size()-1];
    }
}

///factorials and permutaion/combinations function:-
///the return type is long long cause the factorials exceed normal integer limit
ll fact(int n) {
   if (n == 0 || n == 1)
   return 1;
   else
   return n * fact(n - 1);
}
ll permutation(int n, int r){
    ll per;
    per = fact(n) / fact(n-r);
    return per;
}
ll combination(int n, int r){
    ll comb = fact(n) / (fact(r) * fact(n-r));
    return comb;
}

//sieve of eratosthenes:
void sieve()
{
    int max_n, k; 
    cin >> k;
    max_n = pow(2, 15);
    int n = max_n + 5;
    int is_prime[n] = {0};
    vector<int> primes;
    is_prime[0] = is_prime[1] = 1;

    for(int i = 2; i * i <= max_n; i++){
        if(!is_prime[i]){
            for(int j = i * i; j <= max_n; j += i){
                is_prime[j] = 1;
            }
        }
    }
    if(is_prime[k]) cout << k << " is not prime" << endl;
    else cout << k << " is prime" << endl;
    
}

///Insertion Sorting of Array:
void insertion_sort()
{
    int temp, i;
    for(i = 1; i < n; i++){
        temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int n;
    n = pow(2, 3);
    cout << n << endl;
    return 0;
}