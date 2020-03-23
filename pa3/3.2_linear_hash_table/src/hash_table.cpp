
#include <sstream>

#include "../include/hash_table.hpp"

HashTable::HashTable(int length) {
    this->length = length;
    table = new Bucket[length];
    for(int i=0; i<length; ++i) {
        table[i].full = false;
    }
    s = 0;
}
HashTable::~HashTable() {
    //delete table;
}

int HashTable::insert(int key) {
    int index = key % length;

    if(s == length) return -2;
    if(!table[index].full) {
        table[index].key = key;
	table[index].full = true;
	++s;
        return index;
    }

    int i = (index+1) % length;
    while(i != index) {
        if(!table[i].full) {
            table[i].key = key;
            table[i].full = true;
	    ++s;
            return i;
        }
        i = (++i) % length;
    }
    return -2;
}
int HashTable::remove(int key) {
    if(s == 0) return -1;

    int index = key % length;

    if(!table[index].full) return -2;
    if(table[index].key == key) {
	table[index].full = false;
	return --s;
    }
    int i = (index+1) % length;
    while(i != index && !table[i].full) {
        if(table[i].key == key) {
            table[i].full = false;
            return --s;
        }
        i = (++i) % length;
    }    

    return -1; 
}
bool HashTable::sch(int key) {
    if(s == 0) return false;

    int index = key % length;

    if(!table[index].full) return -2;
    if(table[index].key == key) return true;

    int i = (index+1) % length;
    while(i != index && !table[i].full) {
        if(table[i].key == key) return true;
        i = (++i) % length;
    }    

    return false; 
}
int HashTable::size() {
    return s;
}
std::string HashTable::toString() {
    std::ostringstream ss;
    for(int i=0; i<length; ++i) {
        ss << "[" << i << "]\t";
        if(table[i].full) ss << table[i].key << '\n';
        else ss << '\n';
    }
    return ss.str();
}
