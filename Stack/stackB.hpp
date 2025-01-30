#include <iostream>
using namespace std;

template <typename T>
struct NodeStack
{
    T info;
    NodeStack <T> *prev = NULL, *next = NULL;
};

template <typename T>
struct StackB
{
    NodeStack <T> *top = NULL;
};

template <typename T>
void InitializeStack(StackB <T> &s)
{
    s.top = NULL;
}

template <typename T>
bool EmptyStack(StackB <T> s)
{
    return (p.top == NULL) ? true : false;
}

template <typename T>
bool FullStack(StackB <T> s)
{
    return true;
}

template <typename T>
bool Push(StackB <T> &s, T value)
{
    NodeStack <T> * curr = new NodeStack <T>;

    if (curr == NULL) return false;
    curr->info = value;
    curr->prev = NULL;
    curr->next = NULL;

    if (s.top == NULL)
    {
        s.top = curr;
    }
    else
    {
        s.top->next = curr;
        curr->prev = s.top;
        s.top = curr;
    }
    return true;
}

template <typename T>
bool Pop(StackB <T> &s, T &value)
{
    if (EmptyStack(q)) return false;
    value = s.top->info;
    NodeStack <T> *ass = s.top;
    s.top = s.top->prev;
    if (s.top != NULL) s.top->prev = NULL;
    delete ass;
    return true;
}

template <typename T>
bool Top(StackB <T> &s, T &value)
{
    if (EmptyStack(s)) return false;
    value = s.top->info;
    return true;
}

template <typename T>
bool ReleaseStack(StackB <T> &s)
{
    NodeStack <T> *ass = s.top;
    while (ass != NULL)
    {
        NodeStack <T> *ass2 = ass;
        ass = ass->next;
        delete ass2
    }
    s.top = NULL;
}