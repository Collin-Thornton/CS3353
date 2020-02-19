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
    CircularQueue<int> queue = CircularQueue<int>(8);

    for(int i=0; i<5; ++i) {
        cout << "Operation:\t" << "1.ins" << endl;
        cout << "First:\t" << queue.first << " Len:\t" << queue.len << " Size:\t" << queue.size << endl;
        cout << "Original Queue:\t" << queue.toString() << endl;
        queue.insert(2);
        cout << "First:\t" << queue.first << " Len:\t" << queue.len << " Size:\t" << queue.size << endl;
        cout << "New Queue:\t" << queue.toString() << endl << endl;
    }
        for(int i=0; i<5; ++i) {
        cout << "Operation:\t" << "pull" << endl;
        cout << "First:\t" << queue.first << " Len:\t" << queue.len << " Size:\t" << queue.size << endl;
        cout << "Original Queue:\t" << queue.toString() << endl;
        queue.pull();
        cout << "First:\t" << queue.first << " Len:\t" << queue.len << " Size:\t" << queue.size << endl;
        cout << "New Queue:\t" << queue.toString() << endl << endl;
    }
}