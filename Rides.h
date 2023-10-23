#ifndef RIDES_H
#define RIDES_H
#include "Ride.h"
#include "Passenger.h"
#include "Driver.h"
#include "Passengers.h"
#include "Drivers.h"
#include "Rides.h"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Rides
{
    public:
    void add_ride(vector<Ride>&rides,vector<Driver>&drivers,vector<Passenger>&passengers);
    bool search_ride(vector<Ride>&rides,int ride_id);
    void edit_ride(vector<Ride>&rides,int ride_id);
    void delete_ride(vector<Ride>&rides,int ride_id);
    
    void print_rides_for_passenger(vector<Ride>&rides,vector<Passenger>&passengers,int passenger_id);
    void print_rides_for_driver(vector<Ride>&rides,vector<Driver>&drivers,int driver_id);
    void print_all_rides(vector<Ride>&rides);
    void print_ride_by_id(vector<Ride>&rides,int ride_id);



    private:
    vector<Ride>rides;
    vector<Passenger>passengers;
    vector<Driver>drivers;

};



#endif