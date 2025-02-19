#include <iostream>
#include <string>
using namespace std;
class Customer {
public:
    string name;
    string address;
    string mobile;
    double price[10];

    void get_data() {
        cout << "Enter customer name: ";
        char c;
        cin >> c;
        getline(cin, name);
        cout << "Enter customer address : ";
        getline(cin, address);
        cout << "Enter customer mobile : ";
        cin >> mobile;

        cout << "Enter prices for 10 items : " << endl;
        for (int i = 1; i <= 10; i++) {
            cout << "Item " << i << ": ";
            cin >> price[i];
        }
    }

    void show_data() {
        cout << "Customer Name : " << name << endl;
        cout << "Customer Address : " << address << endl;
        cout << "Customer Mobile : " << mobile << endl;
        cout << "Item Prices : " << endl;;
        for (int i = 1; i <= 10; i++) {
            cout << "Item " << i << ": " << price[i] << endl;
        }
    }
};

int main()
{
    int N;
    cout << "Enter the number of customers : ";
    cin >> N;

    Customer customers[100];

    for (int i = 1; i <= N; i++) {
        cout << "Enter data for customer " << i << ":" << endl;
        customers[i].get_data();
    }

    cout << "Customer data:" << endl;
    for (int i = 1; i <= N; i++) {
        cout << "Customer " << i << ":" << endl;
        customers[i].show_data();
        cout << endl;
    }

    return 0;
}
