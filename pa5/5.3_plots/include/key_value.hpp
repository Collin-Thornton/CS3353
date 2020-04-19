// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Container class for key-value datatypes
//   Date    -   4-16-20
//
//   class KeyValue<K,V>
//      KeyValue()
//      KeyValue(const K &key, const V &value): key(key), value(value)
//      K getKey() const
//      V getValue() const
//      void setKey(K const &k)
//      void setValue(V const &v)
//
//      -- overloading all comparison operators to work with key --
//
//  *NOTES*
//   -K must be implement all comparison operators. If not base class, you must \
//      overload the operators in the the class definition.
//
// ##########################################   

#ifndef KEY_VALUE
#define KEY_VALUE

#include <iostream>

namespace DataStructures {
    template<typename K, typename V>
    class KeyValue {
        public:
            KeyValue() {}
            KeyValue(const K &key, const V &value) {
                this->key   = &key;
                this->value = &value;
            }
            const K& getKey()             { return *key;   }
            const V& getValue()           { return *value; }

            friend bool operator==(const KeyValue& lhs, const KeyValue& rhs)    { return (*lhs.key == *rhs.key); }
            friend bool operator!=(const KeyValue& lhs, const KeyValue& rhs)    { return (*lhs.key != *rhs.key); }   
            friend bool operator<(const KeyValue& lhs, const KeyValue& rhs)     { return (*lhs.key <  *rhs.key); }
            friend bool operator>(const KeyValue& lhs, const KeyValue& rhs)     { return (*lhs.key >  *rhs.key); }   
            friend bool operator<=(const KeyValue& lhs, const KeyValue& rhs)    { return (*lhs.key <= *rhs.key); }
            friend bool operator>=(const KeyValue& lhs, const KeyValue& rhs)    { return (*lhs.key >= *rhs.key); }   

            friend std::ostream& operator<<(std::ostream& os, const KeyValue& v) { os << *v.value; return os; }   

            friend int operator-(const int &lhs, const KeyValue& rhs)       { return (lhs - *rhs.key); }   
            friend int operator-(const KeyValue& lhs, const int &rhs)       { return (*lhs.key - rhs); }    
            friend int operator+(const int &lhs, const KeyValue &rhs)       { return (lhs + *rhs.key); }
            friend int operator+(const KeyValue& lhs, const int &rhs)       { return (*lhs.key + rhs); }

            bool operator==(int rhs)    const { return (*key == rhs); }
            bool operator<(int rhs)     const { return (*key < rhs);  }
            bool operator>(int rhs)     const { return (*key > rhs);  }
            bool operator>=(int rhs)    const { return (*key >= rhs); }
            bool operator<=(int rhs)    const { return (*key <= rhs); }  
            bool operator%(int rhs)     const { return (*key % rhs);  }
            bool operator!=(int rhs)    const { return (*key != rhs); }

        private:
            const K *key;
            const V *value;
    };
}

#endif