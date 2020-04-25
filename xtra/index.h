#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Index {

  public:
    Index();
    Index(string filename);
    void read(string filename);
    void read(istream& in);
    void write(string filename);
    void write(ostream& out);


  private:
    vector<string> index;
};



#endif