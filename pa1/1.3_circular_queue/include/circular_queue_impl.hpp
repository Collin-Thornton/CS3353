// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Circular Queue SOURCE
//   Date    -   2-18-20
//
// ##########################################   

#include "circular_queue.hpp"
#include <sstream>

template <class T>
CircularQueue<T>::CircularQueue(int size) {
    queue = new T[size];
    this->size = size;
}
template <class T>
CircularQueue<T>::~CircularQueue() {
    delete queue;
}
template <class T>
int CircularQueue<T>::insert(T key) {
    if(len+1 > size) throw std::invalid_argument("QUEUE OVERFLOW");
    queue[((first+len++)%size)] = key;
    return 1;
}
template <class T>
T CircularQueue<T>::pull() {
    if(--len < 0) throw std::invalid_argument("QUEUE UNDERFLOW");
    return queue[(first++%size)];
}
template <class T>
std::string CircularQueue<T>::toString() {
    std::ostringstream ss;
    if(len == 0 || size == 0) return "EMPTY";

    ss << queue[first];
    if(first < (first+len)%size) {
        for(int i=first+1; i<(first+len); ++i) ss << " -> " << queue[i];
    } else {
        for(int i=first+1; i<size; ++i) ss << " -> " << queue[i];
        for(int i=0; i<(first+len)%size; ++i) ss << " -> " << queue[i];
    }

    return ss.str();
}