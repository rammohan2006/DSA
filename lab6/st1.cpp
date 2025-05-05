
#include <iostream>
#define N 5
using namespace std;

class Stack {
    private:
        int arr[N], top;
    public:
        Stack() { top = -1; }

        void push(int value) {
            if (top == N - 1) {
                cout << "Stack Overflow\n";
                return;
            }
            arr[++top] = value;
            cout << value << " pushed into stack\n";
        }

        void pop() {
            if (top < 0) {
                cout << "Stack Underflow\n";
                return;
            }
            cout << arr[top--] << " popped from stack\n";
        }

        void peek() {
            if (top < 0) {
                cout << "Stack is empty\n";
                return;
            }
            cout << "Top element is " << arr[top] << "\n";
        }
};

int main() {
    Stack s;
    int choice, value;
    
    while (true) {
        cout << "\n1 -> Push\n2 -> Pop\n3 -> Peek\n4 -> Exit\nEnter your choice: ";
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
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}

