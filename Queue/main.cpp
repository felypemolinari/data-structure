#include <iostream>
#include "queueA.hpp"
#include "queueB.hpp"
#include "queueC.hpp"

using namespace std;

// Queue A
int main()
{
    QueueA<int> q;

    InitializeQueue(q);
    Queue(q, 10);
    Queue(q, 20);
    Queue(q, 30);

    for (int i = q.begin; i <= q.end; i++) 
    {
        cout << q.info[i] << " ";
    }
}

