#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isUserExists(string username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (isUserExists(username)) {
        cout << "? Username already exists! Try another.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << "\n";
    file.close();

    cout << "? Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    bool success = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            success = true;
            break;
        }
    }
    file.close();

    if (success) {
        cout << " Login successful! Welcome " << username << "!\n";
    } else {
        cout << " Invalid username or password!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) registerUser();
        else if (choice == 2) loginUser();
    } while (choice != 3);

    return 0;
}
