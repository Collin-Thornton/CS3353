// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Doubly Linked List INCLUDE
//
// ##########################################   


#ifndef DOUBLE_LINKED
#define DOUBLE_LINKED

#include <string>

template<class T>
class DoublyLinked {
    public:
        DoublyLinked();
        DoublyLinked(T key);
        ~DoublyLinked();

        bool append(T key);        
        bool insert(T key, int prev_key);
        bool del(T key);
        bool srch(T key);

        void toString(std::string* s);

        DoublyLinked* next;
        DoublyLinked* prev;
        T key;
        
        DoublyLinked* HEAD;
        DoublyLinked* TAIL;
};

#include "DoublyLinked_impl.hpp"
#endif