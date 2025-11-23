#include <iostream>
#include <string>
using namespace std;

// Patient node structure
struct Patient {
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

Patient* head = nullptr;

// Function to add a new patient at the end
void insertPatient(int id, string name, int age, string disease) {
    Patient* newPatient = new Patient{id, name, age, disease, nullptr};

    if (head == nullptr) {
        head = newPatient;
    } else {
        Patient* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newPatient;
    }
    cout << "Patient added successfully.\n";
}

// Display all patients
void displayPatients() {
    if (head == nullptr) {
        cout << "No patient records available.\n";
        return;
    }
    Patient* temp = head;
    cout << "\n--- All Patient Records ---\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->id
             << ", Name: " << temp->name
             << ", Age: " << temp->age
             << ", Disease: " << temp->disease << endl;
        temp = temp->next;
    }
}

// Search patient by ID
void searchPatientByID(int id) {
    Patient* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Patient Found:\n";
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Age: " << temp->age
                 << ", Disease: " << temp->disease << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient with ID " << id << " not found.\n";
}

// Delete patient by ID
void deletePatientByID(int id) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->id == id) {
        Patient* temp = head;
        head = head->next;
        delete temp;
        cout << "Patient deleted.\n";
        return;
    }

    Patient* prev = head;
    Patient* curr = head->next;

    while (curr != nullptr) {
        if (curr->id == id) {
            prev->next = curr->next;
            delete curr;
            cout << "Patient deleted.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Patient with ID " << id << " not found.\n";
}

// Main menu
int main() {
    int choice, id, age;
    string name, disease;

    do {
        cout << "\n===== Hospital Patient Record System =====\n";
        cout << "1. Add New Patient\n";
        cout << "2. Delete Patient by ID\n";
        cout << "3. Search Patient by ID\n";
        cout << "4. Display All Patients\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // for getline()

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter Disease: ";
                getline(cin, disease);
                insertPatient(id, name, age, disease);
                break;

            case 2:
                cout << "Enter Patient ID to delete: ";
                cin >> id;
                deletePatientByID(id);
                break;

            case 3:
                cout << "Enter Patient ID to search: ";
                cin >> id;
                searchPatientByID(id);
                break;

            case 4:
                displayPatients();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
