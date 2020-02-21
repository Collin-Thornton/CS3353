// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Stack SOURCE
//   Date    -   2-18-20
//
// ##########################################   


#include "stack.hpp"
#include <sstream>

template<class T>
Stack<T>::Stack(int size, bool dynamic) {
    stack = new T[size];
    this->size = size;
    this->dynamic = dynamic;
}
template<class T>
Stack<T>::~Stack() {
    delete stack;
}
template<class T>
void Stack<T>::resize(int size) {
    T* new_stack = new T[size];
    
    for(int i=0; i<=pos; ++i) {
        new_stack[i] = stack[i];
    }
    this->size = size;

    delete stack;
    stack = new_stack;

    return;
}
template<class T>
int Stack<T>::push(T key) {
    if(++pos >= size/2 && dynamic) resize(size*2);
    else if(pos >= size) if(!dynamic) throw std::invalid_argument("OVERFLOW OF STACK");

    stack[pos] = key;
    return 1;   
}
template<class T>
T Stack<T>::pop() {
    if(pos < 0) throw std::invalid_argument("UNDERFLOW OF STACK");
    if(dynamic && pos < size/4) resize(size/2);
    return stack[pos--];
}
template<class T>
std::string Stack<T>::toString() {
    std::ostringstream ss;

    if(pos == -1) return "EMPTY";

    ss << stack[0];
    for(int i=1; i<=pos; ++i) ss << " -> " << stack[i];

    return ss.str();
}
template<class T>
int Stack<T>::getSize() {
    return pos+1;
}