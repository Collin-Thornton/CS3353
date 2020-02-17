// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Doubly Linked List SOURCE
//
// ##########################################   

#include "DoublyLinked.hpp"

DoublyLinked::DoublyLinked(int key) {
    HEAD = this;
    TAIL = this;
    this->key = key;

    prev = nullptr;
    next = nullptr;
}
DoublyLinked::~DoublyLinked() {
    DoublyLinked* tmp = HEAD;
    tmp = tmp->next;

    while(tmp != TAIL) {
        DoublyLinked* next = tmp->next;
        delete(tmp);
        tmp = next;
    }
    delete(tmp);
    delete(HEAD);
    delete(TAIL);
}

bool DoublyLinked::append(int key) {
    DoublyLinked* tmp = TAIL;
    DoublyLinked* prev = tmp;
    
    tmp->next = new DoublyLinked(key);
    
    tmp = tmp->next;
    tmp->prev = prev;
    tmp->next = nullptr;
    TAIL = tmp;

    return true;
}
bool DoublyLinked::insert(int key, int prev_key) {
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
bool DoublyLinked::del(int key) {
    if(!srch(key)) return false;

    DoublyLinked* tmp = HEAD;
    while(tmp->key != key) tmp = tmp->next;

    if(tmp == HEAD) {
        HEAD = tmp->next;
        delete(tmp);
        HEAD->prev = nullptr;
        return true;
    }
    else if(tmp == TAIL) {
        TAIL = tmp->prev;
        delete(tmp);
        TAIL->next = nullptr;
        return true;
    }

    DoublyLinked* prev = tmp->prev;
    DoublyLinked* next = tmp->next;

    prev->next = next;
    next->prev = prev;
    delete(tmp);
    return true;
}
bool DoublyLinked::srch(int key) {
    DoublyLinked* tmp = HEAD;
    while(tmp != TAIL) tmp = tmp->next;

    if(tmp->key == key) return true;
    
    return false;
}