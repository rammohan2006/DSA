#include <iostream>
#include <stack>
using namespace std;

// Function to check if the given string has balanced parentheses
bool isBalanced(string str) {
    stack<char> s;
    
    for (char ch : str) {
        if (ch == '(') {
            s.push(ch); // Push opening bracket
        } else if (ch == ')') {
            if (s.empty()) return false; // More closing brackets than opening
            s.pop(); // Match found, pop opening bracket
        }
    }
    
    return s.empty(); // If stack is empty, it's balanced
}

int main() {
    int choice;
    string str;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                cin >> str;
                if (isBalanced(str))
                    cout << "The parentheses are balanced.\n";
                else
                    cout << "The parentheses are NOT balanced.\n";
                break;
            case 2:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1 or 2.\n";
        }
    }
}
