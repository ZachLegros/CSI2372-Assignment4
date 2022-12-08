#pragma once
#include <iostream>

class DoubleLinkedList
{
private:
    typedef struct Node
    {
        int value;
        Node *prev;
        Node *next;
    } Node;

    Node *head;
    Node *tail;
    int size;
    int dummy;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool add_to_front(int);
    bool add_to_back(int);
    bool insert_item(int, int);
    void remove_item(int);
    void remove_from_front();
    void remove_from_back();
    int get_head();
    int get_tail();
    bool find(int);
    int count_nodes();
    int &operator[](int);
    friend std::ostream &operator<<(std::ostream &, DoubleLinkedList &);
};