// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Circular Queue Source
//   Date    -   5-2-20
// 
//  class CircularQueue<T>
//      CircularQueue(int s)
//      int insert(const T &key)
//      T& remove()
//      int size()
//      bool isEmpty()
//      std::string toString()
//
//  *Notes*
//   -T must implement the insertion operator (<<). If not base class, you must \
//      overload the operator in the class defition.
//
// ##########################################   


#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <string>
#include <sstream>

#include "constants.hpp"

namespace DataStructures {
    template <class T>
    class CircularQueue {
        private:
            void resize(int length) {
                T* new_queue = new T[length];

                for(int i=0; i<=len; ++ i) {
                    new_queue[i] = queue[i];
                }
                this->s = length;

                delete[] queue;
                queue = new_queue;
                new_queue = NULL;
                
                return;
            }

            T* queue;
            int first = 0, len = 0, s = 0;
            bool dynamic;
            
        public:
            CircularQueue(bool dynamic = true, int s = 10) {
                queue = new T[s];
                this->s = s;
            }
            ~CircularQueue() {
                delete[] queue;
            }

            int insert(const T &key) {

                if(len+1 > s && dynamic) resize(s*2);
                else if(len+1 > s) return OVERFLOW;

                queue[((first+len++)%s)] = key;
                return 1;
            }
            T& remove() {
                if(len == 0) throw std::invalid_argument("QUEUE UNDERFLOW");
                if(dynamic && len < s/4) resize(s/2);

                --len;
                return queue[(first++%s)];
            }
            T* arr() {
                T* out = new T[len];

                for(int i=first; i<first+len; ++i) {
                    out[i-first] = queue[(i%s)];
                }
                return out;
            }
            int size() {
                return len;
            }
            bool isEmpty() {
                return (len == 0);
            }

            std::string toString() {
                std::ostringstream ss;
                if(len == 0 || s == 0) return "EMPTY";

                ss << queue[first];
                if(first < (first+len)%s) {
                    for(int i=first+1; i<(first+len); ++i) ss << " -> " << queue[i];
                } else {
                    for(int i=first+1; i<s; ++i) ss << " -> " << queue[i];
                    for(int i=0; i<(first+len)%s; ++i) ss << " -> " << queue[i];
                }

                return ss.str();        
            }
    };
}

#endif // CIRCULAR_QUEUE_H