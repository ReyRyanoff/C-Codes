#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100005

long long heap[MAX_SIZE];
int size_heap = 0;

void swap(long long &a, long long &b)
{
    long long temp = a;
    a = b;
    b = temp;
}

void insert(int value)
{
    if (size_heap >= MAX_SIZE) {
        cout << "Heap is full. Cannot insert element." << endl;
        return;
    }

    heap[size_heap++] = value;
    int i = size_heap - 1;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void display()
{
    for (int i = 0; i < size_heap; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l] > heap[largest])
        largest = l;

    if (r < n && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        swap(heap[i], heap[largest]);

        heapify(n, largest);
    }
}

void heapsort()
{
    int n = size_heap;
    for (int i = size_heap / 2 - 1; i >= 0; i--)
        heapify(size_heap, i);

    for (int i = size_heap - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        size_heap--;
        heapify(size_heap, 0);
    }
    size_heap = n;
}

int main()
{
    int n, i;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter values of elements : ";
    for(i = 0; i < n; i++){
        long long x;
        cin >> x;
        insert(x);
    }
    cout << "The Max Heap is ";
    display();

    heapsort();

    cout << "The sorted array is ";
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}

///Time complexity for heapify is O(n)
///Time complexity for heapsort is O(nlogn)
