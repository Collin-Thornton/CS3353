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
    private:
        DoublyLinked(T key);
    public:
        DoublyLinked();
        ~DoublyLinked();

        int append(T key);        
        int insert(T key, int prev_key);
        int insert(T key);
        int del(T key);

        int srch(T key);
        T get(int index);
        int getSize();

        std::string toString();

        DoublyLinked* next;
        DoublyLinked* prev;
        T key;
        
        DoublyLinked* HEAD;
        DoublyLinked* TAIL;
};

#include "DoublyLinked_impl.hpp"
#endif