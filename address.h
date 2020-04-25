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
    Address(string st, string city, string region, string zip, string type);
    void setAll(string st, string city, string region, string zip, string type);
    void setStreet(string st);
    void setCity(string city);
    void setRegion(string region);
    void setZip(string zip);
    void setType(string type);
    void read(istream& in);
    void print( ostream& out = cout ) const;
    void write(ostream& out) const;
    ~Address();
};


#endif