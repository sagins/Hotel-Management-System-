a1: main.o Date.o Reservation.o Room.o Hotel.o
	g++ -o a1 main.o Date.o Reservation.o Room.o Hotel.o

main.o: main.cc Date.cc Reservation.cc Room.cc Hotel.cc
	g++ -c main.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

Room.o: Room.cc Room.h
	g++ -c Room.cc

Hotel.o: Hotel.cc Hotel.h
	g++ -c Hotel.cc Hotel.h

clean:
	rm -f *.o a1    
