// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Doubly Linked List SOURCE
//
// ##########################################   

#include "DoublyLinked.hpp"

#include <iostream>


template<class T>
DoublyLinked<T>::DoublyLinked() { 
    HEAD = this;
    TAIL = this;
}
template<class T>
DoublyLinked<T>::DoublyLinked(T key) {
    HEAD = this;
    TAIL = this;
    this->key = key;

    prev = NULL;
    next = NULL;
}
template<class T>
DoublyLinked<T>::~DoublyLinked() {      //! Work on this
    DoublyLinked* tmp = HEAD;
    tmp = tmp->next;
    while(tmp->next != TAIL) {
        //std::cout << c++ << std::endl;
        DoublyLinked* next = tmp->next;
        //delete tmp;
        tmp = next;
    }
    //delete HEAD;
    //delete TAIL;
}
template<class T>
bool DoublyLinked<T>::append(T key) {
    DoublyLinked* tmp = TAIL;
    DoublyLinked* prev = tmp;
    
    tmp->next = new DoublyLinked(key);
    
    tmp = tmp->next;
    tmp->prev = prev;
    tmp->next = NULL;
    TAIL = tmp;

    return true;
}
template<class T>
bool DoublyLinked<T>::insert(T key, int prev_key) {
    if(!srch(prev_key)) return false;

    DoublyLinked* tmp = HEAD;
    while(tmp->key != prev_key) tmp = tmp->next;

    if(tmp == TAIL) return append(key); 

    DoublyLinked* next = tmp->next;
    DoublyLinked* prev = tmp;
    tmp->next = new DoublyLinked(key);
    tmp = tmp->next;

    tmp->prev = prev;
    tmp->next = next;

    return true;
}
template<class T>
bool DoublyLinked<T>::del(T key) {
    if(!srch(key)) return false;

    DoublyLinked* tmp = HEAD;
    while(tmp->key != key) tmp = tmp->next;

    if(tmp == HEAD) {
        HEAD = tmp->next;
        delete(tmp);
        HEAD->prev = NULL;
        return true;
    }
    else if(tmp == TAIL) {
        TAIL = tmp->prev;
        delete(tmp);
        TAIL->next = NULL;
        return true;
    }

    DoublyLinked* prev = tmp->prev;
    DoublyLinked* next = tmp->next;

    prev->next = next;
    next->prev = prev;
    delete(tmp);
    return true;
}
template<class T>
bool DoublyLinked<T>::srch(T key) {
    DoublyLinked* tmp = HEAD;
    while(tmp != TAIL) tmp = tmp->next;

    if(tmp->key == key) return true;
    
    return false;
}
template<class T>
void DoublyLinked<T>::toString(std::string *s) {
    DoublyLinked* tmp = HEAD;

    while(tmp != TAIL) {
        s->append(tmp->key + '\n');
        tmp = tmp->next;
    }
    s->append(TAIL->key + '\n' + '\n');
    return;
}