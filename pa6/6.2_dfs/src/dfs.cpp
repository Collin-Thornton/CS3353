// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 6
//   Alg     -   DFS/Topological Sort/SCC
//   Due     -   5-6-2020
//
// ##########################################  

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream> 

#include "../include/circular_queue.hpp"
#include "../include/stack.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 6
//   Alg     -   DFS/Topological Sort/SCC
//   Due     -   5-6-2020
//
// ##########################################  
)";

int** getMatrix(string& fname, int& size);
void dfs(int** mat, bool** discovery, bool** back, bool* explored, int node, int size, int& time, int* d, int* f);
void dfs_visit(int** mat, bool** discovery, bool** back, bool* explored, int node, int size, int& time, int* d, int* f);
void scc_visit(int** mat, bool** discovery, bool** back, bool* explored, int node, int size, int* d, int* f);

DataStructures::Stack<string> topological;
DataStructures::Stack<string> scc_str;
DataStructures::Stack<int> scc;


int main(int argc, char** argv) {
    
    int **mat, **transpose;
    bool **discovery;
    bool **back;
    int source = 2;   
    int size = 1, time = 0;

    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

    string fname, node;
    cout << "Enter Filename:\t";
    cin >> fname;

//    fname = "../test/test1.txt";

    mat = getMatrix(fname, size);

    transpose = new int*[size];
    for(int i=0; i<size; ++i) {
        transpose[i] = new int[size];
        for(int j=0; j<size; ++j) transpose[i][j] = mat[j][i];
    }
    discovery = new bool*[size];
    for(int i=0; i<size; ++i) {
        discovery[i] = new bool[size];
        for(int j=0; j<size; ++j) discovery[i][j] = 0;
    }
    back = new bool*[size];
    for(int i=0; i<size; ++i) {
        back[i] = new bool[size];
        for(int j=0; j<size; ++j) back[i][j] = 0;
    }

    bool explored[size] = {};
    int d[size] = {};
    int f[size] = {};

    cout << "INPUT ADJ MATRIX" << endl << endl;
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            cout << left;
            cout << setw(3) << mat[i][j];
        }
        cout << endl;
    }

    cout << endl << endl << endl;

    dfs(mat, discovery, back, explored, source, size, time, d, f);


    cout << "DFS TREE" << endl << endl;
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            if(i != j) 
            cout << discovery[i][j] << "  ";
            else {
                ostringstream ss;
                ss << '(' << d[i] << '/' << f[i] << ')';
                cout << left << setw(7);
                cout << ss.str();
            }
        }
        cout << endl;
    } cout << endl << endl << endl;


    cout << "TOPOLOGICAL SORT" << endl << endl;
    while(!topological.isEmpty()) cout << topological.pop() << ", ";
    cout << endl << endl << endl << endl;

    for(int i=0; i<size; ++i) {
        explored[i] = false;
        for(int j=0; j<size; ++j) {
            discovery[i][j] = false;
            back[i][j] = false;
        }
    }

    while(!scc.isEmpty()) {
        int node = scc.pop();
        if(!explored[node]) {
            scc_str.push("), ");    
            scc_visit(transpose, discovery, back, explored, node, size, d, f);
            scc_str.push("(");
        }
    }

    cout << "SCC SORT" << endl << endl;
    while(!scc_str.isEmpty()) cout << scc_str.pop();
    cout << endl << endl << endl;

    for(int i=0; i<size; ++i) {
        delete[] mat[i];
        delete[] back[i];
        delete[] discovery[i];
        delete[] transpose[i];
    }
    delete[] mat;
    delete[] back;
    delete[] discovery;
    delete[] transpose;
}



void dfs(int** mat, bool** discovery, bool** back, bool* explored, int node, int size, int& time, int* d, int* f) {
    explored[node] = true;
    dfs_visit(mat, discovery, back, explored, node, size, time, d, f);

    for(int i=0; i<size; ++i) {
        if(!explored[i]) dfs_visit(mat, discovery, back, explored, i, size, time, d, f);
    }

}
void dfs_visit(int** mat, bool** discovery, bool** back, bool* explored, int node, int size, int& time, int* d, int* f) {
    explored[node] = true;    
    d[node] = ++time;
    for(int i=0; i<size; ++i) {
        if(mat[node][i] == 1) {
            if(!discovery[node][i] && !back[node][i]) {
                if(!explored[i]) {
                    discovery[node][i] = 1;
                    dfs_visit(mat, discovery, back, explored, i, size, time, d, f);
                }
                else {
                    back[node][i] = 1;
                }
            }
        }
    }
    f[node] = ++time;
    
    ostringstream ss;
    ss << '(' << d[node] << '/' << f[node] << ')';
    topological.push(ss.str());
    scc.push(node);
}
void scc_visit(int** mat, bool** discovery, bool** back, bool* explored, int node, int size, int* d, int* f) {
    explored[node] = true;    
    for(int i=0; i<size; ++i) {
        if(mat[node][i] == 1) {
            if(!discovery[node][i] && !back[node][i]) {
                if(!explored[i]) {
                    discovery[node][i] = 1;
                    scc_visit(mat, discovery, back, explored, i, size, d, f);
                }
                else {
                    back[node][i] = 1;
                }
            }
        }
    }
    
    ostringstream ss;
    ss << '(' << d[node] << '/' << f[node] << ')';
    scc_str.push(ss.str());
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