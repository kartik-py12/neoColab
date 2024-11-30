
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Create a stack to store the characters typed by the user
    stack<char> textEditor;

    // Variable to store the user's choice
    int choice;

    // Loop to repeatedly prompt the user for an action
    while (true) {
        // Display the menu of options

        // Get the user's choice
        cin >> choice;

        // Perform the corresponding action based on the user's choice
        switch (choice) {
            case 1:
                // Get the character to be typed
                char character;
                cin >> character;

                // Push the character onto the stack
                textEditor.push(character);

                // Output the typed character
                cout << "Typed character: " << character << endl;
                break;
            case 2:
                // Check if the stack is not empty
                if (!textEditor.empty()) {
                    // Pop the top character from the stack
                    character = textEditor.top();
                    textEditor.pop();

                    // Output the character that was removed
                    cout << "Undo: Removed character " << character << endl;
                } else {
                    // Output a message if the stack is empty
                    cout << "Text editor buffer is empty. Nothing to undo." << endl;
                }
                break;
            case 3:{

                // Check if the stack is not empty
                stack<char>tempp=textEditor;
                if (!tempp.empty()) {
                    cout << "Current text: ";
                    while (!tempp.empty()) {
                        cout << tempp.top();
                        tempp.pop();
                    }
                    cout << endl;
                } else {
                    // Output a message if the stack is empty
                    cout << "Text editor buffer is empty." << endl;
                }
                break;
            }
            case 4:
                // Exit the program
                return 0;
            default:
                // Output an error message if the choice is invalid
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}
