
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

void displayForward() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void displayBackward() {
    Node* temp = tail;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main() {
    int value;

    cout << "Enter 7 numbers: ";

    for (int i = 0; i < 7; i++) {
        cin >> value;
        insertAtEnd(value);
    }

    cout << "\nOutput: ";

    displayForward();
    displayBackward();

    return 0;
}
