#include "main.h"

const int TESTS = 8;

void runTests(int);

int main(int argc, const char * argv[]){
    if(argc == 1){
		for(int i = 0; i < TESTS; i++){
			runTests(i);
		}
	}
	else{
		// if(!(strncmp(argv[1], "-e", 2))){
		// 	for(int i = stoi(argv[2]); i < TESTS; i++){
		// 		runTests(i);
		// 	}
		// }
		// else{
		    for(int i = 1; i < argc; i++){
		    	runTests(stoi(argv[i]));
		    }
		// }
	}

    return 0;
}

void runTests(int test){
    switch(test){
        case 0:{
            cout << "-----Test " << test << "-----" << endl;
            try{
                People ppl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
            }
            break;
        } // Constructor and Destructor
        case 1:{
            cout << "-----Test " << test << "-----" << endl;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                if(ppl.size() != 4){
                    cout << "FAIL - sz=" << ppl.size() << endl;
                }
                ppl.print();
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
            }
            break;
        } // Read, size and print
        case 2:{
            cout << "-----Test " << test << "-----" << endl;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                ppl.write(cout);
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
            }
            break;
        } // read and write(cout)
        case 3:{
            cout << "-----Test " << test << "-----" << endl;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                ppl.write("tests/test.out", true);
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
            }
            break;
        } // read and write(text)
        case 4:{
            cout << "-----Test " << test << "-----" << endl;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                ppl.write("tests/test.fcc");
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
            }
            break;
        } // read and write(fcc)
        case 5:{
            cout << "-----Test " << test << "-----" << endl;
            try{
                People ppl, p2;
                ppl.read("tests/test.in", true);
                ppl.write("tests/test.fcc", false);
                p2.read("tests/test.fcc", false);
                if(ppl.size() != p2.size()){
                    cout << "FAIL - sz: " << p2.size() << " vs. " << ppl.size() << endl;
                }
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
            }
            break;
        } // read, write(fcc), and read(fcc)
        case 6:{
            cout << "-----Test " << test << "-----" << endl;
            try{
                People ppl, p2;
                ppl.read("tests/test.in", true);
                ppl.write("tests/test.out", true);
                p2.read("tests/test.out", true);
                if(ppl.size() != p2.size()){
                    cout << "FAIL - sz: " << p2.size() << " vs. " << ppl.size() << endl;
                }
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
            }
            break;
        } // read, write(text), and read(text)
        case 7:{
            cout << "-----Test " << test << "-----" << endl;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                Person p;
                fstream in("tests/test2.in");
                p.read(in);
                in.close();
                cout << "Adding..." << endl;
                ppl.add(&p);
                if(ppl.size() != 5){
                    cout << "FAIL - sz: " << ppl.size() << endl;
                }
                else{
                    cout << "PASS - sz" << endl;
                }
                ppl.print();
            }
            catch(...){
                cout << "FAIL - error" << endl;
            }
            break;
        } // add
    }
}