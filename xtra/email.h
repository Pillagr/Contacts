#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <string>

using namespace std;

class Email{
public:
    Email();
    Email(string email);
    bool check();
private:
    string email;

};

#endif