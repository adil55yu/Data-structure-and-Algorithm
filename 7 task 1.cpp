
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
    cout << endl;
}

void displayBackward() {
    Node* temp = tail;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int Maxvalue() {
    if (head == NULL) {
        cout << "List is empty";
        return -1;
    }

    int max = head->data;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}

int main() {
    int value;

    cout << "Enter 7 numbers: " << endl;

    for (int i = 0; i < 7; i++) {
        cin >> value;
        insertAtEnd(value);
    }

    cout << "\nForward List: ";
    displayForward();

    cout << "Backward List: ";
    displayBackward();

    cout << "Maximum Value: " << Maxvalue() << endl;

    return 0;
}
