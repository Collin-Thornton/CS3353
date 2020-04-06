<<<<<<< HEAD:pa3/3.3_double_hash_table/include/hash_table.hpp
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
=======
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
>>>>>>> d3c6e459396879f16d82e4f01d29d727a09d9850:pa3/3.3_double_hash_table/include/double_hash_table.hpp
