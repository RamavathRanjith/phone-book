#include <iostream>
#include <string>
using namespace std;

// Contact structure
struct Contact {
    string name;
    long long phoneNumber;
    Contact* next;
};

// Phone Directory class
class PhoneDirectory {
private:
    Contact* head;

public:
    // Constructor
    PhoneDirectory() {
        head = nullptr;
    }

    // Destructor
    ~PhoneDirectory() {
        deleteAllContacts();
    }

    // Add a contact
    void addContact(string name, long long phoneNumber) {
        Contact* newContact = new Contact;
        newContact->name = name;
        newContact->phoneNumber = phoneNumber;
        newContact->next = nullptr;

        if (head == nullptr) {
            head = newContact;
        } else {
            Contact* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newContact;
        }

        cout << "Contact added successfully!" << endl;
    }

    // Delete a contact
    void deleteContact(string name) {
        if (head == nullptr) {
            cout << "Phone directory is empty!" << endl;
            return;
        }

        if (head->name == name) {
            Contact* temp = head;
            head = head->next;
            delete temp;
            cout << "Contact deleted successfully!" << endl;
            return;
        }

        Contact* prev = head;
        Contact* curr = head->next;
        while (curr != nullptr) {
            if (curr->name == name) {
                prev->next = curr->next;
                delete curr;
                cout << "Contact deleted successfully!" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Contact not found!" << endl;
    }

    // Display all contacts
    void displayContacts() {
        if (head == nullptr) {
            cout << "Phone directory is empty!" << endl;
            return;
        }

        cout << "Contacts in the phone directory:" << endl;
        Contact* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->name << ", Phone: " << temp->phoneNumber << endl;
            temp = temp->next;
        }
    }

    // Search for a contact
    void searchContact(string name) {
        if (head == nullptr) {
            cout << "Phone directory is empty!" << endl;
            return;
        }

        Contact* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                cout << "Contact found!" << endl;
                cout << "Name: " << temp->name << ", Phone: " << temp->phoneNumber << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Contact not found!" << endl;
    }

    // Delete all contacts
    void deleteAllContacts() {
        Contact* temp = head;
        while (temp != nullptr) {
            Contact* curr = temp;
            temp = temp->next;
            delete curr;
        }
        head = nullptr;
        cout << "All contacts deleted successfully!" << endl;
    }
};

int main() {
    PhoneDirectory phoneDirectory;
    int choice;
    string name;
    long long phoneNumber;

    do {
        cout << "\nPhone Directory Menu:" << endl;
        cout << "1. Add a contact" << endl;
        cout << "2. Delete a contact" << endl;
        cout << "3. Display all contacts" << endl;
        cout << "4. Search for a contact" << endl;
        cout << "5. Delete all contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter contact name: ";
                cin >> name;
                cout << "Enter contact phone number: ";
                cin >> phoneNumber;
                phoneDirectory.addContact(name, phoneNumber);
                break;
            case 2:
                cout << "Enter contact name to delete: ";
                cin >> name;
                phoneDirectory.deleteContact(name);
                break;
            case 3:
                phoneDirectory.displayContacts();
                break;
            case 4:
                cout << "Enter contact name to search: ";
                cin >> name;
                phoneDirectory.searchContact(name);
                break;
            case 5:
                phoneDirectory.deleteAllContacts();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
