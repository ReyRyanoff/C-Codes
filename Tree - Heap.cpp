#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

int heap[MAX_SIZE] = {99999999};
int size_heap = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void insert(int value) {
    if (size_heap >= MAX_SIZE - 1) {
        cout << "Heap is full. Cannot insert element." << endl;
        return;
    }

    heap[++size_heap] = value;
    int i = size_heap;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void display() {
    for (int i = 1; i <= size_heap; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, i;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter values of elements : ";
    for(i = 1; i <= n; i++){
        int x;
        cin >> x;
        insert(x);
    }
    cout << "The Max Heap is ";
    display();

    cout << "The max val is " << heap[1] << endl;

    return 0;
}
