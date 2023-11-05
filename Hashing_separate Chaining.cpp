#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;
};

node *head, *newNode, *temp;

class hashTable{
private:
    int Size;
    node *table[10];
public:
    hashTable(){
        Size = 10;
        for (int i=0; i<Size; i++){
            table[i] = NULL;
        }
    }

    node *createNode(int data){
        node *result;
        result = new node;
        result->data = data;
        result->next = NULL;
        return result;
    }

    int hashFunction(int userIn){
        return userIn % Size;
    }

    bool isEmpty(){
        for (int i=0; i<Size; i++){
            if (table[i] != NULL) return false;
        }
        return true;
    }

    void insertItem(int userIn){
        int tablePos = hashFunction(userIn);

        newNode = createNode(userIn);
        if (table[tablePos] == NULL){
            table[tablePos] = newNode;
        }else{
            temp = table[tablePos];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool searchItem(int searchvalue){
        int tablePos = hashFunction(searchvalue);

        if (isEmpty()) return false;
        temp = table[tablePos];
        while(temp != NULL){
            if (temp->data == searchvalue)
                return true;
            temp = temp->next;
        }
        return false;
    }

    bool deleteItem(int deletevalue){
        int tablePos = hashFunction(deletevalue);
        node *delNode;

        if(isEmpty()) return false;
        if (table[tablePos] == NULL){
            return false;
        }
        if (table[tablePos]->data == deletevalue){
            delNode = table[tablePos];
            table[tablePos] = delNode->next;
            delete delNode;
            return true;
        }else{
            temp = table[tablePos];
            while(temp->next != NULL){
                if (temp->next->data == deletevalue){
                    delNode = temp->next;
                    temp->next = delNode->next;
                    delete delNode;
                    return true;
                }
                temp = temp->next;
            }
        }
        return false;
    }

    void printTable(){
        if (isEmpty()){
            cout << "It empty man" << endl;
            return;
        }
        cout << "Printing the table..." << endl;
        for(int tablePos=0; tablePos<Size; tablePos++){
            cout << tablePos << ": ";
            temp = table[tablePos];   //table[tablePos] acts as the head of the list in tablePos position of our array/table
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    hashTable ht;
    int insertValue, searchValue, deletevalue;

    for (int i=0; i<15; i++){
        cout << "Enter a value to insert: ";
        cin>>insertValue;
        ht.insertItem(insertValue);
    }

    //printing
    ht.printTable();

    //searching
    for (int i=0; i<3; i++){
        cout << "Enter a value to search: ";
        cin>>searchValue;
        if (ht.searchItem(searchValue))
            cout << searchValue << " was found" << endl;
        else
            cout << searchValue << " was not found" << endl;
    }

    //deleting
    for (int i=0; i<3; i++){
        cout << "Enter a value to delete: ";
        cin>>deletevalue;
        if (ht.deleteItem(deletevalue))
            cout << deletevalue << " was deleted successfully" << endl;
        else
            cout << deletevalue << " was not found" << endl;
    }

    //printing
    ht.printTable();
    return 0;
}
