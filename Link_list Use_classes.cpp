#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
		
    }
	
	void selection_sort(){
		Node *i,*j, *min_idx;
		for(i=head; i->next != NULL; i = i->next){
			min_idx = 1;
			for(j=i->next; j != NULL; j = j->next){
				// selection sort
				if(i->data < j->data){
					min_idx = j;
				}
			}
			if(min_idx != 1) {
				int temp = min_idx->data;
				min_idx->data = i->data;
				i->data = temp;
			}
		}
		
	}

    void printList() {    /// Travetrsing the link list, to PRINT The list.
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    int n, value;
    cout << "How many nodes do you want to add? ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Enter the value of node " << i+1 << ": ";
        cin >> value;
        myList.insertAtEnd(value);
    }
    cout << "The linked list contains: ";
    myList.printList();
    return 0;
}
