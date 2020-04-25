/*
 * datetime.h
 * Copyright (c) 2019 Mark Maloof.  All Rights Reserved.  See LICENSE.
 */

#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * A class for storing dates and times.  Dates are in the format
 * MM/DD/YY, and times are in the twelve-hour format, HH:MM [AM|PM].
 *
 * @author Mark Maloof (maloof at cs georgetown edu)
 * @author Sachin Meier
 * @version 1.1, 11/28/12
 * @version 1.2, 01/08/20
 */
class DateTime
{

  friend ostream& operator<<( ostream& out, const DateTime& dt );
  friend istream& operator>>( istream& in, DateTime& dt );

  public:
    DateTime();
    DateTime( int mm, int dd, int yy, int h, int m);
    bool operator==( const DateTime& dt ) const;
    bool operator!=( const DateTime& dt ) const;
    bool operator<( const DateTime& dt ) const;
    bool operator>( const DateTime& dt ) const;
    void print( ostream& out = cout ) const;
    void setDate( int mm, int dd, int yy );
    void setTime( int h, int m);

  private:
    /** the months 1-12*/
    int mm;
    /** the days 0-x */
    int dd;
    /** the years post-2000 */
    int yy;
    /** the hours 0-23*/
    int h;
    /** the minutes 0-59*/
    int m;
    /** unused */
    unsigned long toLong() const;

}; // DateTime

#endif
