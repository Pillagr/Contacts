#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <string>

using namespace std;


class Phone{

friend ostream& operator<<( ostream& out, const Phone& p );
friend istream& operator>>( istream& in, Phone& p );


public:
    Phone();
    Phone(int a, int b, int c, int d);
    void setPhone(int a, int b, int c, int d);
    void setType(string type);
    void read(istream& in);
    void print(ostream& out=cout) const;
    void write(ostream& out) const;
private:
    int a;
    int b;
    int c;
    int d;
    string type;

};

#endif