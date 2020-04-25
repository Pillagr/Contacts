/*
 * datetime.cpp
 * Copyright (c) 2019 Mark Maloof.  All Rights Reserved.  See LICENSE.
 */

#include "datetime.h"

/** 
 * The Default Constructor
 * sets each int data point to zero. 
 */
DateTime::DateTime() {
    this->mm = 0;
    this->dd = 0;
    this->yy = 0;
    this->h = 0;
    this->m = 0;
}
/**
 * Explicit Constructor. Sets DateTime with specifed data points.
 * @param mm the specified month of this DateTime
 * @param dd the specified day of this DateTime
 * @param yy the specified year of this DateTime
 * @param h the specified hour of this DateTime
 * @param m the specified minute of this DateTime
 */
DateTime::DateTime( int mm, int dd, int yy, int h, int m ) {
    setDate(mm, dd, yy);
    setTime(h, m);
}
/**
 * operator== returns a true if the two DateTime objects are identical
 * @param dt the other DateTime object to be compared
 * @return bool, if each data member of this object is equal to dt's
 */
bool DateTime::operator==( const DateTime &dt ) const {
    if(this->mm == dt.mm && this->dd == dt.dd &&
        this->yy == dt.yy && this->h == dt.h &&
        this->m == dt.m) return true;
    else return false;

}
/** 
 * operator!= return's the opposite of operator==
 * @param dt the other DateTime object to be compared
 * @return bool, if each data member of this object is equal to dt's
 */
bool DateTime::operator!=( const DateTime &dt ) const {
    return !(*this == dt); //UNSURE
}
/**
 * operator< returns bool of if this < dt. 
 * @param dt the other DateTime object to be compared
 * @return bool, if dt is a DateTime later than this object
 */
bool DateTime::operator<( const DateTime &dt ) const {
    bool lt = false;
    if(this->yy < dt.yy) lt = true;
    else if (this->yy > dt.yy) lt = false;
    else if (this->mm < dt.mm) lt = true;
    else if (this->mm > dt.mm) lt = false;
    else if (this->dd < dt.dd) lt = true;
    else if (this->dd > dt.dd) lt = false;
    else if (this->h > dt.h) lt = false;
    else if (this->m < dt.m) lt = true;
    else if (this->m > dt.m) lt = false;
    return lt;
    
}
/**
 * operator> returns bool of if this > dt. 
 * @param dt the other DateTime object to be compared
 * @return bool, if dt is a DateTime earlier than this object
 */
bool DateTime::operator>( const DateTime &dt ) const {
    bool gt = false;
    if(this->yy < dt.yy) gt = false;
    else if (this->yy > dt.yy) gt = true;
    else if (this->mm < dt.mm) gt = false;
    else if (this->mm > dt.mm) gt = true;
    else if (this->dd < dt.dd) gt = false;
    else if (this->dd > dt.dd) gt = true;
    else if (this->h < dt.h) gt = false;
    else if (this->h > dt.h) gt = true;
    else if (this->m < dt.m) gt = false;
    else if (this->m > dt.m) gt = true;
    return gt;
}
/** 
 * print prints the info from this class to the specified output stream
 * @param out the specified output stream
 */
void DateTime::print( ostream& out) const {
    out << setw(2) << setfill('0') << mm << "/" << setw(2) << dd 
        << "/" << setw(2) << yy << " " << setw(2) << h << ":" << setw(2) 
        << m;
}
/** 
 * setDate sets the month, date, and year of this DateTime object
 * to the specified month, date, and year after checking if month 
 * is in range{1,12} and date is in the proper range depending on
 * the month, and year is greater than 0. 
 * @param mm the specified month of this DateTime
 * @param dd the specified day of this DateTime
 * @param yy the specified year of this DateTime
 * @throws invalid_argument if month, date, or year is out of range
 */
void DateTime::setDate( int mm, int dd, int yy ) {
    if (mm < 1 || mm > 12) {
        throw invalid_argument("DateTime::setDate invalid month");
    }
    if (dd < 0 || (mm==2 && dd > 28) || 
        ( ((mm < 8 && mm%2==1) || (mm >7 && mm%2==0) ) && dd > 31) || 
        ( ((mm < 7 && mm%2==0) || (mm > 8 && mm%2==1)) && dd > 30 ) ) {
        throw invalid_argument("DateTime::setDate invalid day");
    }
    if (yy < 0){
        throw invalid_argument("DateTime::setDate invalid year");
    }
    this->mm = mm;
    this->dd = dd;
    this->yy = yy;
}
/**
 * setTime sets the hour and minute of this DateTime object
 * to the specified hour and minute after checking that the
 * hour is between 0 and 23 and the minute is between 0 and 
 * 59. 
 * @param h the specified hour of this DateTime
 * @param m the specified minute of this DateTime
 * @throws invalid_argument if hour or minute is out of range
 */
void DateTime::setTime( int h, int m ) {
    if (h < 0 || h > 23) {
        throw invalid_argument("DateTime::setDate invalid hour");
    }
    if (m < 0 || m > 59) {
        throw invalid_argument("DateTime::setDate invalid minute");
    }
    this->h = h;
    this->m = m;
}
/**
 * converts the DateTime to and unsigned long of Unix Time.
 * Unused and not error-checked. Consider Unimplemented.
 * @return DateTime as unix time.
 */
unsigned long DateTime::toLong() const {
    
    unsigned long time;
    time = 60*(m + 60*(h + 24*(dd + 365*(yy))));
    return time; 
    
}
/**
 * operator<< passes the specified DateTime to the specified
 * output stream in human readable form: mm/dd/yy hh:mm
 * @param out the specified output stream
 * @param dt the DateTime to be output
 * @return the input stream
 */
ostream& operator<<( ostream& out, const DateTime& dt ){
    out << setw(2) << setfill('0') << dt.mm << "/" 
    << setw(2) << dt.dd << "/" << setw(2) << dt.yy << " " 
    << setw(2) << dt.h << ":" << setw(2) << dt.m;
    return out;
}
/**
 * operator>> reads in a DateTime from the specified input
 * stream into a specified DateTime object. Throws error
 * if the syntax is incorrectt
 * @param in the specified input stream
 * @param dt the specified DateTime object
 * @throws invalid_argument if synatx of DateTime is wrong.
 * @return input stream
 */
istream& operator>>( istream& in, DateTime& dt ) {
    char x;
    int mm;
    int dd;
    int yy;
    int h;
    int m;
    in >> mm >> x;
    if (x != '/') throw invalid_argument("DateTime::operator>> format error"); 
    in >> dd >> x;
    if (x != '/') throw invalid_argument("DateTime::operator>> format error"); 
    in >> yy >> h >> x;
    if (x != ':') throw invalid_argument("DateTime::operator>> format error"); 
    in >> m;
    //in.get();
    dt.setDate(mm, dd, yy);
    dt.setTime(h, m);
    return in;
}