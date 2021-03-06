#include "pch.h"
#include <iostream>

class ListNode {
public:
    int _num;
    ListNode* _next;

    ListNode(int num, ListNode* next = NULL) {
        _num = num;
        _next = next;
    }

    ~ListNode() {
        delete _next;
    }

};

ListNode* reverse(ListNode* current, ListNode* previous = NULL) {
    if (current == NULL) {
        return previous;
    }

    ListNode* next = current->_next;
    current->_next = previous;

    return reverse(next, current);
}

int main()
{
    const int N = 20;
    ListNode* start = new ListNode(0);
    ListNode* current = start;
    ListNode* reversedList;

    for (int i = 1; i < N; ++i) {
        ListNode* next = new ListNode(i);
        current->_next = next;
        current = next;
    }

    current = start;

    while (current != NULL) {
        std::cout << current->_num << " !\n";
        current = current->_next;
    }

    std::cout << std::endl;
    reversedList = reverse(start);
    current = reversedList;

    while (current != NULL) {
        std::cout << current->_num << " !\n";
        current = current->_next;
    }

    delete reversedList;
    return 0;
}