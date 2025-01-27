#include <iostream>
#include <string.h>
using namespace std;

template<typename T>
struct Node 
{
    T info;
    Node <T> *nextA, *nextP;
};

template<typename T>
struct LDE
{
    Node <T> *begin;
    Node <T> *end;
};

template<typename T>
void bootLDE(LDE <T> &list)
{
    list.begin = NULL;
    list.end = NULL;
}

template<typename T>
bool insertEndLDE( LDE <T> &list, T value )
{
    Node <T> *current = new Node <T>;

    if( current == NULL ) return false;
    current->info = value;
    current->nextA = NULL;
    current->nextP = NULL;

    if( list.begin == NULL ){ // Empty list
        list.begin = current;
        list.end = current;
    } else {
        list.end->nextP = current;
        current->nextA = list.end;
        list.end = current;
    }
    return true;
}

template<typename T>
bool insertLDE( LDE <T> &list, T value )
{
    Node <T> *current = new Node <T>;

    if( current == NULL ) return false;
    current->info = value;
    current->nextA = NULL;
    current->nextP = NULL;

    if( list.begin == NULL ){ // Case a
        list.begin = current;
        list.end = current;
    }
    else if( value < list.begin->info ){ // Case b
        current->nextP = list.begin;
        list.begin->nextA = current;
        list.begin = current;
    }
    else if( value > list.end->info ){ // Case c
        list.end->nextP = current;
        current->nextA = list.end;
        list.end = current;
    }
    else{ // Caso d
        Node <T> *ant = list.begin;
        while( ant != NULL ){
            if( ant->info < value && value < ant->nextP->info ){
                current->nextP = ant->nextP;
                current->nextA = ant;
                ant->nextP->nextA = current;
                ant->nextP = current;
                break;
            }
            ant = ant->nextP;
        }
    }
    return true;
}

template<typename T>
void displayLDE( LDE <T> list, char sequence ){
    Node <T> *aux = (sequence == 'C') ? list.begin : list.end;
    while( aux != NULL ){
        cout << aux->info << "  ";
        aux = (sequence == 'C') ? aux->nextP : aux->nextA;
        /* if( ordem == 'C' )
               aux = aux->eloP;
           else
               aux = aux->eloA;
        */
    }
}

template<typename T>
void releaseLDE(LDE <T> &list){
    Node <T> *aux = list.begin;
    Node <T> *aux2;
    while( aux != NULL ){
        aux2 = aux;
        aux = aux->nextP;
        delete aux2;
    }
}

template<typename T>
Node <T> * researchLDE(LDE <T> &list, T value){
    Node <T> *aux = list.begin;
    while( aux != NULL ){
        if( value == aux->info ) return aux;
        aux = aux->nextP;
    }
    return NULL;
}

template <typename T>
bool toRemoveLDE( LDE <T> &list, T value ){
    Node <T> *aux = researchLDE(list, value);
    if( aux == NULL ) return false; // Não localizou valor

    if( aux == list.begin ){
        if( aux == list.end ){ // Case a
            list.begin = NULL;
            list.end = NULL;
        } else {  // Case b
            list.begin = aux->nextP;
            list.begin->nextA = NULL;
        }
    }
    else if( aux == list.end ){ // Case c
        list.end = aux->nextA;
        list.end->nextP = NULL;
    }
    else{ // Case d
        Node <T> *ant = aux->nextA;
        Node <T> *next = aux->nextP;
        ant->nextP = next;
        next->nextA = ant;
    }
    delete aux;
    return true;
}
