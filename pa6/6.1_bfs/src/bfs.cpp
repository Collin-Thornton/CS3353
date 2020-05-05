// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 6
//   Alg     -   Breadth First Search
//   Due     -   5-6-2020
//
// ##########################################  

#include <iostream>
#include <iomanip>
#include <fstream>

#include "../include/circular_queue.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 6
//   Alg     -   Breadth First Search
//   Due     -   5-6-2020
//
// ##########################################  
)";


int** getMatrix(string &fname, int& size);

int main(int argc, char** argv) {
    
    int **mat;
    int **discovery;
    bool **cross;
    int source = 1;   
    int size;

    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

    string fname, node;
    cout << "Enter Filename:\t";
    cin >> fname;
    cout << "Enter the Source Node Location:\t ";
    cin >> node;

    try {
        source = atoi(node.c_str()) - 1;
    } catch (int e) {
        cout << "Enter an integer for the source node location" << endl;
        cout << "Exiting." << endl;
        exit(1);
    }

    mat = getMatrix(fname, size);

    discovery = new int*[size];
    for(int i=0; i<size; ++i) {
        discovery[i] = new int[size];
        for(int j=0; j<size; ++j) discovery[i][j] = 0;
    }
    cross = new bool*[size];
    for(int i=0; i<size; ++i) {
        cross[i] = new bool[size];
        for(int j=0; j<size; ++j) cross[i][j] = 0;
    }

    bool explored[size] = {};

    cout << endl << endl << endl << "INPUT ADJ MATRIX" << endl << endl;
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            cout << left << setw(2) << mat[i][j];
        }
        cout << endl;
    } cout << endl << endl;


    DataStructures::CircularQueue<int> containers[size];

    int n = 0;
    containers[n].insert(source);

    while(!containers[n].isEmpty() && n<size) {
        int* list = containers[n].arr();

        for(int i=0; i<containers[n].size(); ++i) {
            explored[list[i]] = true;

            for(int j=0; j<size; ++j) {
                if(mat[list[i]][j] == 1) {
                    if(discovery[list[i]][j] == false && cross[list[i]][j] == false) {
                        if(!explored[j]) {
                            discovery[list[i]][j] = true;
                            discovery[j][list[i]] = true;
                            explored[j] = true;
                            containers[n+1].insert(j);
                        }
                        else {
                            cross[list[i]][j] = true;
                            cross[j][list[i]] = true;
                        }
                    }
                }
            }
        }
        delete[] list;
        ++n;
    }


    cout << endl;    
    for(int i=0; i<size; ++i) {
        while(!containers[i].isEmpty()) {
            int j = containers[i].remove();
            discovery[j][j] = i;
        }
    }


    cout << "SHORTEST PATH TREE" << endl << endl;
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            cout << left << setw(2) << discovery[i][j];
        }
        cout << endl;
    } cout << endl << endl;

    for(int i=0; i<size; ++i) {
        delete[] mat[i];
        delete[] cross[i];
        delete[] discovery[i];
    }
    delete[] mat;
    delete[] cross;
    delete[] discovery;
}

int** getMatrix(string& fname, int& size) {
    ifstream file(fname);
    if(!file.is_open()) { cout << "FILE NOT FOUND.\nEXITING." << endl; exit(1); }

    string line;
    DataStructures::CircularQueue<string> inputQueue;

    size = 0;
    while(getline(file, line)) {
        inputQueue.insert(line);
        ++size;
    }

    int **mat = new int*[size];
    for(int i=0; i<size; ++i) mat[i] = new int[size];

    for(int i=0; i<size; ++i) {
        line = inputQueue.remove();
        short space = 0;
        for(int j=0; j<size; ++j) {
            int entry = 0;
            try {
                entry = atoi(line.substr(space, line.find(' ', space+1)).c_str());
                space = line.find(' ', space+1);
            }
            catch(int e) {
                cout << "ENSURE ALL MATRIX ENTRIES ARE INTS" << endl;
                cout << "EXITING" << endl;
                exit(0);
            }
            mat[i][j] = entry;
        }
    }

    return mat;
}