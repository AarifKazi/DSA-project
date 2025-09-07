#include <iostream>
using namespace std;

//linkedlist
class Node {
public:
    int value;      // Stores the data
    Node* next;     // Pointer to the next node

    // Constructor to initialize the node
    Node(int v) {
        value = v;
        next = NULL;
    }
};


class LinkedList {
public:
    Node* head; // Pointer to the first node
    Node* tail; // Pointer to the last node

    // Constructor initializes head and tail as NULL
    LinkedList() {
        head = tail = NULL;
    }

    // Function to add a value at the end of the linked list
    void AddValueAtLast(int x) {
        Node* newnode = new Node(x); // Create new node

        if (head == NULL) {
            head = tail = newnode; // If list is empty
        } else {
            tail->next = newnode;  // Append at the end
            tail = newnode;        // Update tail
        }
    }

    // Function to add value at a given position in the linked list
    void AddValueAtRandomPosition(int x, int pos) {
        Node* newnode = new Node(x);
        int count = 1;

        // If list is empty or position is 1, insert at start
        if (head == NULL || pos <= 1) {
            newnode->next = head;
            head = newnode;

            if (tail == NULL) {
                tail = newnode;
            }
            return;
        }

        Node* temp = head;

        // Traverse to the position before where new node is to be inserted
        while (temp->next != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        // Insert node at the position
        newnode->next = temp->next;
        temp->next = newnode;

        // If new node is inserted at the end, update tail
        if (newnode->next == NULL) {
            tail = newnode;
        }
    }

    // Function to display the linked list
    void print() {
        Node* temp = head;
        cout << "Linked List: ";
        if(temp == NULL){
            cout<<"NULL";
        }
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


//Merge Sort

// Merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // Size of left subarray
    int n2 = right - mid;      // Size of right subarray

    int L[n1], R[n2];          // Temporary arrays

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge temp arrays back into main array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy remaining elements from right subarray
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

//Binary Search

// Function to perform binary search on a sorted array
void Binarysearch(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;

    // Binary search loop
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If element is found
        if (arr[mid] == value) {
            cout << "Value found at index: " << mid << "\n";
            return;
        }
        else if (arr[mid] < value) {
            left = mid + 1; // Search in right half
        }
        else {
            right = mid - 1; // Search in left half
        }
    }

    cout << "Value not found in array.\n";
}


//Quick Sort

// Function to swap two values
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition the array for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition index
        int pi = partition(arr, low, high);

        // Recursively sort left and right parts
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
     LinkedList obj;
     int choice;

    do {
        cout << "Press 1 for Create a linkedlist\nPress 2 for Displaylinkedlist\nPress 3 for Binary Search\npress 4 for Merge Sort\npress 5 for Quick Sort\nPress 0 for EXIT\n"; //declare choice
        cin >> choice;

        switch (choice) {
            case 1:
            //linked-list
            
            int n, val;
            cout << "How many values do you want to insert? ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "Enter value " << i + 1 << ": ";
                cin >> val;
                obj.AddValueAtLast(val);
            }
            cout << "Linked List created successfully.\n";
                break;
                
            case 2:
                 obj.print();
                 break;
                 
            case 3: {
                //Binary search
                
                int size,i,value,j;
    
                cout<<"Enter size of array for searching value : \n";
                cin>>size;
    
                int arr[100];
    
                cout<<"Enter "<<size<<" value : \n";
    
                for(i=0;i<size;i++){
                cin>>arr[i];
                } 
                
                for(i=0;i<size;i++){
                    for(j=i+1;j<size;j++){
                        if(arr[i] > arr[j]){
                            int temp;
                            temp=arr[i];
                            arr[i]=arr[j];
                            arr[j]=temp;
                        }
                    }
                }
                
                cout<<"\nSorted Array\n";
                for(i=0;i<size;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                
                cout<<"Enter value for find out value in array : ";
                cin>>value;
    
                Binarysearch(arr,size,value);
                break;
            }

            case 4: {
                //Merge Sort
                
                int size_merge;
                cout << "Enter size of array: ";
                cin >> size_merge;

                int arr[100];
                cout << "Enter " << size_merge << " values:\n";
                for (int i = 0; i < size_merge; i++) {
                    cin >> arr[i];
                }

                mergeSort(arr, 0, size_merge - 1);

                cout << "Array after Merge Sort: ";
                for (int i = 0; i < size_merge; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            
            case 5:
                //quick
                int q;

                cout << "Enter number of elements: ";
                cin >> q;

                int arr[100]; // Static array

                cout << "Enter " << q << " elements:\n";
                for (int i = 0; i < q; i++)
                cin >> arr[i];

                quickSort(arr, 0, q - 1); // Call QuickSort

                printArray(arr, q); // Output result
                break;

            case 0:
                cout << "EXIT\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);
    
    return 0;
}



