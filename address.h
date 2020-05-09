#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <iostream>

using namespace std;

class Address {


friend ostream& operator<<( ostream& out, const Address& e );
friend istream& operator>>( istream& in, Address& e );

private:
    /** street and street number for this address */
    string street;
    /** city for this address */
    string city;
    /** region for this address  */
    string region;
    /** zip for this address */
    string zip;
    /** subtype for this address */
    string type;
public:
    Address();
    Address(string, string, string, string, string);
    void setAll(string, string, string, string, string);
    void setStreet(string);
    void setCity(string);
    void setRegion(string);
    void setZip(string);
    void setType(string);
    void read(istream&);
    void print( ostream& = cout ) const;
    void write(ostream&) const;
    //~Address();
};


#endif