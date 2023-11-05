#include <iostream>

using namespace std;

class HashTable {
private:
    int Size;
    int* table;
public:
    HashTable(int size) {
        Size = size;
        table = new int[Size];
        for (int i = 0; i < Size; i++) {
            table[i] = -1;  // Initialize all slots as empty (-1)
        }
    }

    int hashFunction(int key) {
        return key % Size;
    }

    void insertItem(int key) {
        int index = hashFunction(key);

        // Find the next available slot using linear probing
        while (table[index] != -1) {
            index = (index + 1) % Size;
        }

        table[index] = key;
    }

    bool searchItem(int key) {
        int index = hashFunction(key);

        // Search for the key using linear probing
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;  // Key found
            }
            index = (index + 1) % Size;
        }

        return false;  // Key not found
    }

    bool deleteItem(int key) {
        int index = hashFunction(key);

        // Search for the key using linear probing
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;  // Mark the slot as empty
                return true;  // Key deleted
            }
            index = (index + 1) % Size;
        }

        return false;  // Key not found
    }

    void printTable() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < Size; i++) {
            if (table[i] != -1) {
                cout << i << ": " << table[i] << endl;
            }
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    HashTable ht(tableSize);

    int insertValue, searchValue, deleteValue;

    for (int i = 0; i < tableSize; i++) {
        cout << "Enter a value to insert: ";
        cin >> insertValue;
        ht.insertItem(insertValue);
    }

    // Printing
    ht.printTable();

    // Searching
    for (int i = 0; i < 3; i++) {
        cout << "Enter a value to search: ";
        cin >> searchValue;
        if (ht.searchItem(searchValue)) {
            cout << searchValue << " was found" << endl;
        } else {
            cout << searchValue << " was not found" << endl;
        }
    }

    // Deleting
    for (int i = 0; i < 3; i++) {
        cout << "Enter a value to delete: ";
        cin >> deleteValue;
        if (ht.deleteItem(deleteValue)) {
            cout << deleteValue << " was deleted successfully" << endl;
        } else {
            cout << deleteValue << " was not found" << endl;
        }
    }

    // Printing
    ht.printTable();

    return 0;
}
