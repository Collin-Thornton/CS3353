<<<<<<< HEAD:pa3/3.3_double_hash_table/src/hash_table.cpp

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
=======

#include <sstream>

#include "../include/double_hash_table.hpp"

HashTable::HashTable(int length, int q) {
    this->length = length;
    table = new Bucket[length];
    for(int i=0; i<length; ++i) {
        table[i].full = false;
    }
    s = 0;
    this->q = q;
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

    int j = 1;
    int i = (index+j*(q-key%q)) % length;

    while(i != index && j < s) {
        if(!table[i].full) {
            table[i].key = key;
            table[i].full = true;
	        ++s;
            return i;
        }
        ++j;
        i = (index+j*(q-key%q)) % length;
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

    int j = 1;
    int i = (index+j*(q-key%q)) % length;

    while(i != index && j < s) {
        if(table[i].key == key) {
            table[i].full = false;
            return --s;
        }
        ++j;
        i = (index+j*(q-key%q)) % length;
    }    

    return -1; 
}
int HashTable::sch(int key) {
    if(s == 0) return false;

    int index = key % length;

    if(!table[index].full) return -3;
    if(table[index].key == key) return 0;

    int j = 1;
    int i = (index+j*(q-key%q)) % length;

    while(i != index && j < s) {
        if(table[i].key == key) return 0;
        ++j;
        i = (index+j*(q-key%q)) % length;
    }    

    return -3; 
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
>>>>>>> d3c6e459396879f16d82e4f01d29d727a09d9850:pa3/3.3_double_hash_table/src/double_hash_table.cpp
