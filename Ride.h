#ifndef RIDE_H
#define RIDE_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Ride {
public:
    Ride();
    Ride(int id, string location, time_t time, string dropoff_location, int party_size, bool includes_pets, time_t dropoff_time, string status, float rating);
    
    // Getters
    int get_ride_id() const;
    string get_pickup_location() const;
    time_t get_pickup_time() const;
    string get_dropoff_location() const;
    int get_party_size() const;
    bool get_includes_pets() const;
    time_t get_dropoff_time() const;
    string get_status() const;
    float get_rating() const;
    
    // Setters
    void set_ride_id(int id);
    void set_pickup_location(string pickup_location);
    void set_pickup_time(time_t pickup_time);
    void set_dropoff_location(string dropoff_location);
    void set_party_size(int party_size);
    void set_includes_pets(bool includes_pets);
    void set_dropoff_time(time_t dropoff_time);
    void set_status(string status);
    void set_rating(float rating);    
private:
    int ride_id;
    string ride_pickup_location;
    time_t ride_pickup_time;
    string ride_dropoff_location;
    int ride_party_size;
    bool ride_pets;
    time_t ride_dropoff_time;
    string ride_status;
    float ride_rating;
};

#endif