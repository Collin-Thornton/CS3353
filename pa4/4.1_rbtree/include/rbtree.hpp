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
#define DOUBLEBLACK 12

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2

#define DUPLICATE -1
#define NOTFOUND -2

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

        RBTree(int traversal = INORDER, bool allow_duplicates = false); 
        ~RBTree();                                                      

        bool srch(int key);                                             

        int insert(int key, T* data = nullptr);                         
        int remove(int key, T* output = nullptr);                       

        int size();                                                     
        bool isEmpty();                                                 
        std::string toString(int trav = -2);                            

    private:
        Node *root;

        bool checkDoubleRed(Node* node);                                

        void fixDoubleRed(Node* node);                                  
        void restructure(Node* node);                                   
        void recolor(Node* node);                                       

        void fixDoubleBlack(Node* node);                                
        
        void deleteTree(Node* node);                                    
        void makeExternal(Node* node);                                  

        void inorder(std::ostringstream &ss, Node* node);               
        void preorder(std::ostringstream &ss, Node* node);              
        void postorder(std::ostringstream &ss, Node* node);             
        Node* getSibling(Node* node);                                   
        

        bool allow_duplicates = false;
        int l, traversal;

};


#endif // RB_TREE