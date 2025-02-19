#include <bits/stdc++.h>
using namespace std;

void recursive_digit(int n)
{
    if (n == 0) return;
    int x = n % 10;
    recursive_digit(n / 10);
    cout << x << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n != 0)
            recursive_digit(n);
        else
            cout << "0";

        cout << endl; 
    }
    return 0;
}
