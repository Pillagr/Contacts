#include "phone.h"

ostream& operator<<( ostream& out, const Phone& p ){
    p.write(out);
    return out;
}
istream& operator>>( istream& in, Phone& p ){
    p.read(in);
    return in;
}

Phone::Phone(){
    this->a = 0;
    this->b = 0;
    this->c = 0;
    this->d = 0;
}
Phone::Phone(int a, int b, int c, int d){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    
}
void Phone::setPhone(int a, int b, int c, int d){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}
void Phone::setType(string type){
    this->type = type;
}
void Phone::read(istream& in){
    int a,b,c,d;
    string type;
    char ch;
    in >> ch;
    if(!(ch == '(')) throw invalid_argument("Phone::read bad phone type.");
    getline(in, type, ')');
    in >> a >> ch;
    if(!(ch == '-')) throw invalid_argument("Phone::read bad phone number.");
    in >> b >> ch;
    if(!(ch == '-')) throw invalid_argument("Phone::read bad phone number.");
    in >> c >> ch;
    if(!(ch == '-')) throw invalid_argument("Phone::read bad phone number.");
    in >> d; 
    setPhone(a,b,c,d);
    setType(type);

}
void Phone::print(ostream& out) const{
    out << type << ": +" << a << '-' << b << '-' << c << '-' << d;
}
void Phone::write(ostream& out) const{
    out << '(' << type << ')' << a << '-' << b << '-' << c << '-' << d;
}

Phone::~Phone(){
    
}