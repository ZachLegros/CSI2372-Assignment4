#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
    size = 0;
    head = NULL;
    tail = NULL;
    dummy = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
    if (size == 0 || head == NULL)
        return;

    Node *current = head;
    for (int i = 0; i < size; i++)
    {
        Node *temp = current->next;
        delete current;
        current = temp;
    }
}

bool DoubleLinkedList::add_to_front(int value)
{
    Node *new_node = new Node;
    new_node->value = value;
    new_node->prev = NULL;
    if (head == NULL)
        new_node->next = NULL;
    else
    {
        new_node->next = head;
        head->prev = new_node;
    }
    head = new_node;
    if (tail == NULL)
        tail = new_node;

    size++;
    return true;
}

bool DoubleLinkedList::add_to_back(int value)
{
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = NULL;

    if (tail == NULL)
        new_node->prev = NULL;
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
    }
    tail = new_node;
    if (head == NULL)
        head = new_node;

    size++;
    return true;
}

bool DoubleLinkedList::insert_item(int pos, int value)
{
    Node *target;
    Node *new_node;
    if (pos == 0)
        return add_to_front(value);
    else if (pos == size - 1)
    {
        return add_to_back(value);
    }

    new_node = new Node;

    if (new_node == NULL)
        return false;

    new_node->value = value;
    new_node->next = NULL;

    target = head;
    for (int i = 0; i < pos - 1; ++i)
        target = target->next;

    new_node->next = target->next;
    new_node->prev = target;
    target->next->prev = new_node;
    target->next = new_node;
    size++;
    return true;
}

void DoubleLinkedList::remove_item(int value)
{
    if (head == NULL || tail == NULL)
        return;

    if (head->value == value)
    {
        remove_from_front();
        return;
    }

    if (tail->value == value)
    {
        remove_from_back();
        return;
    }

    Node *target;
    for (target = head; target->next != NULL; target = target->next)
    {
        if (target->next->value == value)
        {
            Node *temp = target->next;
            if (target->next->next)
                target->next->next->prev = target;
            target->next = target->next->next;
            delete temp;
            size--;
            break;
        }
    }
}

void DoubleLinkedList::remove_from_front()
{
    if (head == NULL)
        return;

    Node *temp = head;
    if (tail->next)
        head->next->prev = NULL;
    head = head->next;
    delete temp;
    size--;
}

void DoubleLinkedList::remove_from_back()
{
    if (tail == NULL)
        return;

    Node *temp = tail;
    if (tail->prev)
        tail->prev->next = NULL;
    tail = tail->prev;
    delete temp;
    size--;
}

bool DoubleLinkedList::find(int value)
{
    if (head == NULL || tail == NULL)
        return false;

    if (head->value == value)
        return true;

    if (tail->value == value)
        return true;

    Node *target;
    for (target = head; target->next != NULL; target = target->next)
    {
        if (target->next->value == value)
        {
            return true;
        }
    }
    return false;
}

int DoubleLinkedList::count_nodes()
{
    return size;
}

int DoubleLinkedList::get_head()
{
    return head->value;
}

int DoubleLinkedList::get_tail()
{
    return tail->value;
}

int &DoubleLinkedList::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Index out of range!" << std::endl;
        return dummy;
    }

    Node *current = head;
    for (int i = 0; i < index; ++i)
        current = current->next;

    return current->value;
}

std::ostream &operator<<(std::ostream &out, DoubleLinkedList &list)
{
    for (int i = 0; i < list.size; ++i)
    {
        if (i != 0)
            out << ", ";
        out << list[i];
    }

    return out;
}