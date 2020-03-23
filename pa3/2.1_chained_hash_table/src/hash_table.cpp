
#include <sstream>

#include "../include/hash_table.hpp"

HashTable::HashTable(int length) {
    this->length = length;
    table = new DoublyLinked<int>[length];
    for(int i=0; i<length; ++i) {
        table[i] = DoublyLinked<int>(false);
    }
    s = 0;
}
HashTable::~HashTable() {
    delete table;
}

int HashTable::insert(int key) {
    int index = key % length;

    table[index].append(key);
    ++s;
    return index;
}
int HashTable::remove(int key) {
    if(s == 0) return 1;

    int index = key % length;

    if(table[index].getSize == 0) return 2;
    if(!table[index].srch(key)) return 2;
    
    table[index].del(key);
    --s;
    return 0; 
}
bool HashTable::sch(int key) {
    if(s == 0) return false;

    int index = key % length;
    if(table[index].srch(key)) return true;
    return false;
}
int HashTable::size() {
    return s;
}
std::string HashTable::toString() {
    std::ostringstream ss;
    for(int i=0; i<length; ++i) {
        ss << "[" << i << "]\t" << table[i].toString() << '\n';
    }
    return ss.str();
}