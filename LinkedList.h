#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <unordered_set>
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
public:
    Node * root;

    LinkedList() : root(nullptr) {}


    LinkedList(const LinkedList &other) : root(nullptr) {
        if (other.root) {
            root = new Node(other.root->data);
            Node* current = root;
            Node* otherCurrent = other.root->next;
            while (otherCurrent) {
                current->next = new Node(otherCurrent->data);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    void insertAtBeginning(int val) {
        Node * newNode = new Node(val);
        newNode->next = root;
        root = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }
        Node* current = root;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    Node* getLastElement() {
        if (!root) return nullptr;
        Node* current = root;
        while (current->next) {
            current = current->next;
        }
        return current;
    }

    void deleteNode(int val) {
        if (!root) return;
        if (root->data == val) {
            Node* temp = root;
            root = root->next;
            delete temp;
            return;
        }
        Node* current = root;
        while (current->next && current->next->data != val) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void deleteAtIndex(int index) {
        if (!root || index < 0) return;
        if (index == 0) {
            Node* temp = root;
            root = root->next;
            delete temp;
            return;
        }
        Node* current = root;
        for (int i = 0; current && i < index - 1; i++) {
            current = current->next;
        }
        if (current && current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

  
    void pointerJumping() {
        if (!root) return;
        Node* last = getLastElement();
        if (last) {
            last->next = root;  
        }
    }

    bool non_negative_prefix() {
        if (!root) {
            std::cout << "Invalid input" << std::endl;
            return false;
        }
        int sum = 0;
        Node* current = root;
        while (current) {
            if (current->data > 1 || current->data < -1) {
                std::cout << "List should contain only -1, 0, +1" << std::endl;
                return false;
            }
            sum += current->data;
            if (sum < 0) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool non_positive_prefix() {
        if (!root) {
            std::cout << "Invalid input" << std::endl;
            return false;
        }
        int sum = 0;
        Node* current = root;
        while (current) {
            if (current->data > 1 || current->data < -1) {
                std::cout << "List should contain only -1, 0, +1" << std::endl;
                return false;
            }
            sum += current->data;
            if (sum > 0) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    ~LinkedList() {
        if (root) {
            Node* current = root;
            Node* next = nullptr;

           
            std::unordered_set<Node*> visited;
            while (current) {
                if (visited.count(current)) {
                    current->next = nullptr;  
                    break;
                }
                visited.insert(current);
                next = current->next;
                delete current;
                current = next;
            }
        }
        root = nullptr;
    }
};


ostream& operator<<(ostream& os, const LinkedList& list) {
    std::unordered_set<Node*> visited;
    Node* current = list.root;
    while (current) {
        if (visited.count(current)) {
            os << " (cycle detected)";
            break;
        }
        os << current->data << (current->next ? " -> " : "");
        visited.insert(current);
        current = current->next;
    }
    if (!list.root) {
        os << "NULL";
    }
    return os;
}

#endif
