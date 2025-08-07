#include <iostream>
#include <vector>
using namespace std;

// Template class for student
template <class T1, class T2>
class MemoryCalculate {
public:
    T1 id;
    T2 name;

    // Constructor
    MemoryCalculate(T1 i, T2 n) {
        id = i;
        name = n;
    }

    // Display function
    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    vector<MemoryCalculate<int, string>> students;
    int choice;

    while (true) {
        // Menu Display
        cout << "\n--- Student Management Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch-case for menu handling
        switch (choice) {

            case 1: {
                // Add Student
                int id;
                string name;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore(); // clear input buffer
                getline(cin, name);

                // Create and store the student
                MemoryCalculate<int, string> s(id, name);
                students.push_back(s);
                cout << "Student added successfully!\n";
                break;
            }

            case 2: {
                // Display All Students
                if (students.empty()) {
                    cout << "No students to display.\n";
                } else {
                    cout << "\nAll Students:\n";
                    for (const auto& student : students) {
                        student.display();
                    }
                }
                break;
            }

            case 3: {
                // Remove Student by ID
                int id;
                cout << "Enter ID to remove: ";
                cin >> id;
                bool found = false;

                // Find and remove
                for (auto it = students.begin(); it != students.end(); ++it) {
                    if (it->id == id) {
                        students.erase(it);
                        cout << "Student removed.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 4: {
                // Search Student by ID
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                bool found = false;

                for (const auto& student : students) {
                    if (student.id == id) {
                        cout << "Student found:\n";
                        student.display();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 0:
                // Exit the program
                cout << "Thank you!\n";
                return 0;

            default:
                // Invalid choice handling
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
