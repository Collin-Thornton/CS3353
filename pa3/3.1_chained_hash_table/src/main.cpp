// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 3
//   Alg     -   Hash Table w/ Chaining
//   Due     -   3-23-2020
//
// ##########################################  


#include <iostream>
#include <fstream>

#include "../include/hash_table.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 3
//   Alg     -   Hash Table w/ Chaining
//   Due     -   3-23-2020
//
// ##########################################  
)";

using namespace std;

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

    short size;
	int index = line.find(' ');
	string sub = line.substr(0, index);
	try {
		size =stoi(sub);
	} catch(exception e) {
		cout << "Please inter an integer for size." << endl << "Exiting." << endl;
		exit(0);
	}

	HashTable table = HashTable(size);

	int prevIndex = index;
	while(index != line.length()) {
		string old_table = table.toString();

		int index= line.find(' ', prevIndex);
		string sub = line.substr(prevIndex, index-prevIndex);

		string k = sub.substr(0, sub.find_first_of('.'));
		int key;
		try {
			key = stoi(k);
		} catch (exception e) {
			cout << "Please enter an integer for key." << endl << "Exiting." << endl;
			exit(0);
		}

		int result;
		string cmd = sub.substr(sub.find_first_of('.'));
		if(cmd == "del") result = table.remove(key);
		else if(cmd == "in") result = table.insert(key);
		else {
			cout << "Command: " << sub << " unrecognized." << endl << "Exiting." << endl;
			exit(0);
		}

		cout << "Operation:\t"  << sub << endl;
        cout << "Old Table:\t"   << old_table << endl;
        cout << "New Heap:\t"   << table.toString() << endl << endl;

	}

}
