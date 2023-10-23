eaglelyft: Driver.o Drivers.o Passenger.o Passengers.o Ride.o Rides.o functions.o main.o
	g++ Driver.o Drivers.o Passenger.o Passengers.o Ride.o Rides.o functions.o main.o -o eaglelyft

Driver.o: Driver.cpp
	g++ -c Driver.cpp

Drivers.o: Drivers.cpp
	g++ -c Drivers.cpp

Passenger.o: Passenger.cpp
	g++ -c Passenger.cpp

Passengers.o: Passengers.cpp
	g++ -c Passengers.cpp

Ride.o: Ride.cpp
	g++ -c Ride.cpp

Rides.o: Rides.cpp 
	g++ -c Rides.cpp
functions.o: functions.cpp
	g++ -c functions.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o
