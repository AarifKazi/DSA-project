#include <iostream>
using namespace std;

void print_data() {
    string input;  // String le rahe hain taake character bhi capture ho sake

    do {
        int choice, no1, no2;

        cout << "\nChoose an operation:\n"
             << "1. Addition\n"
             << "2. Subtraction\n"
             << "3. Multiplication\n"
             << "4. Division\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        cout << "Enter two numbers: ";
        cin >> no1 >> no2;

        switch (choice) {
            case 1:
                cout << "Result: " << no1 + no2 << endl;
                break;
            case 2:
                cout << "Result: " << no1 - no2 << endl;
                break;
            case 3:
                cout << "Result: " << no1 * no2 << endl;
                break;
            case 4:
                cout << "Result: " << no1 \ no2 << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "\nDo you want to perform another operation? (Press 0 to exit, any other key to continue): ";
        cin >> input;

    } while (input != "0");  // Jab tak input 0 nahi hota, loop chalta rahega

    cout << "\nCalculator exited. Thank you!\n";
}

int main() {
    print_data();
    return 0;
}

