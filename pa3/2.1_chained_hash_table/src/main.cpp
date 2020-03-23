// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 3
//   Alg     -   Hash Table w/ Chaining
//   Due     -   3-23-2020
//
// ##########################################  


#include <iostream>
#include <fstream>

#include "../include/hash_table.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 3
//   Alg     -   Hash Table w/ Chaining
//   Due     -   3-23-2020
//
// ##########################################  
)";

using namespace std;

int main(int argc, char** argv) {
    HashTable table(13);

    table.insert(2);
    cout << table.toString();
}