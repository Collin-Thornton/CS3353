// ##########################################
// 
//   Author  -   Collin Thornton
//   Class   -   CS 3353
//   Assgn   -   PA 1
//   Alg     -   Circular Queue
//   Due     -   2-21-2020
//
// ##########################################  

#include <iostream>
#include <fstream>
#include <string>

#include "../include/circular_queue.hpp"

using namespace std;

int main(int argc, char** argv) {
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
    CircularQueue<int> queue = CircularQueue<int>(size);

    cout << "Queue Size:\t" << size << endl << endl;

    while(getline(file, line, ' ')) {
        string old_queue = queue.toString();

        int result;
        if(line == "del") result = queue.pull();
        else {
            int delim = line.find('.');
            if(delim == line.npos) throw invalid_argument("OPERATION NOT RECOGNIZED");
            int key = stoi(line.substr(0, delim));
            string opp = line.substr(delim+1);
            if(opp != "in") throw invalid_argument("OPERATION NOT RECOGNIZED");

            result = queue.insert(key);
        }

        cout << "Operation:\t" << line << endl;
        cout << "Old Queue:\t" << old_queue << endl;
        cout << "New Queue:\t" << queue.toString() << endl << endl;
    }
}