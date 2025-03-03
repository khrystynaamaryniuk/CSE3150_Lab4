#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    cout << "Testing LinkedList Implementation\n";

    // Create a linked list
    LinkedList ll;
    cout << "Initial list: " << ll << endl;

    // Insert elements at the beginning
    ll.insertAtBeginning(-1);
    ll.insertAtBeginning(1);
    ll.insertAtBeginning(-1);
    cout << "After inserting at the beginning: " << ll << endl;
    //-1 1 -1 ->NULL 
    // Insert elements at the end
    ll.insertAtEnd(1);
   
    ll.insertAtEnd(-1);
    cout << "After inserting at the end: " << ll << endl;
    // -1 1 -1 1 -1->NULL 
    // Get the last element
    Node* lastNode = ll.getLastElement();
    if (lastNode)
        cout << "Last node: " << lastNode->data << endl;
    // -1 
    // Delete a specific value
    ll.deleteNode(1);
    cout << "After deleting second element: " << ll << endl;
    //  -1 -1 1 -1->NULL 
    // Delete at index
    ll.deleteAtIndex(2);
    cout << "After deleting node at index 2(third element): " << ll << endl;
    // -1  -1  -1->NULL 
    // Copy constructor test
    LinkedList ll_copy = ll;
    cout << "Copied list (should be same as previous): " << ll_copy << endl;
    // -1 -1 -1->NULL 

    // Test non-negative prefix sum function
    cout << "Non-negative prefix sum check: " << (ll.non_negative_prefix() ? "YES" : "NO") << endl;
    
    //NO 

    // Test non-positive prefix sum function
    cout << "Non-positive prefix sum check: " << (ll.non_positive_prefix() ? "YES" : "NO") << endl;

    //YES

    // Test pointer jumping
    cout << "Before pointer jumping: " << ll << endl;
    ll.pointerJumping();
    cout << "After pointer jumping: " << ll << endl;
    std::cout << "Testing ended" << std::endl;
    return 0;
}
