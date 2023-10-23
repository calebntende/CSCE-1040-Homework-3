#include "Ride.h"
#include "Rides.h"
#include <iostream>
#include <ctime>
using namespace std;
// this is a default constructor that sets the values to 0 or empty
Ride::Ride() {
    ride_id = 10000000;
    ride_pickup_location = "";
    ride_pickup_time = 0;
    ride_dropoff_location = "";
    ride_party_size = 0;
    ride_pets = false;
    ride_dropoff_time = 0;
    ride_status = "";
    ride_rating = 0;
}

Ride::Ride(int id, string location, time_t time, string dropoff_location, int party_size, bool includes_pets, time_t dropoff_time, string status, float rating) {
    ride_id = id;
    ride_pickup_location = location;
    ride_pickup_time = time;
    ride_dropoff_location = dropoff_location;
    ride_party_size = party_size;
    ride_pets = includes_pets;
    ride_dropoff_time = dropoff_time;
    ride_status = status;
    ride_rating = rating;
}

// Getters
int Ride::get_ride_id() const {
    return ride_id;
}

string Ride::get_pickup_location() const {
    return ride_pickup_location;
}

time_t Ride::get_pickup_time() const {
    return ride_pickup_time;
}

string Ride::get_dropoff_location() const {
    return ride_dropoff_location;
}

int Ride::get_party_size() const {
    return ride_party_size;
}

bool Ride::get_includes_pets() const {
    return ride_pets;
}

time_t Ride::get_dropoff_time() const {
    return ride_dropoff_time;
}

string Ride::get_status() const {
    return ride_status;
}

float Ride::get_rating() const {
    return ride_rating;
}

// Setters

void Ride::set_ride_id(int id) {
    ride_id = id;
}

void Ride::set_pickup_location(string pickup_location) {
    ride_pickup_location = pickup_location;
}

void Ride::set_pickup_time(time_t pickup_time) {
    ride_pickup_time = pickup_time;
}

void Ride::set_dropoff_location(string dropoff_location) {
    ride_dropoff_location = dropoff_location;
}

void Ride::set_party_size(int party_size) {
    party_size = party_size;
}

void Ride::set_includes_pets(bool includes_pets) {
    ride_pets = includes_pets;
}


void Ride::set_dropoff_time(time_t dropoff_time) {
    ride_dropoff_time = dropoff_time;
}

void Ride::set_status(string status) {
    ride_status = status;
}

void Ride::set_rating(float rating) {
    ride_rating = rating;
}

