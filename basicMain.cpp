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

    //  Move constructor test
    LinkedList ll_moved = move(ll);
    cout << "Moved list (should be same as original before move): " << ll_moved << endl;
    cout << "Original list after move (should be NULL): " << ll << endl;

    // Move assignment test
    LinkedList ll_moved2;
    ll_moved2.insertAtBeginning(5);
    ll_moved2.insertAtBeginning(10);
    cout << "Before move assignment, list: " << ll_moved2<< endl;
    ll_moved2 = move(ll_moved);
    cout << "After move assignment, list: " << ll_moved2<< endl;
    cout << "Moved-from list (should be NULL): " << ll_moved << endl;


    // Test non-negative prefix sum function
    cout << "Non-negative prefix sum check: " << (ll_moved2.non_negative_prefix() ? "YES" : "NO") << endl;
    
    //NO 

    // Test non-positive prefix sum function
    cout << "Non-positive prefix sum check: " << (ll_moved2.non_positive_prefix() ? "YES" : "NO") << endl;

    //YES

    // Test pointer jumping
    cout << "Before pointer jumping: " << ll_moved2 << endl;
    ll.pointerJumping();
    cout << "After pointer jumping: " << ll_moved2 << endl;
    cout << "Testing ended" << endl;
    return 0;
}
