#include <iostream>
using namespace std;

#ifndef SIZE
#define SIZE 50
#endif // SIZE

template <typename T>
struct QueueA
{
    T info[SIZE];
    int begin, end;
};

template <typename T>
void InitializeQueue(QueueA <T> &q)
{
    q.begin = 0;
    q.end = -1;
}

template <typename T>
bool EmptyQueue(QueueA <T> q)
{
    return (q.end < q.begin) ? true : false;
}

template <typename T>
bool FullQueue(QueueA <T> &q)
{
    return (q.end == SIZE - 1) ? true : false;
}

template <typename T>
bool Queue(QueueA <T> &q, T value)
{
    if (FullQueue(q)) return false;
    q.end++;
    q.info[q.end] = value;
    return true;
}

template <typename T>
bool Dequeue(QueueA <T> &q, T &value){
    if(EmptyQueue(q)) return false;
    value = q.info[q.begin];
    q.begin++;
    return true;
}