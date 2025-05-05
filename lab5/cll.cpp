#include <iostream>
using namespace std;

class cll {
private:
    struct Node {
        int data;
        Node* next;
    } *head, *current, *temp;

public:
    cll() {
        head = nullptr;
    }

    void insbeg(int);
    void insend(int);
    void inspos(int, int);
    void delbeg();
    void delend();
    void delpos(int);
    bool search(int);
    void display();
};

void cll::insbeg(int value) {
    Node* newnode = new Node();
    newnode->data = value;

    if (!head) {  // Empty list case
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void cll::insend(int value) {
    Node* newnode = new Node();
    newnode->data = value;

    if (!head) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
}

void cll::inspos(int value, int pos) {
    if (pos == 0) {
        insbeg(value);
        return;
    }

    Node* newnode = new Node();
    newnode->data = value;
    temp = head;

    for (int i = 0; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void cll::delbeg() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head) {  // Single node case
        delete head;
        head = nullptr;
        return;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}

void cll::delend() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head) {  // Single node case
        delete head;
        head = nullptr;
        return;
    }

    temp = head;
    Node* prev = nullptr;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    delete temp;
}

void cll::delpos(int pos) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    if (pos == 0) {
        delbeg();
        return;
    }

    temp = head;
    Node* prev = nullptr;

    for (int i = 0; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        cout << "Invalid position\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

bool cll::search(int value) {
    if (!head) {
        cout << "List is empty\n";
        return false;
    }

    temp = head;
    do {
        if (temp->data == value) {
            cout << "Element found\n";
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Element not found\n";
    return false;
}

void cll::display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(Head)\n";
}

int main() {
    cll list;
    int choice, value, pos;

    while (true) {
        cout << "\n*** MENU ***\n";
        cout << "1 -> Insert at Beginning\n";
        cout << "2 -> Insert at End\n";
        cout << "3 -> Insert at Position\n";
        cout << "4 -> Delete at Beginning\n";
        cout << "5 -> Delete at End\n";
        cout << "6 -> Delete at Position\n";
        cout << "7 -> Search\n";
        cout << "8 -> Display\n";
        cout << "9 -> Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insbeg(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insend(value);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                list.inspos(value, pos);
                break;
            case 4:
                list.delbeg();
                break;
            case 5:
                list.delend();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.delpos(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}
