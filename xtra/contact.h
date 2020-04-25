#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;


class Contact{

friend ostream& operator<<( ostream& out, const Contact& c );
friend istream& operator>>( istream& in, Contact& c );

public: 
    enum CType{PHONE, EMAIL, NOTE, NONE};
    enum SType{HOME, WORK, MOBILE, URL, BDAY, SNONE};
    Contact();
    Contact(CType type, SType sub, string entry);
    void setEntry(string entry);
    bool match(string query);
    void print();

private:
    /** */
    CType ctype;
    /** */
    SType subtype;
    /** */
    string entry; 

};



#endif