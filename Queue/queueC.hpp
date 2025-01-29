#include <iostream>
using namespace std;

// CIRCLE QUEUE

#ifndef SIZE
#define SIZE 50
#endif // SIZE

template <typename T>
struct QueueC
{
    T info[SIZE];
    int begin, end;
    int cont;
};

template <typename T>
void InitializeQueue(QueueC <T> &q)
{
    q.begin = 0;
    q.end = -1;
    q.cont = 0;
}

template <typename T>
bool EmptyQueue(QueueC <T> q)
{
    return (q.cont == 0) ? true : false;
}

template <typename T>
bool FullQueue(QueueC <T> q)
{
    return (q.cont == SIZE) ? true : false; 
}

template <typename T>
bool Queue(QueueC <T> &q, T value)
{
    if (FullQueue(q)) return false;
    q.end++;
    if (q.end == SIZE) q.end = 0;
    q.info[q.end] = value;
    q.cont++;
    return true;
}

template <typename T>
bool Dequeue(QueueC <T> &q, T value)
{
    if (EmptyQueue(q)) return false;
    value = q.info[q.begin];
    q.begin++;
    if (q.begin == SIZE) q.begin = 0;
    q.cont--;
    return true;
}