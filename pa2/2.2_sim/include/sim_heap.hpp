// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Heap INCLUDE
//   Date    -   3-06-20
//
// ##########################################  

#ifndef HEAP
#define HEAP

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2
#define BREADTH 3

template<class T>
class Heap {
    private:
        struct Node {
            T *key;

            int pos = -1;
            bool isExternal = true;
        }; Node* heap;

        bool minimal, allowDuplicates;

        void expandExternalLayer();
        void removeExternalLayer();

        void upHeap();
        void downHeap();
        
        void preorder(std::ostringstream *ss, short index);
        void inorder(std::ostringstream *ss, short index);
        void postorder(std::ostringstream *ss, short index);
        void breadth(std::ostringstream *ss, short index);

    public:
        Heap(bool minimal = false, bool allowDuplicates = true);
        ~Heap();
        int length=0, layers=0;


        int size();
        bool isEmpty();
        std::string toString(short traversal = BREADTH);

        int insertNode(T *key);
        T pop();
        T* look();
};

#include "sim_heap_impl.hpp"

#endif