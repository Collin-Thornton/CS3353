// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Red Black Tree INCLUDE
//   Date    -   4-08-20
//
// ##########################################  

#ifndef RB_TREE
#define RB_TREE

#include <sstream>

#define RED 10
#define BLACK 11

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2

#define DUPLICATE -1


template <class T>
class RBTree {
    public:
        struct Node {
            int color = BLACK;
            bool isExternal = true;
            T* data = nullptr;
            int key;

            Node *parent = nullptr;
            Node *lchild = nullptr;
            Node *rchild = nullptr;
        };    

        RBTree(int traversal = INORDER, bool allow_duplicates = false); // done
        ~RBTree();                                                      // done

        bool srch(int key);                                             // done

        int insert(int key, T* data = nullptr);                         // done
        //T remove(int key);                                              // TODO

        int size();                                                     // done
        bool isEmpty();                                                 // done
        std::string toString(int trav = -2);                            // done

    private:
        Node *root;

        bool checkDoubleRed(Node* node);                                // done

        void fixDoubleRed(Node* node);                                  // done
        void restructure(Node* node);                                   // done
        void recolor(Node* node);                                       // done

        //bool checkDoubleBlack(Node* node);                              // TODO

        //void fixDoubleBlack(Node* node);                                // TODO

        void deleteTree(Node* node);                                    // done

        void inorder(std::ostringstream* ss, Node* node);               // done
        void preorder(std::ostringstream* ss, Node* node);              // done
        void postorder(std::ostringstream* ss, Node* node);             // done
        Node* getSibling(Node* node);                                   // done

        bool allow_duplicates = false;
        int l, traversal;

};


#endif // RB_TREE