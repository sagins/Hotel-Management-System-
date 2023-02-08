#include "Room.h"
#include "Reservation.h"


Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge){
    this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    numReservations = 0;
}

// make a destructor for bonus


int Room::getRoomNumber(){
    return roomNumber;
}

Reservation Room::getReservation(int index){
    // if the index is out of bounds return null
    if (index < 0 || index >= numReservations){
        return *reservations[numReservations];
    }
    return *reservations[index];
}




bool Room::isMatch(string bt, int cap, bool f){
    // if f is false then has fridge can be true or false
    return (bt == bedType && cap <= capacity && (f == false || hasFridge == true));
}

bool Room::lessThan(Room& r){
    return roomNumber < r.roomNumber;
}


bool Room::addReservation(string customerName, Date& d, int duration){
    // check if there is space for a new reservation
    if (numReservations == MAX_RES){
        return false;
    }
    
    // check if the reservation overlaps with any other reservation

    // There might be memmory leaks here check this later
    Reservation newRes = Reservation(customerName, d, duration);
    for (int i = 0; i < numReservations; i++){
        if (reservations[i]->overlaps(newRes)){
            return false;
        }
    }
    reservations[numReservations] = new Reservation(customerName, d, duration);
    numReservations++;
    return true;
}

void Room::print(){
    cout << "Room " << roomNumber << " (" << bedType << ", " << capacity << " people, " << (hasFridge ? "fridge" : "no fridge") << ")" << endl;
    //printReservations();
}


void Room::printReservations(){
    cout << "Room " << roomNumber << " reservations:" << endl;
    for (int i = 0; i < numReservations; i++){
        cout << "Reservation for: "<< reservations[i]->getCustomerName() << endl;
    }
}

