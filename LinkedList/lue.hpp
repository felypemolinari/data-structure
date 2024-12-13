#include <iostream>
#include <string.h>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node <T> *next;
};

template<typename T>
struct LUE
{
    Node <T> *start;
    Node <T> *end;
};

template<typename T>
void bootLUE(LUE <T> &list)
{
    list.start = NULL;
    list.end = NULL;
}

template<typename T>
bool insertEndLUE(LUE <T> &list, T value)
{
    Node <T> *current = new Node <T>;
    if (current == NULL) return false;
    current->data = value;
    current->next = NULL;

    if (list.start == NULL)
    {
        list.start = current;
        list.end = current;
    }
    else
    {
        list.end->next = current;
        list.end = current;
    }
    
    return true;
}

template<typename T>
bool insertLUE(LUE <T> &list, T value)
{
    Node <T> *current = new Node <T>;
    if (current == NULL) return false;
    current->data = value;
    current->next = NULL;

    if (list.start == NULL)
    {
        list.start = current;
        list.end = current;
    }
    else if (list.start->data > value)
    {
        current->next = list.start;
        list.start = current;
    }
    else if (list.end->data < value)
    {
        list.end->next = current;
        list.end = current;
    }
    else
    {
        Node <T> *prev = list.start;

        while (prev != NULL)
        {
            if (prev->data < value && value < prev->next->data)
            {
                current->next = prev->next;
                prev->next = current;
            }
            prev = prev->next;
        }
    }

    return true;
}

template<typename T>
void displayLUE(LUE <T> &list)
{
    Node <T> *prev = list.start;
    while (prev != NULL)
    {
        cout << prev->data << " ";
        prev = prev->next;
    }
}

template<typename T>
Node <T> * researchLUE(LUE <T> &list, T value)
{
    Node <T> *prev = list.start;
    while (prev != NULL)
    {
        if (value == prev->data) return prev;
        prev = prev->next; 
    }
    return NULL;
}

template<typename T>
bool removeLUE(LUE <T> &list, T value)
{
    if (list.start == NULL) return false;
    Node <T> *temp;

    if (list.start->data == value)
    {
        temp = list.start;
        list.start = temp->next;
        if (list.end == temp) list.end = NULL;
    }
    else
    {
        Node <T> *prev;
        temp = list.start;
        while (temp != NULL)
        {
            if (temp->data == value) break;
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) return false;
        prev->next = temp->next;
        if (temp == list.end) list.end = prev;  
    }

    delete temp;
    return true;
}