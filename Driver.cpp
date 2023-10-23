#include <iostream>
#include <vector>
#include "Driver.h"
#include "Drivers.h"
using namespace std;
//default constructor
Driver::Driver()
{
    Driver_id=100000;
    Driver_name= " ";
    
    Driver_capacity= 2;
    Driver_handicapped=false;
    Driver_type= "coupe";
    Driver_rating= 0;
    Driver_availability= false;
    Driver_pets=false;
    Driver_notes= " ";
}
//constructor that takes in all the variables
Driver::Driver(int id, string name , int capacity, bool handicapped, string type, float rating, bool available, bool pets, string notes)
{
    Driver_id = id;
    Driver_name = name;
    Driver_capacity = capacity;
    Driver_handicapped = handicapped;
    Driver_type = type;
    Driver_rating = rating;
    Driver_availability = available;
    Driver_pets = pets;
    Driver_notes = notes;
}

int Driver::get_id() const
{
    return Driver_id;
}
void Driver::set_id(int id)
{
    Driver_id = id;
}

string Driver::get_name() const
{
    return Driver_name;
}

void Driver::set_name(string name)
{
    Driver_name = name;
}

int Driver::get_capacity() const
{
    return Driver_capacity;
}

void Driver::set_capacity(int capacity)
{
    Driver_capacity = capacity;
}

bool Driver::get_handicapped() const
{
    return Driver_handicapped;
}   

void Driver::set_handicapped(bool handicapped)
{
    Driver_handicapped = handicapped;
}

string Driver::get_type() const
{
    return Driver_type;
}

void Driver::set_type(string type)
{
    Driver_type = type;
}

float Driver::get_rating() const
{
    return Driver_rating;
}

void Driver::set_rating(float rating)
{
    Driver_rating = rating;
}

bool Driver::get_availability() const
{
    return Driver_availability;
}

void Driver::set_availability(bool available)
{
    Driver_availability = available;
}

bool Driver::get_pets() const
{
    return Driver_pets;
}

void Driver::set_pets(bool pets)
{
    Driver_pets = pets;
}

string Driver::get_notes() const
{
    return Driver_notes;
}

void Driver::set_notes(string notes)
{
    Driver_notes = notes;
}



