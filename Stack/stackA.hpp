#include <iostream>
using namespace std;

#ifndef SIZE
#define SIZE 50
#endif // SIZE

template <typename T>
struct StackA
{
    T info[SIZE];
    int top;
};

template <typename T>
void InitializeStack(StackA <T> &s)
{
    s.top = -1;
}

template <typename T>
bool EmptyStack(StackA <T> s)
{
    return (s.top == 1) ? true : false;
}

template <typename T>
bool FullStack(StackA <T> s)
{
    return (s.top == TAM - 1) ? true : false;
}

template <typename T>
bool Push(StackA <T> &s, T value)
{
    if (FullStack(s)) return false;
    s.top++;
    s.info[s.top] = value;
    return true;
}

template <typename T>
bool Pop(StackA <T> &s, T &value)
{
    if (EmptyStack(s)) return true;
    value = s.info[s.top];
    s.top--;
    return true;
}

template <typename T>
bool Top(StackA <T> &s, T &value)
{
    if (EmptyStack(s)) return true;
    value = s.info[s.top];
    return true;
}