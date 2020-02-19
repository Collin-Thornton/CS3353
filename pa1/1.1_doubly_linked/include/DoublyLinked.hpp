// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Doubly Linked List INCLUDE
//   Date    -   2-17-20
//
// ##########################################   


#ifndef DOUBLE_LINKED
#define DOUBLE_LINKED

#include <string>

template<class T>
class DoublyLinked {
    private:
        DoublyLinked(T key, bool allow_dupplicates);
        bool allow_dupplicates = false;

        struct Node {
            T key;
            struct Node* next;
            struct Node* prev;
        };

        struct Node* create_node(T key, Node* next = nullptr, Node* prev = nullptr);

    public:
        DoublyLinked(bool allow_dupplicates = false);
        ~DoublyLinked();

        int append(T key);        
        int insert(T key, int prev_key);
        int insert(T key);
        int del(T key);

        int srch(T key);
        T get(int index);
        int getSize();

        std::string toString();
        
        Node* HEAD;
        Node* TAIL;
};

#include "DoublyLinked_impl.hpp"
#endif