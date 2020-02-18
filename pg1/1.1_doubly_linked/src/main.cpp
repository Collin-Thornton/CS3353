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

int input_opp(string fname, DoublyLinked<string>* opps);

int main(int argc, char** argv) {
    if(argc > 1) {
        cout << "There are no required command line arguments" << endl;
    }

    string fname;
    cout << "Please specify the name of the file containing operations" << endl;
//    cin >> fname;

    fname = "../test/test1.txt";

    DoublyLinked<string> *opps = new DoublyLinked<string>;
    if(!input_opp(fname, opps)) {
        throw invalid_argument("File not found");
    }

    cout << endl << "Number of operations: " << opps->getSize() << endl;
    cout << "Operations: " << opps->toString();
    cout << endl << endl << endl;

    DoublyLinked<int>* data = new DoublyLinked<int>;
    int dataSize = 0;

    for(int i=0; i<opps->getSize(); ++i) {
        string opp = opps->get(i);
        int after = -1;

        short delim = opp.find('.');
        short sub_delim = opp.find('_');
        int num = stoi(opp.substr(0,delim), nullptr);
        
        if(sub_delim == opp.npos) opp = opp.substr(delim+1);
        else {
            after = stoi(opp.substr(sub_delim+1), nullptr);
            opp = opp.substr(delim+1, sub_delim);
        }

        string orig = data->toString();
        cout << "Operation:\t" << num << '.' << opp;

        int result;

        if(opp == "in") {
            if(after == -1) result = data->insert(num);
            else result = data->insert(num, after);
            cout << endl;
        }
        else if(opp == "del") {
            result = data->del(num);
            cout << endl;
        }
        else if(opp == "sch") {
            if(data->srch(num) == 1) cout << "\tFOUND" << endl;
            else cout <<  "\tNOT FOUND" << endl;
        }
        else throw invalid_argument("Operation not recognized");

        if(result == -2) cout << "DUPLICATE KEY" << endl;

        cout << "List before:\t" << orig << endl;    
        cout << "List after:\t" << data->toString() << endl << endl;
    }

    return 0;
}



int input_opp(string fname, DoublyLinked<string>* opps) {
    fname = "../test/test1.txt";

    ifstream file(fname);
    file >> noskipws;

    if(!file.is_open()) {
        cout << "Unable to locate file" << endl;
        cout << "Exiting..." << endl;
        return -1;
    }

    string line;

    file.clear();    
    file.seekg(0);
    while(getline(file, line, ' ')) opps->append(line);

    file.close();    
    
    return 1;
}