// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 1
//   Alg     -   Circular Queue
//   Due     -   2-21-2020
//
// ##########################################  

#include <iostream>
#include <fstream>
#include <string>

#include "../include/heap.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 1
//   Alg     -   Parenthesis Check
//   Due     -   2-21-2020
//
// ##########################################  
)";

int main(int argc, char** argv) {
    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

    string fname;
    cout << "Please specify the name of the file containing operations" << endl;
    cout << "Filename: ";
    cin >> fname;

    //fname = "../test/test1.txt";
    ifstream file(fname);
    if(!file.is_open()) throw invalid_argument("FILE NOT FOUND");

    string line;
    getline(file, line, ' ');

    short traversal;
    if(line == "pre")       traversal = PREORDER;
    else if(line == "post") traversal = POSTORDER;
    else if(line == "in")   traversal = INORDER;
    else throw invalid_argument("TRAVERSAL METHOD UNRECOGNIZED");

    cout << endl << "Traversal:\t" << line << endl << endl;

    Heap<int> heap = Heap<int>(false, false);

    while(getline(file, line, ' ')) {
        string old_heap = heap.toString(traversal);

        int result;
        if(line == "del") result = heap.pop();
        else {
            int delim = line.find('.');
            if(delim == line.npos) throw invalid_argument("OPERATION NOT RECOGNIZED");
            int key = stoi(line.substr(0, delim));
            string opp = line.substr(delim+1);
            if(opp != "in") throw invalid_argument("OPERATION NOT RECOGNIZED");

            result = heap.insertNode(key);
        }

        cout << "Operation:\t"  << line << endl;
        cout << "Old Heap:\t"   << old_heap << endl;
        cout << "New Heap:\t"   << heap.toString(traversal) << endl << endl;
    }
}