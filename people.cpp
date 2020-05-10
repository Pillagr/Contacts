#include "people.h"
/**
 * Default Constructor.
 */ 
People::People(){

}

/**
 * 
 */
People::People(const People& other){
    *this = other;
}

Person* People::at(unsigned position){
    return people.at(position);
}


/**
 * 
 */ 
void People::read(istream& in){ //help fix
    Person* person = new Person;
    person->read(in);
    while(in){
        people.push_back(person);
        person = new Person;
        person->read(in);
    }
}
/**
 * 
 */ 
void People::read(string filename, bool text){
    
    fstream fp(filename.c_str());
    if(text){
        read(fp);
    }
    else{
        Person* person = new Person;
        while(fp.read((char *)person, sizeof(Person))){   
            this->people.push_back(person);
            person = new Person;
        }
        delete person;
    }
    fp.close();
}
/**
 * 
 */
Person* People::toArray(){
    unsigned sz = people.size();
    Person* array = new Person[sz];
    int count = 0;
    for(vector<Person *>::iterator iter= people.begin(); iter != people.end(); count++, iter++){
        array[count] = *(*iter);
    }
    return array;
} 
/**
 * 
 */ 
void People::write(ostream& out){
    for(vector<Person *>::iterator it = people.begin(); it != people.end(); ++it){
        out << (*(*it));
    }
}
/**
 * 
 */ 
void People::write(string filename, bool text){
    fstream fp(filename.c_str());
    if(text){
        write(fp);
    }
    else{
        Person* person;
        for(vector<Person *>::iterator it = people.begin(); it != people.end(); ++it){
            person = *it;
            fp.write((char *)person, sizeof(Person));
        }  
    }
    fp.close();
}
void People::add(Person* person){
    people.push_back(person);
}

/**
 * 
 */ 
void People::print(ostream& out){
    for(vector<Person *>::iterator it = people.begin(); it != people.end(); ++it){
        out << (*(*it)) << endl;
    }
}

/**
 * 
 */ 
unsigned People::size() const{
    return people.size();
}
/**
 * 
 */ 
bool People::empty() const{
    return (people.size() == 0);
}
/**
 * 
 */ 
void People::write_index(string filename){
    fstream fp(filename.c_str());
    write_index(fp);
    fp.close();
}
/**
 * 
 */ 
void People::write_index(ostream& out){
    for(vector<Person *>::iterator it = people.begin(); it != people.end(); ++it){
        out << (*(*it)).getLName() << ", ";
        out << (*(*it)).getFName();
    }
}
/**
 * 
 */ 
void People::clear(){
    if(!empty()){
        unsigned sz = people.size();
        // cout << "SZ:" << sz << endl;
        for(unsigned i = 0; i < sz; i++){
            // cout << "i:" << i << endl;
            delete people[i];
        }
    }
}


/**
 * 
 */ 
Person* People::find(string query, string indexname=""){
    string fname, lname;

    /*
    use try block, check if filename has idx
    */

    fstream fp(indexname);
    getline(fp, lname, ',');
    getline(fp, fname, '\n');
    unsigned count = 0,
                sz = size();
    while(fp && count > sz){
        if(query == fname + " " + lname){
            return people.at(count);
        }
        ++count;
        getline(fp, lname, ',');
        getline(fp, fname, '\n');
    }
    throw logic_error("No Such Person found.");
}

const People& People::operator=(const People& other){
    if(!empty()){
        clear();
    }
    people.resize(other.size());
    for(unsigned i = 0; i < other.size(); i++){
        people.push_back( new Person(*other.people.at(i)));
    }
    return *this;
}

People::~People(){
    clear();
}