// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Circular Queue INCLUDE
//   Date    -   2-18-20
//
// ##########################################   

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <string>

template <class T>
class CircularQueue {
    private:
        T* queue;

        
    public:
        CircularQueue(int size);
        ~CircularQueue();

        int insert(T key);
        T pull();

        std::string toString();

        int first = 0, len = 0, size = 0;
};
#include "circular_queue_impl.hpp"

#endif // CIRCULAR_QUEUE_H