// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Doubly Linked List SOURCE
//
// ##########################################   

#include "DoublyLinked.hpp"
#include <sstream>

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

    while(tmp != TAIL) {
        DoublyLinked* next = tmp->next;
        //free(tmp);
        tmp = next;
    }
    //free(HEAD);
    //free(TAIL);
    //free(tmp);
}
template<class T>
int DoublyLinked<T>::getSize() {
    DoublyLinked* tmp = HEAD;
    int i=0;
    while(tmp != TAIL) {
        tmp = tmp->next;
        ++i;
    }
    return i;
}
template<class T>
int DoublyLinked<T>::append(T key) {
    if(srch(key) == 1) return -2;

    DoublyLinked* tmp = TAIL;
    DoublyLinked* prev = tmp;
    
    tmp->next = new DoublyLinked(key);
    
    tmp = tmp->next;
    tmp->prev = prev;
    tmp->next = NULL;
    TAIL = tmp;

    return 1;
}
template<class T>
int DoublyLinked<T>::insert(T key, int prev_key) {
    if(srch(prev_key) == -1) return -1;
    if(srch(key) == 1) return -2;

    DoublyLinked* tmp = HEAD;
    while(tmp->key != prev_key) tmp = tmp->next;

    if(tmp == TAIL) return append(key); 
    if(tmp == HEAD) return insert(key);

    DoublyLinked* next = tmp->next;
    DoublyLinked* prev = tmp;
    tmp->next = new DoublyLinked(key);
    tmp = tmp->next;

    tmp->prev = prev;
    tmp->next = next;

    return true;
}
template<class T>
int DoublyLinked<T>::insert(T key) {
    if(srch(key) == 1) return -2;
    DoublyLinked* tmp = HEAD;
    DoublyLinked* next = tmp;

    tmp->key = key;
    tmp->prev = new DoublyLinked();
    
    tmp = tmp->prev;
    tmp->next = next;
    tmp->prev = NULL;
    HEAD = tmp;

    return 1;
}
template<class T>
int DoublyLinked<T>::del(T key) {
    if(srch(key) == -1) return -1;

    DoublyLinked* tmp = HEAD;
    while(tmp->key != key) tmp = tmp->next;

    if(tmp == HEAD) {
        HEAD = tmp->next;
        HEAD->prev = NULL;
        delete tmp;       
        return 1;
    }
    else if(tmp == TAIL) {
        TAIL = tmp->prev;
        TAIL->next = NULL;
        delete tmp;        
        return 1;
    }

    DoublyLinked* prev = tmp->prev;
    DoublyLinked* next = tmp->next;

    prev->next = next;
    next->prev = prev;
    free(tmp);
    return 1;
}
template<class T>
int DoublyLinked<T>::srch(T key) {
    DoublyLinked* tmp = HEAD;
    while(tmp != TAIL) {
        tmp = tmp->next;
        if(tmp->key == key) return 1;
    }
    
    return -1;
}
template<class T>
T DoublyLinked<T>::get(int index) {
    DoublyLinked* tmp = HEAD;
    int i=0;

    while(tmp != TAIL && i <= index) {
        tmp = tmp->next;
        ++i;
    }
    if(tmp == TAIL && i-1 != index) throw std::invalid_argument("T DoublyLinked<T>::get(int index). Index greater than list size.");
    return tmp->key;
}
template<class T>
std::string DoublyLinked<T>::toString() {
    if(TAIL == HEAD) return "NULL";

    DoublyLinked* tmp = HEAD;
    tmp = tmp->next;

    std::ostringstream ss;

    ss << tmp->key;
    while(tmp != TAIL) {
        tmp = tmp->next;
        ss << " -> " << tmp->key;
    }
    return ss.str();
}
