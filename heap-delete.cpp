#include <iostream>
using namespace std;

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size_heap = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insert(int value) {
    if (size_heap >= MAX_SIZE) {
        cout << "Heap is full. Cannot insert element." << endl;
        return;
    }

    heap[++size_heap] = value;
    int i = size_heap;

    while (i > 1 && heap[i / 2] < heap[i]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

void display() {
    for (int i = 1; i <= size_heap; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int deleteMax() {
    if (size_heap == 0) {
        cout << "Heap is empty. Cannot delete element." << endl;
        return -1;
    }

    int max_value = heap[1];
    heap[1] = heap[size_heap];
    size_heap--;

    int i = 1;
    while (true) {
        int left_child = 2 * i;
        int right_child = 2 * i + 1;

        if (left_child > size_heap && right_child > size_heap) {
            break;
        }

        int max_child = left_child;
        if (right_child <= size_heap && heap[right_child] > heap[left_child]) {
            max_child = right_child;
        }

        if (heap[i] < heap[max_child]) {
            swap(heap[i], heap[max_child]);
            i = max_child;
        } else {
            break;
        }
    }

    return max_value;
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

    cout << "The max val is " << deleteMax() << endl;
    cout << "The Max Heap after deleting the max value is ";
    display();

    return 0;
}
