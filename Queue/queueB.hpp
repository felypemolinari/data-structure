#include <iostream>
using namespace std;

template <typename T>
struct NodeQueueB{
    T info;
    NodeQueueB <T> *prev=NULL, *next=NULL;
};

template <typename T>
struct QueueB{
    NodeQueueB <T> *begin=NULL, *end=NULL;
};

template <typename T>
void InitializeQueue(QueueB <T> &q)
{
    q.begin = NULL;
    q.end = NULL;
}

template <typename T>
bool EmptyQueue(QueueB <T> q)
{
    return (q.begin == NULL) ? true : false;
}

template <typename T>
bool FullQueue(QueueB <T> q)
{
    return true;
}

template <typename T>
bool Queue(QueueB <T> &q, T value)
{
    NodeQueueB <T> *curr = new NodeQueueB <T>;

    if (curr == NULL) return false;
    curr->info = value;
    curr->prev = NULL;
    curr->next = NULL;

    if (q.end == NULL)
    {
        q.begin = curr;
        q.end = curr;
    }
    else
    {
        q.begin->next = curr;
        curr->prev = q.end;
        q.end = curr;
    }
    
    return true;
}

template <typename T>
bool Dequeue(QueueB <T> &q, T value)
{
    if (EmptyQueue(q)) return false;
    value = q.end->info;
    NodeQueueB <T> *ass = q.begin;
    q.begin = q.begin->next;
    if (q.begin != NULL) q.begin->prev = NULL;
    delete ass;
    return true;
}

template <typename T>
bool ReleaseQueue(QueueB <T> &q)
{
    NodeQueueB <T> *ass = q.begin;
    while (ass != NULL)
    {
        NodeQueueB <T> *ass2 = ass;
        ass = ass->next;
        delete ass2;
    }
    q.begin = NULL;
    q.end = NULL;
}