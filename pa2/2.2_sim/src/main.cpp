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

void getJob(string line, string &name, int &p, int &a, int &l);

int main(int argc, char** argv) {
    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

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

    cout << queuedHeap.toString();
    long t = 0;

    cout << endl << endl << 't';
    while(!queuedHeap.isEmpty()) {
      
        cout << "Time Slice #" << t;

        bool first = true;
        while(queuedHeap.look()->getArrival() == t) {
            Job nextJob = queuedHeap.pop();
            Job *jobExec = new Job (nextJob.getId(), nextJob.getPriority(), nextJob.getArrival(), nextJob.getLength(), false);
            if(first) cout << "\t - " << nextJob.getId() << " arrived" << endl;
            else      cout << "\t\t - " << nextJob.getId() << " arrived" << endl;
            first = false;
            execHeap.insertNode(jobExec);
            if(queuedHeap.isEmpty()) break;
        }
        string str = queuedHeap.toString();

        first = true;
        if(!queuedHeap.isEmpty()) {
            for(t=t;t<queuedHeap.look()->getArrival();++t) {
                if(!first) cout << "Time Slice #" << t << "\t" << " - ";
                else cout << "\t\t - ";
                first = false;
                cout << "Executing " << execHeap.look()->toString();
                execHeap.look()->work();
                if(execHeap.look()->isFinished()) {
                    Job finished = execHeap.pop();
                }
            }
        }
        else {
            while(!execHeap.isEmpty()) {
                cout << "Time Slice #" << t << "\t" << " - ";
                cout << "Executing " << execHeap.look()->toString();

                execHeap.look()->work();
                if(execHeap.look()->isFinished()) {
                    Job finished = execHeap.pop();             
                }
                ++t;
            }
        }
    }

    cout << endl << "FINISHED" << endl;
    return 0;
}



void getJob(string line, string &name, int &p, int &a, int &l) {
    string priority, arrivalTime, length;
    
    int spacePos = line.find(' ', 0);
    int prevPos = 0;

    name = line.substr(0, spacePos);
    prevPos = spacePos;

    spacePos = line.find(' ', prevPos+1);
    priority = line.substr(prevPos, spacePos-prevPos);
    prevPos = spacePos;

    spacePos = line.find(' ', prevPos+1);
    arrivalTime = line.substr(prevPos, spacePos-prevPos);
    prevPos = spacePos;

    length = line.substr(prevPos, line.length()-prevPos);

    try {
        p = stoi(priority);

    } catch(...) {
        cout << "Priority on Job ID: " << name << " (" << priority << ") not an integer" << endl;
        exit(1);
    }
    
    try {
        a = stoi(arrivalTime);
    } catch(...) {
        cout << "Arrival Time on Job ID: " << name << " not an integer" << endl;
        exit(1);
    }

    try {
        l = stoi(length);
    } catch(...) {
        cout << "Length on Job ID: " << name << " not an integer" << endl;
        exit(1);
    }

    p = max(p, -10);
    p = min(p, 10);
    l = max(l, 0);
    l = min(l, 100);
    a = max(a, 0);

    return;
}