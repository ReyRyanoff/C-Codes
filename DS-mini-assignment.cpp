#include<bits/stdc++.h>
using namespace std;

#define maxint 1000005
int arr[maxint], n, item, f;

///checks if the array is sorted:
int is_sorted()
{
    int o = 1, i;
    for(i = 1; i <= n; i++){
        if(arr[i] <= arr[i+1]){
            o++;
        }
    }
    if(o == n) return 1;
    else return 0;
}

///Insertion Sorting of Array:
void insertion_sort()
{
    int temp, i;
    for(i = 2; i <= n; i++){
        temp = arr[i];
        int j = i-1;
        while(j >= 1 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

///writing in the txt file:
void write()
{
    ofstream outFile("Array mini assignment.txt");
    if (outFile.is_open())
    {
        cout << "\t\t\tFile opened and elements added\n";
        outFile << n << endl;
        for (int i = 1; i <= n; i++)
        {
            outFile << arr[i] << " ";
        }
        outFile.close();
    }
    else cout << "\t\t\tError writing file" << endl;
}

///reading from the txt file:
void read()
{
    ifstream inFile("Array mini assignment.txt");
    if (inFile.is_open())
    {
        int i = 1;
        inFile >> n;
        cout << "Array : ";
        while (i<=n){
            inFile >> arr[i];
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
        inFile.close();
    }
    else cout << "Error reading file" << endl;
}

///Displaying the array:
void Display()
{
    cout << "Array : ";
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

///Binary searching to fing the position to insert or delete or search an element in array:
int Search()
{
    int beg, end, mid, loc = 0;
    end = n, beg = 1;
    mid = (beg + end) / 2;
    while(beg <= end && arr[mid] != item){
        if(item < arr[mid]) end = mid - 1;
        else beg = mid + 1;
        mid = (beg + end) / 2;
    }
    if(arr[mid] == item){
        loc = mid;
        return loc;
    }
    else{
        f = -1;
        loc = mid;
        return loc;
    }
}

///Inserting an element:
void Insert()
{
    cout << "\t\t\t" << "Enter item to insert : ";
    cin >> item;
    int loc;
    loc = Search();
    loc++;

    for(int i = n+1; i >= loc; i--){
        arr[i] = arr[i-1];
    }
    arr[loc] = item;
    n++;
    cout << "\t\t\t" << "Element Inserted : " << item << " in " << loc << "th position" << endl;
    write();
}

///Deleting an element:
void Delete()
{
    cout << "\t\t\t" << "Enter item to delete : ";
    cin >> item;
    int loc;
    loc = Search();

    if(f == -1){
        cout << "\t\t\t" << "Item not found" << endl;
        cout << "\t\t\t" << "No element deleted" << endl;
        return;
    }
    for(int i = loc; i <= n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;
    cout << "\t\t\t" << "Element Deleted : " << item << " from " << loc << "th position" << endl;
    write();
}

///menu function:
void menu()
{
    cout << "\t\t\t" << "Press to perform the following command: \n";
    cout << "\t\t\t" << "1. Insert an element" << endl;
    cout << "\t\t\t" << "2. Delete an element" << endl;
    cout << "\t\t\t" << "3. Search an element" << endl;
    cout << "\t\t\t" << "4. Display the array" << endl;
    cout << "\t\t\t" << "5. Exit" << endl;
    cout << endl;
    while(1){

        cout << "\t\t\t" << "Enter your choice : ";
        int t, i, cnt = 0;
        cin >> t;
        if(t == 1){
            Insert();
            cout << "\t\t\t" << "New ";
            read();
            cout << endl;
        }
        else if (t == 2){
            f = 0;
            Delete();
            cout << "\t\t\t" << "New ";
            read();
            cout << endl;
        }
        else if (t == 3){
            f = 0;
            cout << "\t\t\t" << "Enter item to Search : ";
            cin >> item;
            int pos = Search();
            if(f == -1){
                cout << "\t\t\t" << "Item not found\n";
            }
            else{
                for(i = pos-1; arr[i] == arr[pos]; i--) cnt++;
                pos -= cnt;
                cout << "\t\t\t" << item << " found in " << pos << "th position" << endl << endl;
            }
        }
        else if (t == 4){
            cout << "\t\t\t";
            Display();
            cout << endl;
        }
        else if(t == 5){
            cout << "\t\t\t" << "Exiting the program......." << endl;
            return;
        }
        else {
            cout << "\t\t\t" << "Invalid choice. Try again" << endl;
        }
    }
}

///creating the array:
void array_creation()
{
    int i, j;
    cout << endl;
    cout << "\t\t\t" << "Enter size of Array : ";
    cin >> n;
    for (i = 1; i <= n; i++){
        arr[i] = rand();
    }
    write();
    cout << "\t\t\t";
    read();
    if(is_sorted()) cout << "\t\t\t" << "Sorted Array" << endl;
    else{
        cout << endl;
        cout << "\t\t\t" << "Unsorted Array" << endl;
        cout << "\t\t\t";
        Display();
        cout << endl;
        insertion_sort();
        cout << "\t\t\t" << "Array is Sorted" << endl;
        cout << "\t\t\t" << "After sorting ";
        Display();
        cout << endl;
    }
    return;
}

int main()
{
    array_creation();
    menu();

    return 0;
}

///original code pastebin : https://pastebin.com/y3j5YdnS
