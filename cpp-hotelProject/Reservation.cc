#include "Reservation.h"

Reservation::Reservation(string customerName, Date& checkIn, int duration){
    setReservation(customerName, checkIn, duration);
}

void Reservation::setReservation(string customerName, Date& checkIn, int duration){
    setCustomerName(customerName);
    setCheckInDate(checkIn);
    setDuration(duration);
}

void Reservation::setCustomerName(string name){
    customerName = name;
}

void Reservation::setCheckInDate(Date& d){
    checkIn = d;
}

void Reservation::setDuration(int duration){
    if (duration < 1){
        this->duration = 1;
    }
    else {
        this->duration = duration;
    }
}

Reservation Reservation::getReservation() {
    return *this;
}

string Reservation::getCustomerName(){
    return customerName;
}


bool Reservation::overlaps(Reservation& r){
    //this is the case where two range of dates overlap: (StartA <= EndB)  and  (EndA >= StartB)
    Date fLast = checkIn;
    fLast.addDays(duration - 1);
    Date sLast = r.checkIn;
    sLast.addDays(r.duration - 1);

    return checkIn.lessThan(r.checkIn) ? fLast.lessThan(r.checkIn) == false : sLast.lessThan(checkIn) == false;

   
}

bool Reservation::lessThan(Reservation& res){
    return !overlaps(res);

}

bool Reservation::lessThan(Date& d){
    Date first = checkIn;
    Date second = checkIn;
    second.addDays(duration-1);

    return (first.lessThan(d) && second.lessThan(d));

}



void Reservation::print(){
    cout <<"Reservation for "<<customerName<<" on "<<checkIn.getMonthName()<<" "<<checkIn.getDay()<<", "<<checkIn.getYear()<<" for "<<duration<<" days."<<endl; 
    //cout << "Duration is: "<<duration<<endl; 
}
