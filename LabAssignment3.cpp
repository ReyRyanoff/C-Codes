#include <iostream>
using namespace std;
#define MAX 200

int multiply(int x, int result[], int result_size);

void factorial(int n)
{
    int result[MAX];
    result[0] = 1;
    int result_size = 1;

    for (int x = 2; x <= n; x++)
        result_size = multiply(x, result, result_size);

    cout << "Factorial of " << n << " = ";
    for (int i = result_size - 1; i >= 0; i--)
        cout << result[i];
}

int multiply(int x, int result[], int result_size)
{
    int carry = 0;

    for (int i = 0; i < result_size; i++) {
        int prod = result[i] * x + carry;

        result[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        result[result_size] = carry % 10;
        carry = carry / 10;
        result_size++;
    }
    return result_size;
}

int main()
{
    int n;
    cin >> n;
    factorial(n);
    return 0;
}
