#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "LinkedList.h"
#include <sstream>

TEST_CASE("LinkedList initialization and insertion") {
    LinkedList list;
    
    SUBCASE("Initial list is empty") {
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "NULL");  
    }

    SUBCASE("Insert at the beginning") {
        list.insertAtBeginning(-1);
        list.insertAtBeginning(1);
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "1 -> -1");
    }

    SUBCASE("Insert at the end") {
        list.insertAtEnd(-1);
        list.insertAtEnd(1);
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "-1 -> 1");
    }
}

TEST_CASE("LinkedList deletion") {
    LinkedList list;
    list.insertAtBeginning(-1);
    list.insertAtBeginning(1);
    list.insertAtEnd(0);
    // 1 -1 0  
    SUBCASE("Delete element with data 1 ") {
        list.deleteNode(1);  // Delete second element (value = 1)
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "-1 -> 0");
    }

    SUBCASE("Delete at index") {
        list.deleteAtIndex(1);  // Delete the second element (value = -1)
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "1 -> 0");
    }
}

TEST_CASE("Copying a LinkedList") {
    LinkedList list;
    list.insertAtBeginning(-1);
    list.insertAtBeginning(1);
    
    LinkedList copiedList = list;
    
    std::ostringstream ossOriginal, ossCopy;
    ossOriginal << list;
    ossCopy << copiedList;
    
    CHECK(ossOriginal.str() == ossCopy.str());
}

TEST_CASE("Prefix sum checks") {
    LinkedList list;
    list.insertAtBeginning(-1);
    list.insertAtBeginning(1);
    list.insertAtEnd(-1);
    // 1 -1 -1 

    SUBCASE("Non-negative prefix sum check") {
        CHECK(list.non_negative_prefix() == false);
    }

    SUBCASE("Non-positive prefix sum check") {
        CHECK(list.non_positive_prefix() == false);
    }
}

TEST_CASE("Pointer Jumping") {
    LinkedList list;
    list.insertAtBeginning(-1);
    list.insertAtBeginning(1);
    list.insertAtEnd(0);
    
    SUBCASE("Before pointer jumping") {
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "1 -> -1 -> 0");
    }
    
    list.pointerJumping();
    
    SUBCASE("After pointer jumping") {
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "1 -> -1 -> 0 ->  (cycle detected)");
    }
}
TEST_CASE("Move constructor and move assignment operator") {
    LinkedList list1;
    list1.insertAtBeginning(-1);
    list1.insertAtBeginning(1);
    
    LinkedList list2 = move(list1);
    
    SUBCASE("Move constructor") {
        ostringstream oss1, oss2;
        oss1 << list1;  // Should be empty
        oss2 << list2;   // Should contain the elements 1 -> -1
        CHECK(oss1.str() == "NULL");
        CHECK(oss2.str() == "1 -> -1");
        CHECK(list1.root == nullptr);  // list1 should be empty after move
    }

    // Test move assignment operator
    LinkedList list3;
    list3.insertAtBeginning(10);
    list3.insertAtEnd(20);
    list3 = move(list2);
    
    SUBCASE("Move assignment operator ") {
        ostringstream oss3, oss2;
        oss3 << list3;   // Should contain the elements 1 -> -1
        oss2 << list2;   // Should be empty
        CHECK(oss3.str() == "1 -> -1");
        CHECK(oss2.str() == "NULL");
        CHECK(list2.root == nullptr);  // list2 should be empty after move
    }
    
   
    SUBCASE("Ensure the root addresses are moved") {
        LinkedList list4;
        list4.insertAtBeginning(5);
        list4.insertAtEnd(10);
        
        Node* oldRoot = list4.root;
        LinkedList list5 = move(list4);
        
        // After the move, list5 should take over the root
        CHECK(list4.root == nullptr); // list4 should be empty
        CHECK(list5.root == oldRoot); // list5 should point to the old root of list4
    }
}

TEST_CASE("LinkedList move edge cases") {
    LinkedList list1;
    
    SUBCASE("Move from empty list") {
        LinkedList list2 = move(list1);
        ostringstream oss;
        oss << list2;
        CHECK(oss.str() == "NULL");  // Should be empty
        CHECK(list1.root == nullptr);  // list1 should still be empty
    }

    SUBCASE("Move to an already existing list") {
        list1.insertAtBeginning(5);
        LinkedList list2;
        list2.insertAtBeginning(10);
        list2 = move(list1);
        
        std::ostringstream oss1, oss2;
        oss1 << list1;
        oss2 << list2;
        
        CHECK(oss1.str() == "NULL");  
        CHECK(oss2.str() == "5");    
    }
}
