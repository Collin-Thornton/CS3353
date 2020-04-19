// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Merge Sort INCLUDE
//   Date    -   4-15-20
//
//
//  class MergeSort<K>
//      MergeSort(int size, bool descending = true)
//      sort(K *data)
//
//  class MergeSortKV<K,V>
//      MergeSortKV(int size, bool descending = true)
//      sort(K *keys, V *values)
//
//  *NOTES*
//   -K must be implement all comparison operators. If not base class, you must \
//      overload the operators in the the class definition.
//   -T must implement the insertion operator (<<). If not base class, you must \
//      overload the operator in the class defition.
//   -MergeSortKV creates an array of KeyValue objects of length size. Data to be sorted \
//      is copied into this array.
//
// ##########################################  

#ifndef MERGE_SORT
#define MERGE_SORT

// TODO #include <thread>

#include "key_value.hpp"

namespace DataStructures {
    template<typename K, typename V>
    class MergeSortKV {
        private:
            void mergeSort(KeyValue<K,V> **data, int n) {
                if(n < 2) return;

                KeyValue<K,V> *s1[n/2], *s2[n/2 + n%2];
                for(int i=0; i<n/2; ++i) {
                    s1[i] = data[i];
                }
                for(int i=0; i<(n/2 + n%2); ++i) {
                    s2[i] = data[i+n/2];
                }

                mergeSort(s1, n/2);
                mergeSort(s2, n/2+n%2);
                merge(s1, n/2, s2, n/2+n%2, data);
            }
            // TODO void parallelMergeSort()
            void merge(KeyValue<K,V> **s1, int size1, KeyValue<K,V> **s2, int size2, KeyValue<K,V> **s) {
                int i=0, j=0, k=0;
                if(descending) {
                    while(i < size1 && j < size2) {
                        s[k++] = (*s1[i] >= *s2[j]) ? s1[i++] : s2[j++];
                    }
                    while(i < size1) {
                        s[k++] = s1[i++];
                    }
                    while(j < size2) {
                        s[k++] = s2[j++];
                    }
                }
                else {
                    while(i < size1 && j < size2) {
                        s[k++] = (*s1[i] <= *s2[j]) ? s1[i++] : s2[j++];
                    }
                    while(i < size1) {
                        s[k++] = s1[i++];
                    }
                    while(j < size2) {
                        s[k++] = s2[j++];
                    }
                }
            }

            bool descending;
            int size;

            // TODO const unsigned int MAX_THREADS = std::thread::hardware_concurrency();
        public:
            MergeSortKV(int size, bool descending = true) {
                this->descending = descending;
                this->size = size;
            }
            void sort(K *keys, V *values) {          // TODO Add support for parallization here
                KeyValue<K,V> *data[size];
                K k[size];
                V v[size];
                for(int i=0; i<size; ++i) {
                    try {
                        k[i] = keys[i];
                        v[i] = values[i];
                        data[i] = new KeyValue<K,V>(k[i], v[i]);
                    } catch(...) {
                        break;
                    }
                }

                mergeSort(data, size);          

                for(int i=0; i<size; ++i) {
                    try{
                        keys[i]   = data[i]->getKey();
                        values[i] = data[i]->getValue();
                        delete data[i];
                    } catch (...) {
                        break;
                    }
                }
            }
    };

    template<typename K>
    class MergeSort {
        private:
            void mergeSort(K *data, int n) {
                if(n < 2) return;

                K s1[n/2], s2[n/2 + n%2];
                for(int i=0; i<n/2; ++i) {
                    s1[i] = data[i];
                }
                for(int i=0; i<(n/2 + n%2); ++i) {
                    s2[i] = data[i+n/2];
                }

                mergeSort(s1, n/2);
                mergeSort(s2, n/2+n%2);
                merge(s1, n/2, s2, n/2+n%2, data);
            }
            // TODO void parallelMergeSort()
            void merge(K *s1, int size1, K *s2, int size2, K *s) {
                int i=0, j=0, k=0;
                if(descending) {
                    while(i < size1 && j < size2) {
                        s[k++] = (s1[i] >= s2[j]) ? s1[i++] : s2[j++];
                    }
                    while(i < size1) {
                        s[k++] = s1[i++];
                    }
                    while(j < size2) {
                        s[k++] = s2[j++];
                    }
                }
                else {
                    while(i < size1 && j < size2) {
                        s[k++] = (s1[i] <= s2[j]) ? s1[i++] : s2[j++];
                    }
                    while(i < size1) {
                        s[k++] = s1[i++];
                    }
                    while(j < size2) {
                        s[k++] = s2[j++];
                    }
                }
            }

            bool descending;
            int size;

            // TODO const unsigned int MAX_THREADS = std::thread::hardware_concurrency();
        public:
            MergeSort(int size, bool descending = true) {
                this->descending = descending;
                this->size = size;
            }
            void sort(K *data) {          // TODO Add support for parallization here
                mergeSort(data, size);
            }
    };    
}
#endif