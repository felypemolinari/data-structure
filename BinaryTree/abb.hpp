#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T info;
    Node <T> *left=NULL, *right=NULL;
};

template <typename T>
void prefixed(Node <T> *source)
{
    if (source == NULL) return;
    cout << source->info << " ";
    prefixed(source->left);
    prefixed(source->right);
}

template <typename T>
void infixed(Node <T> *source)
{
    if (source == NULL) return;
    infixed(source->left);
    cout << source->info << " ";
    infixed(source->right);
}

template <typename T>
void postfixed(Node <T> *source)
{
    if (source == NULL) return;
    postfixed(source->left);
    postfixed(source->right);
    cout << source->info << " ";
}

template <typename T>
int count(Node <T> *source)
{
    if (source == NULL) return 0;
    return 1 + count(source->left) + count(source->right);
}

template <typename T>
bool insertABB(Node <T> *&source, T info)
{
    if (source == NULL)
    {
        source = new Node<T>;
        if (source == NULL) return false;
        source->info = info;
        return true;
    }
    if (info == source->info) return false;
    if (info < source->info)
        return inserABB(source->left, info);
    else
        return insertABB(source->right, info);   
}

template <typename T>
T lookForGreaterValue(Node <T> *source)
{
    if (source->right == NULL)
        return source->info;
    else
        return lookForGreaterValue(source->right);
}