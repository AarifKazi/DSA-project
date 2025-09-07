#include <iostream>
using namespace std;

// Merge two sorted halves into one sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // Size of left subarray
    int n2 = right - mid;      // Size of right subarray

    int L[n1], R[n2];          // Temporary arrays for left and right parts

    // Copy elements into temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge temporary arrays back into original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find midpoint to divide array
        int mid = left + (right - left) / 2;

        // Recursively sort first half
        mergeSort(arr, left, mid);

        // Recursively sort second half
        mergeSort(arr, mid + 1, right);

        // Merge both sorted halves
        merge(arr, left, mid, right);
    }
}

// Linear search function: search for value v in array a[] of size s
void search(int a[], int s, int v) {
    int count = 0; // Count occurrences
    for (int i = 0; i < s; i++) {
        if (a[i] == v) {
            cout << "Index is " << i << "\n";
            count++;
        }
    }
    if (count == 0) {
        cout << "Item not found\n";
    }
}

// Binary search function: search for value in sorted array arr[] of size 'size'
void Binarysearch(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            cout << "Index is: " << mid << "\n";
            return;
        } else if (arr[mid] < value) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    cout << "Value not found\n";
}

int main() {
    int choice;

    do {
        // Display menu options
        cout << "Press 1 for Selection Sort\nPress 2 for Merge Sort\nPress 3 for Linear Search\nPress 4 for Binary Search\nPress 0 for EXIT\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Selection Sort
                int size, i, j;
                cout << "Enter size of array for sorting: ";
                cin >> size;

                int arr[100];
                cout << "Enter " << size << " values:\n";
                for (i = 0; i < size; i++) {
                    cin >> arr[i];
                }

                // Selection sort algorithm
                for (i = 0; i < size; i++) {
                    for (j = i + 1; j < size; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }

                // Print sorted array
                cout << "Sorted Array: ";
                for (i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }

            case 2: {
                // Merge Sort
                int size_merge;
                cout << "Enter size of array: ";
                cin >> size_merge;

                int arr[100];
                cout << "Enter " << size_merge << " values:\n";
                for (int i = 0; i < size_merge; i++) {
                    cin >> arr[i];
                }

                // Call merge sort function
                mergeSort(arr, 0, size_merge - 1);

                // Print sorted array after merge sort
                cout << "Array after Merge Sort: ";
                for (int i = 0; i < size_merge; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }

            case 3: {
                // Linear Search
                int size, k, value;
                cout << "Enter size of array: ";
                cin >> size;

                int arr[100];

                cout << "Enter " << size << " values: ";
                for (k = 0; k < size; k++) {
                    cin >> arr[k];
                }

                cout << "Find value in array: ";
                cin >> value;

                // Call linear search
                search(arr, size, value);
                break;
            }

            case 4: {
                // Binary Search
                int size, i, j, value;

                cout << "Enter size of array for searching value: ";
                cin >> size;

                int arr[100];

                cout << "Enter " << size << " values: ";
                for (i = 0; i < size; i++) {
                    cin >> arr[i];
                }

                // Sort array before binary search using simple bubble sort
                for (i = 0; i < size; i++) {
                    for (j = i + 1; j < size; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }

                // Print sorted array
                cout << "\nSorted Array\n";
                for (i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;

                cout << "Enter value to find in array: ";
                cin >> value;

                // Call binary search function
                Binarysearch(arr, size, value);

                break;
            }

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
