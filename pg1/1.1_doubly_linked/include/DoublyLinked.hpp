// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Doubly Linked List INCLUDE
//
// ##########################################   


#ifndef DOUBLE_LINKED
#define DOUBLE_LINKED

class DoublyLinked {
    public:
        DoublyLinked(int key);
        ~DoublyLinked();

        bool append(int key);        
        bool insert(int key, int prev_key);
        bool del(int key);
        bool srch(int key);

        DoublyLinked* next;
        DoublyLinked* prev;
        int key;
        
        DoublyLinked* HEAD;
        DoublyLinked* TAIL;
};

#endif DOUBLE_LINKED