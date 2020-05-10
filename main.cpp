#include "main.h"
#include <functional>

const int TESTS = 10;

bool runTests(int);

int main(int argc, const char * argv[]){
    People ppl;
    ppl.read("tests/test.fcc", false);
    cout << ppl.size() << endl;
    ppl.print();

    // int passed = 0, failed = 0, taken = TESTS;
	// string fails = "";
	
	// if(argc == 1){
	// 	for(int i = 0; i < TESTS; i++){
	// 		if(runTests(i)){
	// 			fails += " " + to_string(i);
	// 			failed++;
	// 		}
	// 		else{
	// 			passed++;
	// 		}
	// 	}
	// }
	// else{
	// 	taken = 0;
	// 	// if(!strncmp(argv[1], "-e", 2)){
	// 	// 	for(int i = stoi(argv[2]); i < TESTS; i++){
	// 	// 		if(runTests(i)){
	// 	// 			fails += " " + to_string(i);
	// 	// 		}
	// 	// 	}
	// 	// }
	// 	// else{
	// 		for(int i = 1; i < argc; i++){
	// 			if(runTests(stoi(argv[i]))){
	// 				fails += " " + to_string(i);
	// 				failed++;
	// 			}
	// 			else{
	// 				passed++;
	// 			}
	// 			taken++;
	// 	 	}
	// 	// }
	// }
	// cout << "======== TEST SUMMARY =========" << endl;
	// cout << "  Tests: " << taken << endl;
	// cout << "  Passed: " << passed << endl;
	// cout << "  Failed: " << failed << endl;
	// cout << "  Percent: " << (double)passed/(double)taken << endl;
	// cout << "\n  Fails: " << fails << endl;
	// cout << "===============================" << endl;


    return 0;
}





bool runTests(int test){
    switch(test){
        case 0:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // Constructor and Destructor
        case 1:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                if(ppl.size() != 4){
                    cout << "FAIL - sz=" << ppl.size() << endl;
                    fail = true;
                }
                ppl.print();
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // Read, size and print
        case 2:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                ppl.write(cout);
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // read and write(cout)
        case 3:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                ppl.write("tests/test.out", true);
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // read and write(text)
        case 4:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                ppl.write("tests/test.fcc");
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // read and write(fcc)
        case 5:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                ppl.write("tests/test.fcc", false);
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            try{
                People p2;
                p2.read("tests/test.fcc", false);
                p2.print();
                if(p2.size() != 5){
                    cout << "FAIL - sz: " << to_string(p2.size()) << endl;
                    fail = true;
                }
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }

            return fail;
            break;
        } // read, write(fcc), and read(fcc)
        case 6:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl, p2;
                ppl.read("tests/test.in", true);
                ppl.write("tests/test.out", true);
                p2.read("tests/test.out", true);
                if(ppl.size() != p2.size()){
                    cout << "FAIL - sz: " << to_string(p2.size()) << " vs. " << to_string(ppl.size()) << endl;
                    fail = true;
                }
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // read, write(text), and read(text)
        case 7:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl;
                ppl.read("tests/test.fcc");
                Person* arr = ppl.toArray();
                for(int i =0; i < 4; i++){
                    arr[i].write();
                }
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // toArray
        case 8:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                Person p;
                fstream in("tests/test2.in");
                p.read(in);
                cout << p << endl;

                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // Person read
        case 9:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People p;
                fstream in("tests/test.in");
                p.read(in);
                People p2(p);
                p.print();
                cout << "PASS" << endl;
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // Copy Constructor
        case 10:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People p;
                p.read("tests/test.in", true);
                p.write_index("tests/index.txt");
                Person me = *(p.find("Sachin Meier,", "tests/index.txt"));
                cout << me << endl;
            }
            catch(exception &e){
                cout << "FAIL - error: " << e.what() << endl;
                fail = true;
            }
            return fail;
            break;
        } // find
        case 100:{
            cout << "-----Test " << test << "-----" << endl;
            bool fail = false;
            try{
                People ppl;
                ppl.read("tests/test.in", true);
                Person p;
                fstream in("tests/test2.in");
                p.read(in);
                p.write(cout);
                in.close();
                cout << "Adding..." << endl;
                //ppl.add(&p);
                if(ppl.size() != 4){
                    cout << "FAIL - sz: " << to_string(ppl.size()) << endl;
                    fail = true;
                }
                else{
                    cout << "PASS - sz" << endl;
                }
                ppl.print();
            }
            catch(...){
                cout << "FAIL - error" << endl;
                fail = true;
            }
            return fail;
            break;
        } // add
    }
}