#include<iostream>
using namespace std;

//node structure
class Node{
    public:
        int value;
        Node *next;
        
        //constructor
        Node(int v){
            value = v;
            next = NULL;
        }   
};

//LinkedList class
class LinkedList{
    public:
    Node *head;
    Node *tail;
    
    //constructor
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    //Add value method
    void AddValueAtFirst(int x){
        Node *newnode = new Node(x);
        
        if(head != NULL){
            newnode->next = head;
            head = newnode;
        }
        else{
            head = newnode;
            tail = newnode;
        }
    }
    
    
    //delete method
    void deleteNode(int x){
        if(head == NULL){   // Empty list
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        
        
        if(head->value == x){
            Node *temp = head;
            head = head->next;
            delete temp;
            
            if(head == NULL) tail = NULL;
            return;
        }
        
        
        Node *current = head;
        while(current->next != NULL && current->next->value != x){
            current = current->next;
        }
        
        
        if(current->next == NULL){
            cout << "Value " << x << " not found in the list.\n";
            return;
        }
        

        Node *temp = current->next;
        current->next = current->next->next;
        

        if(temp == tail){
            tail = current;
        }
        delete temp;
    }
    
    
    //searchNode method
    bool searchNode(int x){
        Node *temp = head;
        int position = 1;  // positions start from 1
        
        while(temp != NULL){
            if(temp->value == x){
                cout << "Value " << x << " found at position " << position << ".\n";
                return true;
            }
            temp = temp->next;
            position++;
        }
        cout << "Value " << x << " not found in the list.\n";
        return false;
    }
    
    //reverse method
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed!" << endl;
    }
    

    //for print LinkedList
    void printList(){
        Node *temp = head;
        
        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    
};

int main(){
    LinkedList list; //object
    int choice, value;


    //for choice method
    do {
        cout << "\n===== Linked List Menu =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Search a node\n";
        cout << "3. Delete a node\n";
        cout << "4. Reverse the list\n";
        cout << "5. Display the list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.AddValueAtFirst(value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.searchNode(value)){
                cout << "Node found!\n";
            }
            else{
                cout << "Node not found!\n";
            }
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;

        case 4:
            list.reverse();
            break;

        case 5:
            cout << "Linked List: ";
            list.printList();
            break;

        case 0:
            cout << "EXIT";
            break;

        default:
            cout << "invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}


