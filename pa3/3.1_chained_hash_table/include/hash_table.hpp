#ifndef HASH_TABLE
#define HASH_TABLE

#include <string>

#include "DoublyLinked.hpp"

class HashTable {
    private:
        DoublyLinked<int>* table;
        int s, length;

    public:
        HashTable(int length);
        ~HashTable();

        int insert(int key);
        int remove(int key);

        bool sch(int key);
        int size();

        std::string toString();

};


#endif