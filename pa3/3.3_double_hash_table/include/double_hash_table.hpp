#ifndef HASH_TABLE
#define HASH_TABLE

#include <string>

class HashTable {
    private:
        struct Bucket {
            bool full;
            int key;
        };

        Bucket* table;
        int s, length, q;

    public:
        HashTable(int length, int q);
        ~HashTable();

        int insert(int key);
        int remove(int key);

        int sch(int key);
        int size();

        std::string toString();

};


#endif
