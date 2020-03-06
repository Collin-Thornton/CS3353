// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 2
//   Alg     -   Job Sim
//   Due     -   3-06-2020
//
// ##########################################  

#include <iostream>
#include <fstream>

#include "../include/heap.hpp"
#include "../include/job.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 2
//   Alg     -   Job Sim
//   Due     -   3-06-2020
//
// ##########################################  
)";

using namespace std;

int main(int argc, char** argv) {
    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

    Job job1 = Job(1, 2, 3, 4);
    Job job2 = Job(2, 4, 3, 4);
    Job job3 = Job(3, 2, 3, 4);

    cout << job1.toString() << endl;
    cout << job2.toString() << endl;
    cout << job3.toString() << endl;

    job1.work();
    cout << "JOB1 WORKED" << endl;
    cout << job1.toString() << endl;

    cout << "Job1 == job2:\t" << (job1 >= job2) << endl;
    return 0;
}