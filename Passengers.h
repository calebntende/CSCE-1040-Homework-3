#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <string>
#include <vector>  // Include the vector header
#include "Passenger.h"

#include <string>
#include <iostream>
using namespace std;
//drivers class is a collection entity that holds a vector of drivers
class Passengers
{
    public:
    
    void add_passenger(vector<Passenger>&passengers);
    void edit_passenger(vector<Passenger>&passengers,int passenger_id);
    void delete_passenger(vector<Passenger>&passengers,int passenger_id);
    bool search_passenger(vector<Passenger>&passengers,int passenger_id);
    void print_passenger(vector<Passenger>&passengers);
    private:
    vector<Passenger>passengers;
};




#endif