#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    } *head, *tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insBeg(int);
    void insEnd(int);
    void insPos(int, int);
    void delBeg();
    void delEnd();
    void delPos(int);
    bool search(int);
    void displayForward();
    void displayBackward();
};

// Insert at Beginning
void DoublyLinkedList::insBeg(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (!head) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at End
void DoublyLinkedList::insEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert at a Specific Position
void DoublyLinkedList::insPos(int value, int pos) {
    if (pos == 0 || !head) {
        insBeg(value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp->next; i++) {
        temp = temp->next;
    }

    if (!temp->next) {
        insEnd(value);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from Beginning
void DoublyLinkedList::delBeg() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
}

// Delete from End
void DoublyLinkedList::delEnd() {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
}

// Delete at a Specific Position
void DoublyLinkedList::delPos(int pos) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    if (pos == 0) {
        delBeg();
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos && temp->next; i++) {
        temp = temp->next;
    }

    if (!temp->next) {
        delEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// Search for an Element
bool DoublyLinkedList::search(int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) {
            cout << "Element found\n";
            return true;
        }
        temp = temp->next;
    }
    cout << "Element not found\n";
    return false;
}

// Display List Forward
void DoublyLinkedList::displayForward() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Display List Backward
void DoublyLinkedList::displayBackward() {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = tail;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main() {
    DoublyLinkedList list;
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
        cout << "8 -> Display Forward\n";
        cout << "9 -> Display Backward\n";
        cout << "10 -> Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insBeg(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insEnd(value);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                list.insPos(value, pos);
                break;
            case 4:
                list.delBeg();
                break;
            case 5:
                list.delEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.delPos(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.displayForward();
                break;
            case 9:
                list.displayBackward();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}
