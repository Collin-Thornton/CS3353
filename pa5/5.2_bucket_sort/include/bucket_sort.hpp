// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Bucket Sort INCLUDE
//   Date    -   4-15-20
//
//
//  class BucketSort<T>
//      BucketSort(int size, int low, int high, bool descending = true)
//      void sort(T* data)
//
//  *NOTES*
//   -The range of inputs must be known
//   -This algorithm is most useful when the range is small compared to the number of inputs
//
// ##########################################  

#ifndef BUCKET_SORT
#define BUCKET_SORT

// TODO #include <thread>
#include "stack.hpp"

namespace DataStructures {
    template<class T>
    class BucketSort {
        private:
            void bucketSort(T *data) {
                for(int i=0; i<size; ++i) {
                        if(data[i] < low) throw std::invalid_argument("DATA LOWER THAN MIN");
                        else if(data[i] > range+low-1) throw std::invalid_argument("DATA HIGHER THAN MAX");

                        (descending) ? buckets[range-data[i]+low-1].push(data[i]) : buckets[data[i]-low].push(data[i]);                      
                }         
                int i=0;
                for(int j=0; j<range; ++j) {
                    while(!buckets[j].isEmpty() && i < size) {
                            data[i++] = buckets[j].pop();
                    }
                }
                return;   
            }        
            // TODO void parallelBucketSort()

            bool descending;
            int size, low, range;

            Stack<T>* buckets;
            // TODO const unsigned int MAX_THREADS = std::thread::hardware_concurrency();

        public:
            BucketSort(int size, int low, int high, bool descending = true) {     // TODO parallel_processing = true
                this->descending = descending;
                this->size = size;
                this->low = low;
                this->range = high-low+1;

                if(low > high) throw std::invalid_argument("Error: high must be greater than low.");

                buckets = new Stack<T>[range];
                //for(int i=0;i<range; ++i) buckets[i] = Stack<T>(true, 10);
            }      
            ~BucketSort() {
                delete[] buckets;
                buckets = NULL;
            }

        void sort(T *data) {                                                                                    // TODO Add support for parallization here
                bucketSort(data);
            }
    };
}
#endif