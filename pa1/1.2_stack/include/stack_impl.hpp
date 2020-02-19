// ##########################################
// 
//   Author  -   Collin Thornton
//   Alg     -   Stack SOURCE
//   Date    -   2-18-20
//
// ##########################################   


#include "stack.hpp"
#include <sstream>

template<class T>
Stack<T>::Stack(int size) {
    stack = new T[size];
    this->size = size;
}
template<class T>
Stack<T>::~Stack() {
    delete stack;
}
template<class T>
int Stack<T>::push(T key) {
    if(++pos >= size) throw std::invalid_argument("OVERFLOW OF STACK");

    stack[pos] = key;
    return 1;   
}
template<class T>
T Stack<T>::pop() {
    if(pos < 0) throw std::invalid_argument("UNDERFLOW OF STACK");
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