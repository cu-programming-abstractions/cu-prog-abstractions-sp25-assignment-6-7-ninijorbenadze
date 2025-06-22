#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include "list.h"

int length(const LinkedList& list);
int sum(const LinkedList& list);
bool contains(const LinkedList& list, int k);
void reverse(LinkedList& list);
int nthFromEnd(const LinkedList& list, int n);

#endif // LIST_UTILS_H
