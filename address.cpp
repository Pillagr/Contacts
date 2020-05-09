#include "address.h"

/** 
 * Default Constructor.
 */
Address::Address(){
    
}
/**
 * 
 */
Address::Address(string st, string city, string region, string zip, string type){
    this->street = st;
    this->city = city;
    this->region = region;
    this->zip = zip;
}
/**
 * sets all data points for this Address
 */
/** */
void Address::setAll(string st, string city, string region, string zip, string type){
    this->street = st;
    this->city = city;
    this->region = region;
    this->zip = zip;
}
/**
 * sets Street for this Address
 */
/** */
void Address::setStreet(string st){
    this->street = st;
}
/**
 * sets City for this Address
 */
void Address::setCity(string city){
    this->city = city;
}
/** */
void Address::setRegion(string region){
    this->region = region;
}
/**
 * sets Zip Code for this Address
 */
void Address::setZip(string zip){
    this->zip = zip;
}
/**
 * sets Type for this Address
 */
void Address::setType(string type){
    this->type = type;
}
void Address::read(istream& in){
    string street, city, region, zip;
    char ch;
    in >> ch;
    getline(in, street, '\"');
    getline(in, city, '\"');
    getline(in, city, '\"');
    getline(in, region, '\"');
    getline(in, region, '\"');
    getline(in, zip, '\"');
    getline(in, zip, '\"');

    setStreet(street);
    setCity(city);
    setRegion(region);
    setZip(zip);
}
/**
 * 
 */
void Address::print(ostream& out) const{
    out << "st: " << this->street << "\nct: " << this->city 
    << "\nrg: " << this->region << "\nzip:" << this->zip << endl;
}
void Address::write(ostream& out) const{
    out << "\"" << this->street << "\"\t\"" << this->city << "\"\t\"" << this->region 
        << "\"\t\"" << this->zip << "\"";
}
/** */
ostream& operator<<( ostream& out, const Address& addr ){
    addr.write(out);
    return out;
}
/** */
istream& operator>>( istream& in, Address& addr ){
    addr.read(in);
    return in;
}

// Address::~Address(){

// }
