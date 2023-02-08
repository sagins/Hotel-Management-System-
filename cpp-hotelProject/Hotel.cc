#include "Hotel.h"

Hotel::Hotel(){
    numRooms = 0;
}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr){
    if (numRooms == MAX_ROOMS){
        return false;
    }

    for (int i = 0; i < numRooms; i++){
        if (rooms[i]->getRoomNumber() == roomNumber){
            return false;
        }
    }

    Room newRoom = Room(roomNumber, bedType, capacity, fr);
    int index = 0;
    while (index < numRooms && rooms[index]->lessThan(newRoom)){
        index++;
    }
    for (int i = numRooms; i > index; i--){
        rooms[i] = rooms[i - 1];
    }
    rooms[index] = new Room(roomNumber, bedType, capacity, fr);
    numRooms++;
    return true;
}


bool Hotel::deleteRoom(int roomNumber){
    int indexToRemove = -1;
    for (int i = 0; i < numRooms; i++){
        if (rooms[i]->getRoomNumber() == roomNumber){
            indexToRemove = i;
        }
    }
    if (indexToRemove >= 0){
        for (int i = indexToRemove; i < numRooms - 1; i++){
            rooms[i] = rooms[i + 1];
        }
        numRooms--;
        return true;
    }
    return false;
}


bool Hotel::getRoom(int roomNumber, Room** room){
    for (int i = 0; i < numRooms; i++){
        if (rooms[i]->getRoomNumber() == roomNumber){
            // WATCH OUT HERE MIGHT GET AN ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            *room = rooms[i];
            return true;
        }
    }
    return false;
}


bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration){
    // might need to delete this later to avoid memory leaks
    Reservation newRes = Reservation(customer, date, duration);
    for (int i = 0; i < numRooms; i++){
        if(rooms[i]->isMatch(bedType, capacity, fr)){            
            if (rooms[i]->addReservation(customer, date, duration)){
                return true;
            }
            return false;
        } 
    }
    return false;
}

void Hotel::print(){
    for (int i = 0; i < numRooms; i++){
        rooms[i]->print();
    }
}


void Hotel::printReservations(){
    for (int i = 0; i < numRooms; i++){
        rooms[i]->printReservations();
    }
}
