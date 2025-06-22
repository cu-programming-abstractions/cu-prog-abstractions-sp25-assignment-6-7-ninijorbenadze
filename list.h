#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(LinkedList rhs);
    ~LinkedList();

    void prepend(int value);
    void append(int value);
    int removeFront();
    bool isEmpty() const;
    void print(ostream& out) const;

    class Node {
    public:
        int data;
        Node* next;
    };

    Node* getHead() const { return head; }
    void setHead(Node* node) { head = node; }

private:
    Node* head = nullptr;

    Node* deepCopy(Node* src);
    void freeChain(Node* n);
};

#endif // LIST_H
