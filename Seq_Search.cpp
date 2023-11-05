#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 5, 2, 8, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter the number to search: ";
    cin >> key;

    int index = sequentialSearch(arr, size, key);
    if (index == -1) {
        cout << "The number is not present in the array." << endl;
    } else {
        cout << "The number is present at index " << index << " in the array." << endl;
    }

    return 0;
}
