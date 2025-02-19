#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, rem;
    cin >> n >> m;

    while(n != 0){
        rem = n % m;
        n -= rem;
        n /= m;
        cout << "Result = " << n << endl;
        cout << "Reminder = " << rem << endl;
    }

    return 0;
}
