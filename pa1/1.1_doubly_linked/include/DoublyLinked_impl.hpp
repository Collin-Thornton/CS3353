// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Doubly Linked List SOURCE
//
// ##########################################   

#include "DoublyLinked.hpp"
#include <sstream>

template<class T>
DoublyLinked<T>::DoublyLinked(bool allow_dupplicates) { 
    this->allow_dupplicates = allow_dupplicates;
    Node* node = new Node;
    HEAD = node;
    TAIL = node;
}
template<class T>
DoublyLinked<T>::DoublyLinked(T key, bool allow_dupplicates) {
    Node* node = new Node;
    HEAD = node;
    TAIL = node;
    node->key = key;
    this->allow_dupplicates = allow_dupplicates;

    node->prev = NULL;
    node->next = NULL;
}
template<class T>
DoublyLinked<T>::~DoublyLinked() {      //! Work on this
    Node* tmp = HEAD;

    while(tmp != TAIL) {
        Node* next = tmp->next;
        //free(tmp);
        tmp = next;
    }
    //free(HEAD);
    //free(TAIL);
    //free(tmp);
}
template<class T>
struct DoublyLinked<T>::Node* DoublyLinked<T>::create_node(T key, Node* next, Node* prev) {
    Node* new_node = new Node;
    new_node->key = key;
    if(next != nullptr) new_node->next = next;
    if(prev != nullptr) new_node->prev = prev;

    return new_node;
}
template<class T>
int DoublyLinked<T>::getSize() {
    Node* tmp = HEAD;
    int i=0;
    while(tmp != TAIL) {
        tmp = tmp->next;
        ++i;
    }
    return i;
}
template<class T>
int DoublyLinked<T>::append(T key) {
    if(!allow_dupplicates && srch(key) == 1) return -2;

    Node* tmp = TAIL;    
    tmp->next = create_node(key, NULL, tmp);
    TAIL = tmp->next;

    return 1;
}
template<class T>
int DoublyLinked<T>::insert(T key, int prev_key) {
    if(srch(prev_key) == -1) return -1;
    if(!allow_dupplicates && srch(key) == 1) return -2;

    Node* tmp = HEAD;
    while(tmp->key != prev_key) tmp = tmp->next;

    if(tmp == TAIL) return append(key); 
    if(tmp == HEAD) return insert(key);

    Node* prev = tmp;
    tmp->next = create_node(key, tmp->next, tmp->prev);
    tmp = tmp->next;
    tmp = tmp->next;
    tmp->prev = prev;

    return true;
}
template<class T>
int DoublyLinked<T>::insert(T key) {
    if(!allow_dupplicates && srch(key) == 1) return -2;
    Node* tmp = HEAD;
    Node* next = tmp;

    tmp->key = key;
    tmp->prev = create_node(key, tmp, NULL);
    HEAD = tmp->prev;

    return 1;
}
template<class T>
int DoublyLinked<T>::del(T key) {
    if(srch(key) == -1) return -1;

    Node* tmp = HEAD;
    while(tmp->key != key) tmp = tmp->next;

    if(tmp == HEAD) {
        HEAD = tmp->next;
        HEAD->prev = NULL;
        delete tmp;       
        return 1;
    }
    if(tmp == TAIL) {
        TAIL = tmp->prev;
        TAIL->next = NULL;
        delete tmp;        
        return 1;
    }

    Node* prev = tmp->prev;
    Node* next = tmp->next;

    prev->next = next;
    next->prev = prev;
    delete tmp;
    return 1;
}
template<class T>
int DoublyLinked<T>::srch(T key) {
    Node* tmp = HEAD;
    while(tmp != TAIL) {
        tmp = tmp->next;
        if(tmp->key == key) return 1;
    }
    
    return -1;
}
template<class T>
T DoublyLinked<T>::get(int index) {
    Node* tmp = HEAD;
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

    Node* tmp = HEAD;
    tmp = tmp->next;

    std::ostringstream ss;

    ss << tmp->key;
    while(tmp != TAIL) {
        tmp = tmp->next;
        ss << " -> " << tmp->key;
    }
    return ss.str();
}
