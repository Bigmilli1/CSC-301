#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
    }

    // Destructor to free memory
    ~LinkedList()
    {
        clear();
    }

    // Add a node to the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << value << " added to the beginning." << endl;
    }

    // Add a node to the end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        // If the list is empty
        if (head == nullptr)
        {
            head = newNode;
            cout << value << " added to the end." << endl;
            return;
        }

        Node *current = head;

        // Move to the last node
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;

        cout << value << " added to the end." << endl;
    }

    // Add a node at a specific position
    // Positions start from 1
    void insertAtPosition(int value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position. Position must be 1 or greater."
                 << endl;
            return;
        }

        // Position 1 means beginning
        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }

        Node *current = head;

        // Move to the node before the required position
        for (int i = 1; i < position - 1 && current != nullptr; i++)
        {
            current = current->next;
        }

        // Position is outside the list
        if (current == nullptr)
        {
            cout << "Cannot insert. Position is outside the list."
                 << endl;
            return;
        }

        Node *newNode = new Node(value);

        newNode->next = current->next;
        current->next = newNode;

        cout << value << " added at position "
             << position << "." << endl;
    }

    // Delete a node by position
    void deleteByPosition(int position)
    {
        // Check if the list is empty
        if (head == nullptr)
        {
            cout << "Cannot delete. The list is empty." << endl;
            return;
        }

        if (position < 1)
        {
            cout << "Invalid position." << endl;
            return;
        }

        // Delete the first node
        if (position == 1)
        {
            Node *temp = head;

            head = head->next;

            cout << temp->data
                 << " deleted from position 1." << endl;

            delete temp;
            return;
        }

        Node *current = head;

        // Move to the node before the node to delete
        for (int i = 1; i < position - 1 && current != nullptr; i++)
        {
            current = current->next;
        }

        // Position does not exist
        if (current == nullptr || current->next == nullptr)
        {
            cout << "Cannot delete. Position does not exist."
                 << endl;
            return;
        }

        Node *temp = current->next;

        current->next = temp->next;

        cout << temp->data
             << " deleted from position "
             << position << "." << endl;

        delete temp;
    }

    // Delete the first node containing a particular value
    void deleteByValue(int value)
    {
        // Check if the list is empty
        if (head == nullptr)
        {
            cout << "Cannot delete. The list is empty." << endl;
            return;
        }

        // If the value is in the first node
        if (head->data == value)
        {
            Node *temp = head;

            head = head->next;

            cout << value << " deleted from the list." << endl;

            delete temp;
            return;
        }

        Node *current = head;

        // Search for the value
        while (current->next != nullptr &&
               current->next->data != value)
        {
            current = current->next;
        }

        // Value was not found
        if (current->next == nullptr)
        {
            cout << value << " was not found in the list." << endl;
            return;
        }

        Node *temp = current->next;

        current->next = temp->next;

        cout << value << " deleted from the list." << endl;

        delete temp;
    }

    // Display all nodes
    void display()
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *current = head;

        cout << "List: ";

        while (current != nullptr)
        {
            cout << current->data;

            if (current->next != nullptr)
            {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << " -> NULL" << endl;
    }

    // Delete all nodes and free memory
    void clear()
    {
        Node *current = head;

        while (current != nullptr)
        {
            Node *temp = current;

            current = current->next;

            delete temp;
        }

        head = nullptr;
    }
};

// Main function
int main()
{
    LinkedList list;

    int choice;
    int value;
    int position;

    cout << " SINGLY LINKED LIST PROGRAM " << endl;

    do
    {
        cout << "\n MENU " << endl;
        cout << "1. Add node at beginning" << endl;
        cout << "2. Add node at middle/position" << endl;
        cout << "3. Add node at end" << endl;
        cout << "4. Delete node by position" << endl;
        cout << "5. Delete node by value" << endl;
        cout << "6. Display list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            list.insertAtPosition(value, position);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> position;
            list.deleteByPosition(position);
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteByValue(value);
            break;

        case 6:
            list.display();
            break;

        case 7:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
