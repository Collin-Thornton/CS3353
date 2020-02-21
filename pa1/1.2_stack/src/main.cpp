// ##########################################
// 
//   Author  -   Collin Thornton
//   Class   -   CS 3353
//   Assgn   -   PA 1
//   Alg     -   Stack
//   Due     -   2-21-2020
//
// ##########################################  

#include <iostream>
#include <fstream>
#include <string>

#include "../include/stack.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
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

    int size = stoi(line, nullptr);
    Stack<int> stack = Stack<int>(size);

    cout << "Stack Size:\t" << size << endl << endl;

    while(getline(file, line, ' ')) {
        string old_stack = stack.toString();

        int result;
        if(line == "pop") result = stack.pop();
        else {
            int delim = line.find('.');
            if(delim == line.npos) throw invalid_argument("OPERATION NOT RECOGNIZED");
            int key = stoi(line.substr(0, delim));
            string opp = line.substr(delim+1);
            if(opp != "push") throw invalid_argument("OPERATION NOT RECOGNIZED");

            result = stack.push(key);
        }

        cout << "Operation:\t" << line << endl;
        cout << "Old Stack:\t" << old_stack << endl;
        cout << "New Stack:\t" << stack.toString() << endl << endl;
    }
}