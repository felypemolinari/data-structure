#include <iostream>
#include "LinkedList/lde.hpp"
using namespace std;

#define SIZE 10

struct Hash
{
    LDE<int> list[SIZE];
};

int hashing(int key)
{
    int sum = 0, res;

    for (int i = 0; i < key; i++)
    {
        sum += key;
    }
    
    res = sum % SIZE;
    return res;
}

void InitializeHash(Hash &table)
{
    for(int i = 0; i < SIZE; i++)
    {
        bootLDE(table.list[i]);
    }
}

void eraseHash(Hash &table)
{
    for(int i = 0; i < SIZE; i++)
    {
        releaseLDE(table.list[i]);
    }
}

bool insertHash(Hash &table, int value)
{
    int res = hashing(value);
    if (researchLDE(table.list[res], value) == NULL)
        return insertLDE(table.list[res], value);
    else
        return false;
}

bool removeHash(Hash &table, int value)
{
    int res = hashing(value);
    return toRemoveLDE(table.list[res], value);
}

bool searchHash(Hash table, int value){
    int res = hashing(value);
    return (researchLDE(table.list[res], value) == NULL) ? false : true;
}