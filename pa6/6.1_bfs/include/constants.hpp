// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Constants for use in DataStructures namespace
//   Date    -   4-16-20
//
//   class ChainedHashTable<K,T>
//      ChainedHashTable<K,T>(int num_buckets)
//      int insert(K key, T value)
//      int remove(K key)
//      bool srch(K key)
//      int size()
//      std::string toString()
//
//  *NOTES*
//   -These constants are used throughout the DataStructures namespace
//
// ##########################################   


#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace DataStructures {
    const int RED           = 10;
    const int BLACK         = 11;
    const int DOUBLEBLACK   = 12;

    const int PREORDER      = 0;
    const int INORDER       = 1;
    const int POSTORDER     = 2;
    
    const int DUPLICATE     = -1;
    const int NOTFOUND      = -2;
    const int UNDERFLOW     = -3;
    const int OVERFLOW      = -4;
}


#endif // CONSTANTS_H