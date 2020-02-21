// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 1
//   Alg     -   Parenthesis Check
//   Due     -   2-21-2020
//
// ##########################################  

#include <iostream>
#include <fstream>
#include <string>

#include "../include/stack.hpp"

using namespace std;

const string HEADER = R"(
// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Class   -   CS 3353
//   Assgn   -   PA 1
//   Alg     -   Parenthesis Check
//   Due     -   2-21-2020
//
// ##########################################  
)";

int main(int argc, char** argv) {
    cout << HEADER << endl << endl << endl;

    if(argc > 1) cout << "There are no command line arguments" << endl;

    string fname, input;
    cout << "Please specify the name of the file containing operations" << endl;
    cout << "Filename: ";
    cin >> fname;
    cout << endl << endl;

    //fname = "../test/test1.txt"; 
    ifstream file(fname);
    if(!file.is_open()) throw invalid_argument("FILE NOT FOUND");

    Stack<char> parenthesis = Stack<char>(10, true);
    Stack<char> brackets    = Stack<char>(10, true);
    Stack<char> braces      = Stack<char>(10, true);

    getline(file, input);

    cout << "Input: " << input << endl << endl;

    int paren_err_cnt = 0, brack_err_cnt = 0, brace_err_cnt = 0;

    for(int i=0; i < input.length(); ++i) {
        char c = input.at(i), result = '_';
        
        switch(c) {
            case '(':
                parenthesis.push(c);
                break;
            case ')':
                try {
                result = parenthesis.pop();
                } catch(invalid_argument E) {
                    ++paren_err_cnt;
                }
                break;
            case '[':
                brackets.push(c);
                break;
            case ']':
                try {
                result = brackets.pop();
                } catch(invalid_argument E) {
                    ++brack_err_cnt;
                }
                break;
            case '{':
                braces.push(c);
                break;
            case '}':
                try {
                result = braces.pop();
                } catch(invalid_argument E) {
                    ++brace_err_cnt;
                }
                break;                                
            default:
                cout << "CHARACTER: '" << c << "' UNRECOGNIZED" << endl;
                exit(0);
        }
    }

    if(paren_err_cnt > 0 || brack_err_cnt > 0 || brace_err_cnt > 0) {
        cout << "String Incorrect, there are:" << endl;

        if(paren_err_cnt > 0) cout << "\t\t" << paren_err_cnt << " unclosed right parentheses" << endl;
        if(brack_err_cnt > 0) cout << "\t\t" << brack_err_cnt << " unclosed right brackets" << endl;
        if(brace_err_cnt > 0) cout << "\t\t" << brace_err_cnt << " unclosed right braces" << endl;

        cout << endl;
    }

    if(parenthesis.getSize() > 0 || brackets.getSize() > 0 || braces.getSize() > 0) {
        cout << "String Incorrect, there are:" << endl;

        if(parenthesis.getSize() > 0)   cout << "\t\t" << parenthesis.getSize() << " unclosed left parentheses" << endl;
        if(brackets.getSize() > 0)      cout << "\t\t" << brackets.getSize()    << " unclosed left brackets" << endl;
        if(braces.getSize() > 0)        cout << "\t\t" << braces.getSize()      << " unclosed left brackes" << endl;
    }

    if(paren_err_cnt + brack_err_cnt + brace_err_cnt > 0) return 0;
    if(parenthesis.getSize() + brackets.getSize() + braces.getSize() > 0) return 0;
    
    cout << "String Correct." << endl;
    return 0;
}