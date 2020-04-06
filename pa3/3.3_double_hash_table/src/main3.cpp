<<<<<<< HEAD:pa3/3.2_linear_hash_table/src/main.cpp
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 3
//   Alg     -   Hash Table w/ Linear Probing
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
//   Alg     -   Hash Table w/ Linear Probing
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
    //cin >> fname;

    fname = "../test/test1.txt";
    ifstream file(fname);
    if(!file.is_open()) throw invalid_argument("FILE NOT FOUND");

    string line;
    getline(file, line, ' ');

    short size;
	try {
		size =stoi(line);
	} catch(exception e) {
		cout << "Please inter an integer for size." << endl << "Exiting." << endl;
		exit(0);
	}

	HashTable table = HashTable(size);

	while(getline(file, line, ' ')) {
	        string old_table = table.toString();

        	int result;

		string k = line.substr(0, line.find_first_of('.'));
		int key;
		try {
			key = stoi(k);
		} catch (exception e) {
			cout << "Please enter an integer for key." << endl << "Exiting." << endl;
			exit(0);
		}

		string cmd = line.substr(line.find_first_of('.')+1);
		if(cmd.find("del") != cmd.npos) result = table.remove(key);
		else if(cmd.find("in") != cmd.npos) result = table.insert(key);
		else {
			cout << "Command: " << line << " unrecognized." << endl << "Exiting." << endl;
			exit(0);
		}
	
      	 	cout << "Operation:\t"  << line << endl;
       		cout << "Old Table:\n"   << old_table << endl;
        	cout << "New Table:\n"   << table.toString() << endl << endl;
	}
}
=======
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 3
//   Alg     -   Hash Table w/ Double Hashing
//   Due     -   3-23-2020
//
// ##########################################  


#include <iostream>
#include <fstream>

#include "../include/double_hash_table.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 3
//   Alg     -   Hash Table w/ Double Hashing
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
	try {
		size =stoi(line);
	} catch(exception e) {
		cout << "Please inter an integer for size." << endl << "Exiting." << endl;
		exit(0);
	}

    getline(file, line, ' ');
    short q;
	try {
		q =stoi(line);
	} catch(exception e) {
		cout << "Please inter an integer for q." << endl << "Exiting." << endl;
		exit(0);
	}	

	HashTable table = HashTable(size, q);

	while(getline(file, line, ' ') && table.size() < size) {
		string old_table = table.toString();

		int result;

		string k = line.substr(0, line.find_first_of('.'));
		int key;
		try {
			key = stoi(k);
		} catch (exception e) {
			cout << "Please enter an integer for key." << endl << "Exiting." << endl;
			exit(0);
		}

		string cmd = line.substr(line.find_first_of('.')+1);
		
		bool search = false;
		if(cmd.find("del") != cmd.npos) 		result = table.remove(key);
		else if(cmd.find("in") != cmd.npos) 	result = table.insert(key);
		else if(cmd.find("sch") != cmd.npos) 	{ result = table.sch(key); search = true; }
		else {
			cout << "Command: " << line << " unrecognized." << endl << "Exiting." << endl;
			exit(0);
		}
	
      	 	cout << "Operation:\t"  << line << endl;

			if(search == true && result == -3) cout << "NOT FOUND" << endl;
			else if(search == true && result != -3) cout << "FOUND" << endl;

       		cout << "Old Table:\n"   << old_table << endl;
        	cout << "New Table:\n"   << table.toString() << endl << endl;
	}

	if(table.size() >= size) cout << "TABLE FULL" << endl;
	cout << "FINISHED" << endl;	
}
>>>>>>> d3c6e459396879f16d82e4f01d29d727a09d9850:pa3/3.3_double_hash_table/src/main3.cpp
