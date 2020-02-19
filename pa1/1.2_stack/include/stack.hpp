// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Stack INCLUDE
//   Date    -   2-18-20
//
// ##########################################   

#ifndef STACK_H
#define STACK_H

#include <string>

template<class T>
class Stack{
    private:
        T* stack;
        int pos=-1, size=0;
    public:
        Stack(int size);
        ~Stack();
        int push(T key);
        T pop();

        std::string toString();
};

#include "stack_impl.hpp"
#endif // STACK_H