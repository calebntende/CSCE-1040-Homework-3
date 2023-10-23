#include "Ride.h"
#include "Passenger.h"
#include "Driver.h"
#include "Rides.h"
#include "Passengers.h"
#include "Drivers.h"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;

time_t convert_string_to_time_t(const std::string& str) {
    struct tm tm = {0};
    strptime(str.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
    return mktime(&tm);
}

void Rides::add_ride(vector<Ride>&rides,vector<Driver>&drivers,vector<Passenger>&passengers)
{
    // Ride properties
    int ride_id;
    string ride_pickup_location;
    string ride_pickup_time_str;
    string ride_dropoff_location;
    int party_size;
    bool ride_pets;
    string ride_status;
    float ride_rating;

    // Assign a unique ride_id (you can adapt this logic)
    

    cout << "Ride ID: " << ride_id << endl;

    // Get ride data from user input
    cout << "Enter pickup location: ";
    getline(cin, ride_pickup_location);

    cout << "Enter pickup time (format: YYYY-MM-DD HH:MM:SS): ";
    getline(cin, ride_pickup_time_str);
    time_t ride_pickup_time = convert_string_to_time_t(ride_pickup_time_str);

    cout << "Enter drop-off location: ";
    getline(cin, ride_dropoff_location);

    cout << "Enter party size: ";
    cin >> party_size;
    cin.ignore();

    cout << "Includes pets? (yes/no): ";
    string ride_pets_str;
    getline(cin, ride_pets_str);
    ride_pets = (ride_pets_str == "yes");

    cout << "Enter ride status: ";
    getline(cin, ride_status);

    cout << "Enter ride rating: ";
    cin >> ride_rating;
    cin.ignore();

   // Create the new Ride object
Ride ride(ride_id, ride_pickup_location, ride_pickup_time, ride_dropoff_location, party_size, ride_pets, time(nullptr), ride_status, ride_rating);

// Find a driver that meets the criteria

// Create an unordered_map of available drivers

 Driver* driver_ptr = nullptr;
    for (int i = 0; i < drivers.size(); i++) {
        Driver& driver = drivers[i];
        if (driver.get_availability() &&
            driver.get_capacity() >= party_size &&
            driver.get_pets() == ride_pets &&
            driver.get_rating() >= ride_rating) {
            // Find a passenger that meets the criteria
            for (int j = 0; j < passengers.size(); j++) {
                Passenger& passenger = passengers[j];
                if (passenger.get_Passenger_handicapped() &&
                    driver.get_handicapped() == passenger.get_Passenger_handicapped()) {
                    driver_ptr = &driver;
                    break;
                }
            }
            if (driver_ptr != nullptr) {
                break;
            }
        }
    }

    if (driver_ptr != nullptr) {
        // Create the new Ride object with a unique ID
        rides.push_back(ride);
        cout << "Ride added successfully!" << endl;
    } else {
        cout << "No driver found!" << endl;
    }
  




}

bool Rides::search_ride(vector<Ride>&rides,int ride_id)
{
    for (int i = 0; i < rides.size(); i++) 
    {
        if (rides[i].get_ride_id() == ride_id) 
        {
        cout <<"Ride found\n";
            return true;
        }
    }
    cout << "Ride not found!" << endl;
    
    
}

void Rides::edit_ride(vector<Ride>&rides,int ride_id)
{
    //int ride_id;
    string ride_pickup_location;
    string ride_pickup_time_str;
    string ride_dropoff_location;
    int party_size;
    bool ride_pets;
    string ride_status;
    float ride_rating;

    if(search_ride(rides,ride_id))
    {
        for(int i=0;i<rides.size();i++)
        {
            if(rides[i].get_ride_id()==ride_id)
            {
                cout << "Enter pickup location: ";
                getline(cin, ride_pickup_location);

                cout << "Enter pickup time (format: YYYY-MM-DD HH:MM:SS): ";
                getline(cin, ride_pickup_time_str);
                time_t ride_pickup_time = convert_string_to_time_t(ride_pickup_time_str);

                cout << "Enter drop-off location: ";
                getline(cin, ride_dropoff_location);

                cout << "Enter party size: ";
                cin >> party_size;
                cin.ignore();

                cout << "Includes pets? (yes/no): ";
                string ride_pets_str;
                getline(cin, ride_pets_str);
                ride_pets = (ride_pets_str == "yes");

                cout << "Enter ride status: ";
                getline(cin, ride_status);

                cout << "Enter ride rating: ";
                cin >> ride_rating;
                cin.ignore();

                Ride ride(ride_id, ride_pickup_location, ride_pickup_time, ride_dropoff_location, party_size, ride_pets, time(nullptr), ride_status, ride_rating);

                rides[i].set_pickup_location(ride_pickup_location);
                rides[i].set_pickup_time(ride_pickup_time);
                rides[i].set_dropoff_location(ride_dropoff_location);
                rides[i].set_party_size(party_size);
                rides[i].set_includes_pets(ride_pets);
                rides[i].set_status(ride_status);
                rides[i].set_rating(ride_rating);
                rides[i]=ride;
                cout <<"Ride edited successfully\n";
            }
        }
    }
    else
    {
        cout <<"Ride not found\n";
        
    }

}


void Rides::delete_ride(vector<Ride>&rides,int ride_id)
{
    if(search_ride(rides,ride_id))
    {
        for(int i=0;i<rides.size();i++)
        {
            if(rides[i].get_ride_id()==ride_id)
            {
                rides.erase(rides.begin()+i);
                cout <<"Ride deleted successfully\n";
            }
        }
    }
    else
    {
        cout <<"Ride not found\n";
        
    }
}

void Rides::print_rides_for_passenger(vector<Ride>&rides, vector<Passenger>&passengers, int passenger_id)
{
    
    for (const Passenger& passenger : passengers) 
    {
        if(passenger.get_Passenger_id()==passenger_id)
    {
        cout << "Rides for passenger: " << passenger.get_Passenger_name() << endl;
        for (const Ride& ride : rides) 
        {
            if(ride.get_rating()>= passenger.get_Passenger_rating()&&ride.get_includes_pets()==passenger.get_Passenger_pets()){
                cout << "Ride ID: " << ride.get_ride_id() << endl;
                cout << "Pickup Location: " << ride.get_pickup_location() << endl;
                cout << "Pickup Time: " << ride.get_pickup_time() << endl;
                cout << "Dropoff Location: " << ride.get_dropoff_location() << endl;
                cout << "Party Size: " << ride.get_party_size() << endl;
                cout << "Includes Pets: " << ride.get_includes_pets() << endl;
                cout << "Status: " << ride.get_status() << endl;
                cout << "Rating: " << ride.get_rating() << endl;
            }
            
        }
    }
    
}
}

void Rides::print_rides_for_driver(vector<Ride>&rides, vector<Driver>&drivers, int driver_id)
{
    for (const Driver& driver : drivers) 
    {
        if(driver.get_id()==driver_id)
    {
        cout << "Rides for driver: " << driver.get_name() << endl;
        for (const Ride& ride : rides) 
        {
            if(ride.get_rating()>= driver.get_rating()&&ride.get_includes_pets()==driver.get_pets()&&(driver.get_availability())){
                cout << "Ride ID: " << ride.get_ride_id() << endl;
                cout << "Pickup Location: " << ride.get_pickup_location() << endl;
                cout << "Pickup Time: " << ride.get_pickup_time() << endl;
                cout << "Dropoff Location: " << ride.get_dropoff_location() << endl;
                cout << "Party Size: " << ride.get_party_size() << endl;
                cout << "Includes Pets: " << ride.get_includes_pets() << endl;
                cout << "Status: " << ride.get_status() << endl;
                cout << "Rating: " << ride.get_rating() << endl;
            }
            
        }
    }
    
}
}
// this prints all the rides
void Rides::print_all_rides(vector<Ride>&rides)
{
    for (const Ride& ride : rides) 
    {
        cout << "Ride ID: " << ride.get_ride_id() << endl;
        cout << "Pickup Location: " << ride.get_pickup_location() << endl;
        cout << "Pickup Time: " << ride.get_pickup_time() << endl;
        cout << "Dropoff Location: " << ride.get_dropoff_location() << endl;
        cout << "Party Size: " << ride.get_party_size() << endl;
        cout << "Includes Pets: " << ride.get_includes_pets() << endl;
        cout << "Status: " << ride.get_status() << endl;
        cout << "Rating: " << ride.get_rating() << endl;
    }
}

void Rides::print_ride_by_id(vector<Ride>&rides,int ride_id)
{
   
    for (const Ride& ride : rides) 
    {
        if(ride.get_ride_id()==ride_id)
        {
            cout << "Ride ID: " << ride.get_ride_id() << endl;
            cout << "Pickup Location: " << ride.get_pickup_location() << endl;
            cout << "Pickup Time: " << ride.get_pickup_time() << endl;
            cout << "Dropoff Location: " << ride.get_dropoff_location() << endl;
            cout << "Party Size: " << ride.get_party_size() << endl;
            cout << "Includes Pets: " << ride.get_includes_pets() << endl;
            cout << "Status: " << ride.get_status() << endl;
            cout << "Rating: " << ride.get_rating() << endl;
        }
    }
}
   





