#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Registration function
void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Validate input
    if (username.empty() || password.empty()) {
        cout << "Username and password cannot be empty.\n";
        return;
    }

    // Check for duplicate username
    ifstream file("users.txt");

    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            cout << "Username already exists. Please choose another.\n";
            file.close();
            return;
        }
    }

    file.close();

    // Store credentials
    ofstream outFile("users.txt", ios::app);

    outFile << username << " " << password << endl;

    outFile.close();

    cout << "Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password;

    cout << "\n--- Login ---\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    string storedUsername, storedPassword;
    bool loginSuccessful = false;

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            loginSuccessful = true;
            break;
        }
    }

    file.close();

    if (loginSuccessful) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n========== LOGIN SYSTEM ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you for using the system!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}