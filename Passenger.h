#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <iostream>

using namespace std;
// passenger class that holds all the information about the passenger
class Passenger
{
    public:
    Passenger();
    Passenger(string name, int id, string payment, bool handicapped, float rating,bool pets);
    string get_Passenger_name()const;
    int get_Passenger_id()const;
    string get_Passenger_payment()const;
    bool get_Passenger_handicapped()const;
    float get_Passenger_rating()const;
    bool get_Passenger_pets()const;
    void set_Passenger_name(string name);
    void set_Passenger_id(int id);
    void set_Passenger_payment(string payment);
    void set_Passenger_handicapped(bool handicapped);
    void set_Passenger_rating(float rating);
    void set_Passenger_pets(bool pets);
    private:
    string Passenger_name;
    int Passenger_id;
    string Passenger_payment;
    bool Passenger_handicapped;
    float Passenger_rating;
    bool Passenger_pets;
    


};


#endif