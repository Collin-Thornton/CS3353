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

void getJob(string line, string &name, int &p, int &a, int &l);

int main(int argc, char** argv) {
    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

    RBTree<int> tree = RBTree<int>(INORDER);

    tree.insert(56);
    tree.insert(23);
    tree.insert(45);
    tree.insert(7);
    tree.insert(5);

    cout << tree.toString() << endl;
/*    
    for(int i=0; i<10; ++i) {
        string before = tree.toString();
        tree.insert(i);

        cout << "Operation:\t" << i << ".in" << endl;
        cout << "Tree before:\t" << before << endl;
        cout << "Tree after:\t" << tree.toString() << endl << endl;
    }

*/


















/*
    string fname;
    cout << "Please specify the name of the file containing operations" << endl;
    cout << "Filename: ";
    cin >> fname;

//    fname = "pa2/2.2_sim/test/test1.txt";
    
    ifstream file(fname);
    if(!file.is_open()) throw invalid_argument("FILE NOT FOUND");

    string line;
    Heap<Job> queuedHeap = Heap<Job>(true, true);
    Heap<Job> execHeap = Heap<Job>(true, true);

    int i = 0;
    while(getline(file, line, '\n')) {
        string name;
        int priority, arrivalTime, length;
        getJob(line, name, priority, arrivalTime, length);
        Job *jobCompArriv = new Job(name, priority, arrivalTime, length, true);

        queuedHeap.insertNode(jobCompArriv);
    }
*/
    

    cout << endl << "FINISHED" << endl;
    return 0;
}