#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include "phone.h"
#include "address.h"
#include "datetime.h"

class Person{

friend ostream& operator<<( ostream& out, const Person& p );
friend istream& operator>>( istream& in, Person& p );

public:
    Person();
    Person(string fname, string lname, Address* address, 
            Phone* phone, string email, string note="");

    void read(istream&);
    void write(ostream& = cout) const;

    void setPhone(Phone*);
    void setPhone(int, int, int, int);
    void setAddress(Address*);
    void setEmail(string);
    void setFName(string);
    void setLName(string);
    void setNote(string);

    Phone& getPhone();
    Address& getAddress();
    string getEmail();
    string getFName();
    string getLName();
    string getNote();
    ~Person();



private:
    /** The Address object of this Person */
    Address address;
    /** The Phone ojbect of this Person */
    Phone phone;
    /** The Email object of this Person */
    string email;
    /** The first name of this Person */
    string fname;
    /** The last name of this Person */
    string lname;
    /** The note of this Person */
    string note;
    /** The DateTime last modified */ 
    DateTime modified;
    
};



#endif