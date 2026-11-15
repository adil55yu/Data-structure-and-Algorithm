#include <iostream>
using namespace std;

struct Node {
    int id;
    string action;
    Node *next;
};

Node *head = NULL;

void insertAtEnd(int id, string action) {
    Node *newNode = new Node;

    newNode->id = id;
    newNode->action = action;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAfterSecond(int id, string action) {
    Node *newNode = new Node;

    newNode->id = id;
    newNode->action = action;

    newNode->next = head->next->next;
    head->next->next = newNode;
}

void display() {
    Node *temp = head;

    while(temp != NULL) {
        cout << "ID: " << temp->id;
        cout << " Action: " << temp->action << endl;
        temp = temp->next;
    }
}

void deleteByID(int id) {
    Node *temp = head;

    if(head == NULL)
        return;

    if(head->id == id) {
        head = head->next;
        delete temp;
        return;
    }

    while(temp->next != NULL && temp->next->id != id) {
        temp = temp->next;
    }

    if(temp->next != NULL) {
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

int main() {
    int id;
    string action;

    for(int i = 0; i < 4; i++) {
        cout << "Enter action ID: ";
        cin >> id;

        cout << "Enter action name: ";
        cin >> action;

        insertAtEnd(id, action);
    }

    cout << "\nOriginal List:\n";
    display();

    cout << "\nEnter ID for Erase action: ";
    cin >> id;

    insertAfterSecond(id, "Erase");

    cout << "\nAfter Insertion:\n";
    display();

    cout << "\nEnter ID to delete: ";
    cin >> id;

    deleteByID(id);

    cout << "\nFinal List:\n";
    display();

    return 0;
}