
#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "Reservation.h"
#include "Room.h"

using namespace std;
class Hotel {
		
	public:
		//constructors
        Hotel();

        // make a destructor for bonus


		// getters

		// other functions
        bool addRoom(int roomNumber, string bedType, int capacity, bool fr);
	bool deleteRoom(int roomNumber);
        bool getRoom(int roomNumber, Room** room);
        bool addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration);
	void print();
        void printReservations();

	
	private:
		//functions

			
	
		//variables
        Room* rooms[MAX_ROOMS];
        int numRooms;


		
	
};
#endif

