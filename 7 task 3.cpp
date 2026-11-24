
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertAtEnd(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteByValue(int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found!" << endl;
        return;
    }

    if (temp == head) {
        head = temp->next;
    }

    if (temp == tail) {
        tail = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << "Node deleted successfully!" << endl;
}

void display() {
    Node* temp = head;

    cout << "Updated List: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int value, delValue;

    cout << "Enter 5 numbers: ";

    for (int i = 0; i < 5; i++) {
        cin >> value;
        insertAtEnd(value);
    }

    cout << "\nOriginal List: ";
    display();

    cout << "Enter value to delete: ";
    cin >> delValue;

    deleteByValue(delValue);

    display();

    return 0;
}
