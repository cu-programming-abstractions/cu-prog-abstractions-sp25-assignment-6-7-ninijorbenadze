#include "list_utils.h"
#include "list.h"

int length(const LinkedList& list) {
    int count = 0;
    LinkedList::Node* current = list.getHead();
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int sum(const LinkedList& list) {
    int total = 0;
    LinkedList::Node* current = list.getHead();
    while (current != nullptr) {
        total += current->data;
        current = current->next;
    }
    return total;
}

bool contains(const LinkedList& list, int k) {
    LinkedList::Node* current = list.getHead();
    while (current != nullptr) {
        if (current->data == k) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void reverse(LinkedList& list) {
    LinkedList::Node* prev = nullptr;
    LinkedList::Node* current = list.getHead();
    LinkedList::Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list.setHead(prev);
}

int nthFromEnd(const LinkedList& list, int n) {
    if (n < 0) {
        throw std::runtime_error("Invalid position");
    }

    int len = length(list);
    if (n >= len) {
        throw std::runtime_error("Invalid position");
    }

    LinkedList::Node* fast = list.getHead();
    LinkedList::Node* slow = list.getHead();

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the last node
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
}
