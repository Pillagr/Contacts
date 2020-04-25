#include "person.h"

/**
 * Default Constructor.
 */ 
Person::Person(){
    //nothing here
}
/**
 * Explicit Constructor.
 * @param fname the first name of this Person.
 * @param lname the last name of this Person.
 * @param address the Address of this Person.
 * @param phone the Phone object of this Person.
 * @param email the email of this Person.
 * @param note the note of this Person.
 */ 
Person::Person(string fname, string lname, Address* address, 
                Phone* phone, string email, string note){
    setFName(fname);
    setLName(lname);
    setAddress(address);
    setPhone(phone);
    setEmail(email);
    setNote(note);
}
/**
 * 
 */ 
void Person::read(istream& in){
    string fname, lname, email, note;
    getline(in, lname, ',');
    if(in.good()){
        in.get();
        getline(in, fname, '.');
        in >> this->modified;
        this->address.read(in);
        in.get();
        this->phone.read(in);
        in.get();
        getline(in, email, '\n');
        getline(in, note, '|');

        //in.get();
        setFName(fname);
        setLName(lname);
        setEmail(email);
        setNote(note);
    }

}
/**
 * 
 */ 
void Person::write(ostream& out) const{
    out << this->lname << ", " << fname << ". " << this->modified
        << '\n' << this->address << '\n' << this->phone
        << '\n' << this->email << '\n' << this->note << "|";
}
/**
 * 
 */ 
void Person::setPhone(Phone* phone){
    //this->phone = phone;
    throw invalid_argument("Person::setPhone not implemented!");
}
/**
 * 
 */ 
void Person::setPhone(int a, int b, int c, int d){
    this->phone.setPhone(a,b,c,d); //maybe delete
}
/**
 * 
 */ 
void Person::setAddress(Address * address){
    //this->address = address;
    throw invalid_argument("Person::setAddress not implemented!");
}
/**
 * 
 */ 
void Person::setEmail(string email){
    this->email = email;
}
/**
 * 
 */ 
void Person::setFName(string fname){
    this->fname = fname;
}
/**
 * 
 */ 
void Person::setLName(string lname){
    this->lname = lname;
}
/**
 * 
 */ 
void Person::setNote(string note){
    this->note = note;
}

/**
 *
 */ 
Phone& Person::getPhone(){
    return this->phone;
}
/**
 * 
 */ 
Address& Person::getAddress(){
    return this->address;
}
/**
 * 
 */ 
string Person::getEmail(){
    return this->email;
}
/**
 * 
 */ 
string Person::getFName(){
    return this->fname;
}
/**
 * 
 */ 
string Person::getLName(){
    return this->lname;
}
/**
 * 
 */ 
string Person::getNote(){
    return this->note;
}
/**
 * 
 */ 
ostream& operator<<( ostream& out, const Person& p ){
    p.write(out);
    return out;
}
/**
 * 
 */ 
istream& operator>>( istream& in, Person& p ){
    p.read(in);
    return in;
}

Person::~Person(){
    
}