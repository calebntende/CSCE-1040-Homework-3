#include <string>
#include <iostream>
#include <vector>
#include "Passenger.h"
#include "Passengers.h"
using namespace std;
// default constructor
Passenger::Passenger()
{
    Passenger_name = "";
    Passenger_id = 0;
    Passenger_payment = "";
    Passenger_handicapped = false;
    Passenger_rating = 0.0;
    Passenger_pets = false;
}
// parameterized constructor
Passenger::Passenger(string name, int id, string payment, bool handicapped, float rating,bool pets)
{
    Passenger_name = name;
    Passenger_id = id;
    Passenger_payment = payment;
    Passenger_handicapped = handicapped;
    Passenger_rating = rating;
    Passenger_pets = pets;
    
}

string Passenger::get_Passenger_name() const
{
    return Passenger_name;
}

int Passenger::get_Passenger_id() const
{
    return Passenger_id;
}

string Passenger::get_Passenger_payment() const
{
    return Passenger_payment;
}

bool Passenger::get_Passenger_handicapped() const
{
    return Passenger_handicapped;
}

float Passenger::get_Passenger_rating() const
{
    return Passenger_rating;
}

bool Passenger::get_Passenger_pets() const
{
    return Passenger_pets;
}

void Passenger::set_Passenger_name(string name)
{
    Passenger_name = name;
}

void Passenger::set_Passenger_id(int id)
{
    Passenger_id = id;
}

void Passenger::set_Passenger_payment(string payment)
{
    Passenger_payment = payment;
}

void Passenger::set_Passenger_handicapped(bool handicapped)
{
    Passenger_handicapped = handicapped;
}

void Passenger::set_Passenger_rating(float rating)
{
    Passenger_rating = rating;
}

void Passenger::set_Passenger_pets(bool pets)
{
    Passenger_pets = pets;
}
