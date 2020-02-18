// ##########################################
// 
//   Author  -   Collin Thornton
//   Class   -   CS 3353
//   Assgn   -   PA 1
//   Alg     -   Doubly Linked List
//   Due     -   2-19-2020
//
// ##########################################   

#include <iostream>
#include <fstream>
#include <string>

#include "DoublyLinked.hpp"

using namespace std;

int input_opp(string fname, DoublyLinked<string>* opps, int* size);

int main(int argc, char** argv) {
    if(argc > 1) {
        cout << "There are no required command line arguments" << endl;
    }

    string fname;
    cout << "Please specify the name of the file containing operations" << endl;
//    cin >> fname;

    fname = "../test/test1.txt";

    DoublyLinked<string> *opps = new DoublyLinked<string>;
    int size;
    if(!input_opp(fname, opps, &size)) {
        cout << "File: " << fname << " not found." << endl;
        cout << "Exiting..." << endl;
        exit(-1);
    }

    string args;
    opps->toString(&args);

    cout << endl << "Number of operations: " << size << endl;
    cout << "Operations: ";
    cout << args << endl << endl;


    DoublyLinked<int> data;
    int past_delim = args.find('\n', 1);

    for(int i=0; i<size; ++i) {
        int beg = args.find('\n', past_delim+1);
        string opp = args.substr(past_delim, beg);
        past_delim = beg;

        string sub_opp = "none";

        short delim = 0;//opp.find('.');
        short sub_delim = 0;//opp.find('_');

        cout << opp << endl;        
        //cout << delim << endl;
        //cout << opp.substr(0,delim) << endl;
        //int num = stoi(opp.substr(0,delim), nullptr);

        
        //if(sub_delim == opp.npos) opp = opp.substr(delim);
        //else {
        //    sub_opp = opp.substr(sub_delim);
        //    opp = opp.substr(delim, sub_delim);
        //}

//        cout << "Number: " << num << " - Operation: " << opp << " - sub_opp: " << sub_opp << endl;        

    }

    return 0;
}



int input_opp(string fname, DoublyLinked<string>* opps, int* size) {
    fname = "../test/test1.txt";

    ifstream file(fname);
    file >> noskipws;

    if(!file.is_open()) {
        cout << "Unable to locate file" << endl;
        cout << "Exiting..." << endl;
        return -1;
    }

    char c;
    *size = 0;
    while(file >> c) {
        if(c == ' ') ++*size;
    }

    ++*size;
    string line;

    int i = 0;

    file.clear();    
    file.seekg(0);
    while(getline(file, line, ' ')) opps->append(line);

    file.close();    
    
    return 1;
}