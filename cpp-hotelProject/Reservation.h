#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"


using namespace std;


class Reservation {

    public:
        // constructors
        Reservation(string customerName, Date& checkIn, int duration);

        // setters
        void setReservation(string, Date&, int);
        void setCustomerName(string);
        void setCheckInDate(Date&);
        void setDuration(int);

        // getters
        Reservation getReservation();
        string getCustomerName();


        // other functions
        bool overlaps(Reservation& r);
        void print();
        bool lessThan(Reservation& res);
        bool lessThan(Date& d);


    private:
        // variables
        string customerName;
        Date checkIn;
        int duration;


};









#endif
