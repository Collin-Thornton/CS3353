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
        void resize(int size);

        T* stack;
        int pos=-1, size=0;
        bool dynamic = false;
    public:
        Stack(int size, bool dynamic = false);
        ~Stack();

        int push(T key);
        T pop();
        int getSize();

        std::string toString();
};

#include "stack_impl.hpp"
#endif // STACK_H