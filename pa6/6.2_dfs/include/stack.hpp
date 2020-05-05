// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Stack Source
//   Date    -   4-14-20
// 
//  class Stack<T>
//      Stack(bool dynamic = true, int length = 10)
//      int push(T key)
//      T pop()
//      int size()
//      bool isEmpty()
//      T* arr()
//      std::string toString()
//
//  *Notes*
//   -T must implement the insertion operator (<<). If not base class, you must \
//      overload the operator in the class defition.
//
// ##########################################   

#ifndef STACK_H
#define STACK_H

#include <sstream>
#include "constants.hpp"

namespace DataStructures {
    template<class T>
    class Stack{
        private:
            void resize(int length) {
                T* new_stack = new T[length];
                
                for(int i=0; i<=pos; ++i) {
                    new_stack[i] = stack[i];
                }
                this->length = length;

                delete[] stack;
                stack = new_stack;
                new_stack = NULL;

                return;
            }
            T* stack;
            int pos=-1, length;
            bool dynamic;
        public:
            Stack(bool dynamic = true, int length = 10) {
                stack = new T[length];
                this->length = length;
                this->pos = -1;
                this->dynamic = dynamic;
            }            
            ~Stack() {
                delete[] stack;
                stack = NULL;
            }

            int push(T key) {
                if(++pos >= length/2 && dynamic) resize(length*2);
                else if(pos >= length) return OVERFLOW;

                stack[pos] = key;
                return 0;   
            }            
            T pop() {
                if(pos < 0) throw std::invalid_argument("UNDERFLOW OF STACK");
                if(dynamic && pos < length/4) resize(length/2);
                return stack[pos--];
            }

            int size() {
                return pos+1;
            }
            bool isEmpty() {
                return (pos < 0);
            }

            T* arr() {
                T* out = new T[pos+1];

                for(int i=0; i<pos+1; ++i) {
                    out[i] = stack[i];
                }
                return out;
            }

            std::string toString() {
                std::ostringstream ss;

                if(pos == -1) return "EMPTY";

                ss << stack[0];
                for(int i=1; i<=pos; ++i) ss << " -> " << stack[i];

                return ss.str();
            }
    };
}

#endif // STACK_H