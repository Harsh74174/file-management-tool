#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(const string& filename) {
    ofstream file(filename); // write mode (overwrites)
    if (file.is_open()) {
        string line;
        cout << "Enter text to write to the file (type 'exit' to finish):\n";
        cin.ignore(); // clear buffer
        while (true) {
            getline(cin, line);
            if (line == "exit") break;
            file << line << endl;
        }
        file.close();
        cout << "File written successfully.\n";
    } else {
        cout << "Unable to open the file.\n";
    }
}

void appendFile(const string& filename) {
    ofstream file(filename, ios::app); // append mode
    if (file.is_open()) {
        string line;
        cout << "Enter text to append to the file (type 'exit' to finish):\n";
        cin.ignore();
        while (true) {
            getline(cin, line);
            if (line == "exit") break;
            file << line << endl;
        }
        file.close();
        cout << "Data appended successfully.\n";
    } else {
        cout << "Unable to open the file.\n";
    }
}

void readFile(const string& filename) {
    ifstream file(filename); // read mode
    if (file.is_open()) {
        string line;
        cout << "\n--- File Content ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
        cout << "---------------------\n";
    } else {
        cout << "Unable to open the file.\n";
    }
}

int main() {
    string filename = "myfile.txt";
    int choice;

    do {
        cout << "\n===== FILE MANAGEMENT TOOL =====\n";
        cout << "1. Write to file (overwrite)\n";
        cout << "2. Append to file\n";
        cout << "3. Read file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                appendFile(filename);
                break;
            case 3:
                readFile(filename);
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}