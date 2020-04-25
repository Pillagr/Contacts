#include "contact.h"

/**
 * Default Constructor
 */ 
Contact::Contact(){

}

/**
 * Explicit Constructor. Sets type and subtype and entry to 
 * specified type and subtype and entry
 * @param type type of this contact (Phone, Email, Address, Note, None)
 * @param sub subtype of this contact (Home, Work, Mobile, URL, BDAY, None)
 * @param entry data for the contact
 */ 
Contact::Contact(CType type, SType sub, string entry){
    this->ctype = type;
    this->subtype = sub;
    setEntry(entry);

}
/** */
void Contact::setEntry(string entry){
    if (this->ctype == PHONE){
        for(int i = 0; i < entry.length(); i++){
            if(!isdigit(entry[i])) 
                throw invalid_argument("Contact::setEntry bad Phone #");
        }
    }
    this->entry = entry;
}
bool Contact::match(string query){
    return query.find(entry);
}


/** */
void Contact::print(){
    switch(ctype){
        case PHONE:
            cout << "PHONE - ";
            break;
        case EMAIL:
            cout << "EMAIL - ";
            break;
        case NOTE:
            cout << "NOTE - ";
            break;
        case NONE:
            cout << "NONE - ";
            break;
    }
    switch(subtype){
        case HOME:
            cout << "HOME\n";
            break;
        case WORK:
            cout << "WORK\n";
            break;
        case MOBILE:
            cout << "MOBILE\n";
            break;
        case URL:
            cout << "URL\n";
            break;
        case BDAY:
            cout << "BDAY\n";
            break;
        case SNONE:
            cout << "NONE\n";
            break;
    }
    cout << this->entry << endl;

}