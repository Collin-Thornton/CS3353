// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Red Black Tree SOURCE
//   Date    -   4-08-20
//
// ##########################################  

#include "rbtree.hpp"

template<class T>
RBTree<T>::RBTree(int traversal, bool allow_duplicates) {
    root = new Node;

    this->traversal = traversal;
    this->allow_duplicates = allow_duplicates;

    l = 0;
}
template<class T>
RBTree<T>::~RBTree() {
    deleteTree(root);
}
template<class T>
void RBTree<T>::deleteTree(Node* node) {
    if(node == nullptr) return;

    deleteTree(node->lchild);
    deleteTree(node->rchild);

    delete node;
}
template<class T>
int RBTree<T>::size() {
    return l;
}
template<class T>
bool RBTree<T>::isEmpty() {
    return (l == 0);
}
template<class T>
bool RBTree<T>::srch(int key) {
    if(l == 0) return false;

    Node* tmp = root;
    if(tmp->key = key) return true;

    while(tmp->key != key && !tmp->isExternal) {
        if(key < tmp->key) tmp = tmp->lchild;
        else tmp = tmp->rchild;
    }

    if(tmp->isExternal) return false;
    else return true;
}
template<class T>
int RBTree<T>::insert(int key, T* data) {
    Node* tmp = root;
    while(!tmp->isExternal) {
        if(key < tmp->key) tmp = tmp->lchild;
        else if(key > tmp->key) tmp = tmp->rchild;
        else {
            if(!allow_duplicates) return DUPLICATE;
            tmp = tmp->lchild;
        }
    }

    if(tmp != root) tmp->color = RED;
    tmp->isExternal = false;
    tmp->key = key;
    tmp->data = data;

    tmp->lchild = new Node;
    tmp->rchild = new Node;
    tmp->lchild->parent = tmp;
    tmp->rchild->parent = tmp;

    fixDoubleRed(tmp);
    ++l;
    return 1;
}
template<class T>
bool RBTree<T>::checkDoubleRed(Node*  node) {
    if(node == root || node == nullptr) return false;
    return (node->color == RED && node->parent->color == RED);
}
template<class T>
void RBTree<T>::fixDoubleRed(Node* node) {
    Node* tmp = node;
    while(checkDoubleRed(tmp)) {
        if(getSibling(tmp)->color == BLACK) restructure(tmp);
        else recolor(tmp);
        tmp = tmp->parent;
    }
}
template<class T>
struct RBTree<T>::Node* RBTree<T>::getSibling(Node* node) {
    if(node == root) return nullptr;
    Node* tmp = node;
    tmp = tmp->parent;

    return (tmp->lchild == node) ? tmp->rchild : tmp->lchild;
}
template<class T>
void RBTree<T>::restructure(Node* node) {
    Node* parent = node->parent;
    Node* grandparent = node->parent->parent;

    if(node == parent->rchild && parent == grandparent->rchild) {
        if(grandparent == root) root = parent;
        parent->parent = grandparent->parent;
        grandparent->parent = parent;
        grandparent->rchild = parent->lchild;
        parent->lchild = grandparent;
        parent->color = BLACK;
        grandparent->color = RED;
        node->color = RED;
    }
    else if(node == parent->lchild && parent == grandparent->lchild) {
        if(grandparent == root) root = parent;
        parent->parent = grandparent->parent;
        grandparent->parent = parent;
        grandparent->lchild = parent->rchild;
        parent->rchild = grandparent;
        parent->color = BLACK;
        grandparent->color = RED;
        node->color = RED;
    }
    else if(node == parent->lchild && parent == grandparent->rchild) {
        if(grandparent == root) root = node;
        node->parent = grandparent->parent;
        parent->parent = node;
        grandparent->parent = node;
        grandparent->rchild = node->lchild;
        parent->lchild = node->rchild;
        node->lchild = grandparent;
        node->rchild = parent;
        node->color = BLACK;
        parent->color = RED;
        grandparent->color = RED;
    }
    else {
        if(grandparent == root) root = node;
        node->parent = grandparent->parent;
        parent->parent = node;
        grandparent->parent = node;
        grandparent->lchild = node->rchild;
        parent->rchild = node->lchild;
        node->lchild = parent; 
        node->rchild = grandparent;
        node->color = BLACK;
        parent->color = RED;
        grandparent->color = RED;
    }
    return;
}
template<class T>
void RBTree<T>::recolor(Node* node) {
    node->color = BLACK;
    if(node == root) return;
    getSibling(node)->color = BLACK;
    
    node->parent->color = (node->parent == root) ? BLACK : RED;
    return;
}


template<class T>
std::string RBTree<T>::toString(int trav) {
    std::ostringstream ss;

    if(isEmpty()) {
        ss << "NULL / EMPTY";
        return ss.str();
    }

    if(trav == -2) trav = traversal;
    
    switch(trav) {
        case INORDER:
            inorder(&ss, root);
            break;
        case POSTORDER:
            postorder(&ss, root);
            break;
        case PREORDER:
            preorder(&ss, root);
            break;
        default:
            throw std::invalid_argument("TRAVERSAL METHOD UNRECOGNIZED");
            break;
    }

    return ss.str();
}
template<class T>
void RBTree<T>::inorder(std::ostringstream* ss, Node* node) {
    if(node == nullptr) return;
    
    inorder(ss, node->lchild);
    if(!node->isExternal) {
        *ss << node->key;
        (node->color == BLACK) ? *ss << 'B' : *ss << 'R';
        *ss << ' ';  
    }
    inorder(ss, node->rchild);
}
template<class T>
void RBTree<T>::preorder(std::ostringstream* ss, Node* node) {
    if(node == nullptr) return;

    if(!node->isExternal) {
        *ss << node->key;
        (node->color == BLACK) ? *ss << 'B' : *ss << 'R';
        *ss << ' ';  
    }

    inorder(ss, node->lchild);
    inorder(ss, node->rchild);    
}
template<class T>
void RBTree<T>::postorder(std::ostringstream* ss, Node* node) {
    if(node == nullptr) return;
    
    inorder(ss, node->lchild);
    inorder(ss, node->rchild);    

    if(!node->isExternal) {
        *ss << node->key;
        (node->color == BLACK) ? *ss << 'B' : *ss << 'R';
        *ss << ' ';  
    }
}