// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 5
//   Alg     -   Bucket Sort
//   Due     -   4-15-2020
//
// ##########################################  

#include <iostream>
#include <fstream>
#include <string>

#include "../include/bucket_sort.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 5
//   Alg     -   Bucket Sort
//   Due     -   4-15-2020
//
// ##########################################  
)";

int main(int argc, char** argv) {
    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

    string fname, lrange, urange;
    cout << "Enter Filename: ";
    cin >> fname;
    cout << "Enter Left Range: ";
    cin >> lrange;
    cout << "Enter Right Range: ";
    cin >> urange;

//    fname = "../test/test1.txt";
    cout << endl << endl << endl;

    int l, r;
    try {
        l = stoi(lrange);
        r = stoi(urange);
    } catch(exception e) {
        cout << "Error converting ranges to int. Be sure an integer was entered." << endl;
        cout << "Exiting." << endl;
        exit(1);
    }
    
    ifstream file(fname);
    if(!file.is_open()) throw invalid_argument("FILE NOT FOUND");

    string line;

    DataStructures::Stack<int> inputStack = DataStructures::Stack<int>(true);

    int i = 0;
    int m = 999999999, M = -999999999;
    while(getline(file, line)) {
        int num;
        try {
            num = stoi(line);
        } catch(exception e) {
            cout << "Error converting line to int. Be sure an integer was entered." << endl;
            cout << "Line: " << line;
            exit(1);
        }

        M = max(M, num);
        m = min(m, num);
        ++i;

        inputStack.push(num);
    }
    if(l > r) { cout << "Left range must be less than or equal to right range.\nExiting" << endl; exit(0); }
    if(l > i) { cout << "Left range is greater than input size.\nExiting." << endl; exit(0); }
    if(r > i) { cout << "Right range is greater than input size.\nExiting." << endl; exit(0); }

    DataStructures::BucketSort<int> bucketSort(i, m, M, false);

    cout << "Sorted numbers in the selected range are: " << endl;
    int* arr = inputStack.arr();
    bucketSort.sort(arr);

    for(int i=l-1; i<r; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    delete[] arr;


    cout << endl << "FINISHED" << endl;
    return 0;
}