#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "person.h"

using namespace std;

/** */
class People {

  friend class Index;

  public:
    People();
    People(const People&);

    const People& operator=(const People&);

    Person* at(unsigned);

    void read(istream&);
    void read(string, bool=false);
    void write(ostream&);
    void write(string, bool=false);
    void add(Person*);
    void write_index(string);
    void write_index(ostream& = cout);
    Person* toArray();
    void print(ostream& = cout);
    unsigned size() const;
    bool empty() const;
    void clear();
    Person* find(string, string);
    ~People();


  private:
    /** List of all person objects*/
    vector<Person *> people;
};


#endif