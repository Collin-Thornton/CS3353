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

    table.insert(3);

    for(int i=0; i<15; ++i) {
	    cout << "Operation: " << i << ".in\t" << endl;
	    cout << "Table before operation:" << endl;
	    cout << table.toString();
	    int result = table.insert(i);
	    if(result == -1) cout << "DUPLICATE RESULT" << endl;
	    cout << "Table after operation:" << endl;
	    cout << table.toString();
    	    cout << endl << endl;
    }
    cout << "Operation: del(13)\t" << endl;
    int result = table.remove(13);
    cout << table.toString();
}
