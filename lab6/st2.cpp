#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
};

class Stack {
    private:
        Node* top;
    public:
        Stack() { top = nullptr; }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            cout << value << " pushed into stack\n";
        }

        void pop() {
            if (top == nullptr) {
                cout << "Stack Underflow\n";
                return;
            }
            Node* temp = top;
            cout << temp->data << " popped from stack\n";
            top = top->next;
            delete temp;
        }

        void peek() {
            if (top == nullptr) {
                cout << "Stack is empty\n";
                return;
            }
            cout << "Top element is " << top->data << "\n";
        }

        void display() {
            if (top == nullptr) {
                cout << "Stack is empty\n";
                return;
            }
            Node* temp = top;
            cout << "Stack elements: ";
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
};

int main() {
    Stack s;
    int choice, value;
    
    while (true) {
        cout << "\n1 -> Push\n2 -> Pop\n3 -> Peek\n4 -> Display\n5 -> Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
