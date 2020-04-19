// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 4
//   Alg     -   Red Black Tree
//   Due     -   4-08-2020
//
// ##########################################  

#include <iostream>
#include <fstream>
#include <string>

#include "../include/rbtree.hpp"
#include "../include/rbtree_impl.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 4
//   Alg     -   Red Black Tree
//   Due     -   4-08-2020
//
// ##########################################  
)";

using namespace std;

int main(int argc, char** argv) {
    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

    string fname;
    cout << "Please specify the name of the file containing operations" << endl;
    cout << "Filename: ";
    cin >> fname;

//    fname = "../test/test1.txt";
    cout << endl << endl << endl;
    
    ifstream file(fname);
    if(!file.is_open()) throw invalid_argument("FILE NOT FOUND");

    string line;
    int traversal;

    getline(file, line, ' ');
    if(line == "in") traversal = INORDER;
    else if(line == "post") traversal = POSTORDER;
    else if(line == "pre") traversal = PREORDER;
    else {
        cout << "Please enter a valid traversal method as the first command." << endl;
        cout << "Valid traversal methods: 'in', 'pre', 'post'" << endl;
        cout << "Exiting." << endl;
        exit(0);
    }

    RBTree<int> tree = RBTree<int>(traversal);

    int i = 0;
    while(getline(file, line, ' ')) {
        string before = tree.toString();

        string k, cmd;
        int key;
        
        int delim = line.find('.');
        if(delim == line.npos) {
            cout << "Command unrecognized: " << line << endl;
            cout << "Exiting." << endl;
            exit(1);
        }
        k = line.substr(0, delim);
        cmd = line.substr(delim+1);

        try {
            key = stoi(k);
        } catch(exception e) {
            cout << "Error converting key to int on command: " << line << endl;
            cout << "Exiting." << endl;
            exit(1);
        }

        int result;
        if(cmd == "in") result = tree.insert(key);
        else if(cmd == "del") result = tree.remove(key);
        else if(cmd == "srch") result = tree.srch(key);
        else {
            cout << "Subcommand (" << cmd << ") not recognized: " << line << endl;
            cout << "Exiting." << endl;
            exit(1);
        }

        if(result == DUPLICATE) cout << "Insert: (" << key << ") is duplicate. Skipping." << endl;
        else if(result == NOTFOUND) cout << "Entry: (" << key << ") not found. Skipping." << endl;

        cout << "Operation:\t"      << line << endl;
        cout << "Tree Before:\t"    << before << endl;
        cout << "Tree After:\t"     << tree.toString() << endl << endl;
    }

    cout << endl << "FINISHED" << endl;
    return 0;
}