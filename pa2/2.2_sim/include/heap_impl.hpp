// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Heap SOURCE
//   Date    -   3-06-20
//
// ##########################################  

#include <sstream>
#include <iostream>
#include <cmath>

#include "heap.hpp"

template<class T>
Heap<T>::Heap(bool minimal, bool allowDuplicates) {
    heap = new Node[1];
    this->minimal = minimal;
    this->allowDuplicates = allowDuplicates;
}
template<class T>
Heap<T>::~Heap() { 
    delete heap;
}
template<class T>
void Heap<T>::expandExternalLayer(){
    if(length < (int)pow(2, layers+1)-1) return;
    
    Node* tmp = new Node[(int)pow(2,layers+2)-1];
    for(int i=0; i<length; ++i) {
        tmp[i] = heap[i];
    }
    delete heap;
    heap = tmp;
    ++layers;
}
template<class T>
void Heap<T>::removeExternalLayer() {
    if(length > (int)pow(2, layers)-1) return;

    std::cout << "Layer removed" << std::endl;
    Node* tmp = new Node[(int)pow(2,layers)-1];
    for(int i=0; i<length; ++i) {
        tmp[i] = heap[i];
    }
    delete heap;
    heap = tmp;
    --layers;
}
template<class T>
int Heap<T>::size() {
    return length;
}
template<class T>
bool Heap<T>::isEmpty() {
    return (length == 0);
}
template<class T>
int Heap<T>::insertNode(T key) {
    expandExternalLayer();

    heap[length].pos = length;
    heap[length].key = key;
    heap[length].isExternal = false;

    upHeap();
    ++length;

    return 1;
}
template<class T>
T Heap<T>::pop() {
    if(size() == 0) throw std::invalid_argument("HEAP UNDERFLOW");

    removeExternalLayer();
    T key = heap[0].key;
    heap[0].key = heap[length-1].key;

    heap[length-1].key = 0;
    heap[length-1].isExternal = true;

    downHeap();
    --length;

    return key;
}
template<class T>
void Heap<T>::upHeap() {
    if(isEmpty()) return;
    
    int index = length;
    if(minimal) {
        while((heap[index].key < heap[(index-1)/2].key) && index != 0) {
            T tmp = heap[(index-1)/2].key;
            heap[(index-1)/2].key = heap[index].key;
            heap[index].key = tmp;
            index = (index-1)/2;
        }
        return;
    }
    
    while((heap[index].key > heap[(index-1)/2].key) && index != 0) {
        T tmp = heap[(index-1)/2].key;
        heap[(index-1)/2].key = heap[index].key;
        heap[index].key = tmp;
        index = (index-1)/2;
    }
    return;
}
template<class T>
void Heap<T>::downHeap() {
    if(isEmpty() || size() == 1) return;
    
    int index = 0;
    if(heap[1].isExternal && heap[2].isExternal) return;

    if(minimal) {
        while((heap[index].key > heap[index*2+1].key || heap[index].key > heap[index*2+2].key) && !heap[index*2+1].isExternal) {
            if(heap[index*2+2].isExternal || heap[index*2+1].key < heap[index*2+2].key) {
                T tmp = heap[index].key;
                heap[index].key = heap[index*2+1].key;
                heap[index*2+1].key = tmp;
                index = index*2+1;
            }
            else {
                T tmp = heap[index].key;
                heap[index].key = heap[index*2+2].key;
                heap[index*2+2].key = tmp;
                index = index*2+2;
            }
        }
        return;
    }
    while((heap[index].key < heap[index*2+1].key || heap[index].key < heap[index*2+2].key) && !heap[index*2+1].isExternal) {
        if(heap[index*2+2].isExternal || heap[index*2+1].key > heap[index*2+2].key) {
            T tmp = heap[index].key;
            heap[index].key = heap[index*2+1].key;
            heap[index*2+1].key = tmp;
            index = index*2+1;
        }
        else {
            T tmp = heap[index].key;
            heap[index].key = heap[index*2+2].key;
            heap[index*2+2].key = tmp;
            index = index*2+2;
        }
    }
    return;
}
template<class T>
std::string Heap<T>::toString(short traversal) {
    std::ostringstream ss;

    if(isEmpty()) return "EMPTY";
    
    switch(traversal) {
        case PREORDER:
            preorder(&ss, 0);
            break;
        case POSTORDER:
            postorder(&ss, 0);
            break;
        case INORDER:
            inorder(&ss, 0);
            break;
        case BREADTH:
            breadth(&ss, 0);
             break;
        default:
            throw std::invalid_argument("TRAVERSAL METHOD UNKOWN. VALID RANGE [0->4]");
            return "--- INVALID TRAVERSAL ---";
    }
    return ss.str();
}
template<class T>
void Heap<T>::preorder(std::ostringstream *ss, short index) {
    if(index >= length) return; 
    
    *ss << heap[index].key << ' ';
    preorder(ss, index*2+1);
    preorder(ss, index*2+2);
}
template<class T>
void Heap<T>::postorder(std::ostringstream *ss, short index) {
    if(index >= length) return; 

    postorder(ss, index*2+1);
    postorder(ss, index*2+2);
    *ss << heap[index].key << ' ';
}
template<class T>
void Heap<T>::inorder(std::ostringstream *ss, short index) {
    if(index >= length) return;

    inorder(ss, index*2+1);
    *ss << heap[index].key << ' ';
    inorder(ss, index*2+2);
}
template<class T>
void Heap<T>::breadth(std::ostringstream *ss, short index) {
    for(int i=index; i<size(); ++i) {
        *ss << heap[i].key << ' ';
    }
}
