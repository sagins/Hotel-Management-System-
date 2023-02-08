
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "Reservation.h"

using namespace std;

class Room {
		
	public:
		//constructors
		Room(int roomNumber, string bedType, int capacity, bool hasFridge);


		// getters
		int getRoomNumber();
		Reservation getReservation(int index);

		// other functions
		bool isMatch(string bt, int cap, bool f);
		bool lessThan(Room& r);
		bool addReservation(string customerName, Date& d, int duration);
		void printReservations();
		void print();
		
	
	private:
		//functions
		// get the number of days in this month
			
	
		//variables
		int roomNumber;
        string bedType;
        int capacity;
        bool hasFridge;
		Reservation* reservations[MAX_RES];
		int numReservations;
	
};
#endif

