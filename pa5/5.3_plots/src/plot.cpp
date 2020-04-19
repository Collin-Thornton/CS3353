// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 5
//   Alg     -   Sort Plot
//   Due     -   4-15-2020
//
// ##########################################  

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>

#include "../include/bucket_sort.hpp"
#include "../include/merge_sort.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 5
//   Alg     -   Sort Plot
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

    //fname = "../test/plot.txt";
    cout << endl << endl << endl;

    ifstream file(fname);
    if(!file.is_open()) throw invalid_argument("FILE NOT FOUND");

    string line;

    long mergeData[100][2];
    long bucketData[100][3];

    for(int k=0; k<100; ++k) {             
        DataStructures::Stack<int> inputStack = DataStructures::Stack<int>(true);

        int i = 0;
        int m = 999999999, M = -999999999;
        while(getline(file, line) && i < 1000*(k+1)) {
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

        DataStructures::BucketSort<int> bucketSort(i, m, M, false);
        DataStructures::MergeSort<int> mergeSort(i, false);

        clock_t bucketTime = 0, mergeTime = 0;
        

        for(int j=0; j<20; ++j) {
            if(j % 3 == 0) cout << '.' << flush;
            int* arr = inputStack.arr();
            int* arrr = inputStack.arr();


            clock_t timeStart = clock();
            bucketSort.sort(arr);
            bucketTime += clock() - timeStart;

            timeStart = clock();
            mergeSort.sort(arrr);
            mergeTime += clock() - timeStart;
            delete[] arr;
            delete[] arrr;
            arr = NULL;
            arrr = NULL;
        } cout << endl;


        system("clear");

        cout << HEADER << endl;
        cout << "Num Inputs:\t" << i << endl;
        cout << "BUCKET SORT:\t" << (float)(bucketTime)/CLOCKS_PER_SEC*1e9/20 << " nanoseconds." << endl;
        cout << "MERGE SORT:\t" << (float)(mergeTime)/CLOCKS_PER_SEC*1e9/20 << " nanoseconds." << endl << endl;
        if(k<99) cout << "Sorting" << flush;

        bucketData[k][0] = i;
        bucketData[k][1] = M-m+1;
        bucketData[k][2] = bucketTime;
        mergeData[k][0] = i;
        mergeData[k][1] = mergeTime;

        file.clear();
        file.seekg(0, ios::beg);
    }

    cout << endl;
    cout << "FINISHED SORTING" << endl;
    cout << "Calculating asymptotic time constant..." << endl;

    ofstream bucket_dump("bucket_dump.csv"), merge_dump("merge_dump.csv"), dual_dump("dual_dump.csv");

    bucket_dump << "num inputs,range,time,constant" << endl;
    merge_dump  << "num inputs,time,constant" << endl;
    dual_dump   << "num inputs,range,merge time,merge constant,bucket time,bucket constant" << endl;
    float n1 = 0, n2 = 0;
    for(int i=0; i<100; ++i) {
        float n11 = (float)bucketData[i][2] / ((float)bucketData[i][0]+(float)bucketData[i][1]);
        float n22 = (float)mergeData[i][1]  / ((float)mergeData[i][0]*(float)log2(mergeData[i][0]));        
        bucket_dump << bucketData[i][0] << ',' << bucketData[i][1]  << ',' << bucketData[i][2]  << ',' << n11 << endl;
        merge_dump  << mergeData[i][0]  << ',' << mergeData[i][1]   << ',' << n22 << endl;
        dual_dump   << bucketData[i][0] <<',' << bucketData[i][1]   << ',' << mergeData[i][1]   << ',' <<  n22 << ',' << bucketData[i][2] << ',' << n11 << endl;

        n1 += n11;
        n2 += n22;
    } n2 /= 100; n1/=100;

    bucket_dump << "AVERAGE CONSTANT: " << n1 << endl;
    merge_dump  << "AVERAGE CONSTANT: " << n2 << endl;
    dual_dump   << "MERGE AVERAGE CONSTANT: " << n2 << endl;
    dual_dump   << "BUCKET AVERAGE CONSTANT: " << n1 << endl;

    file.close();
    bucket_dump.close();
    merge_dump.close();

    cout << "Time constant for bucketSort:\t" << n1 << endl;
    cout << "Time constant for mergeSort:\t" << n2 << endl;

    cout << endl;
    cout << endl << "FINISHED" << endl;
    return 0;
}