#include <iostream>
#include <vector>
#include "Driver.h"
#include "Drivers.h"
using namespace std;

//add driver function that takes in a vector of drivers and adds a driver to the vector
void Drivers::add_driver(vector<Driver>&drivers)
{
    

    int Driver_id;
    string Driver_name;
    int Driver_capacity;
    bool Driver_handicapped;
    string Driver_type;
    float Driver_rating;
    bool Driver_availability=false;
    bool Driver_pets;
    string Driver_notes;
    cout <<"Driver id is assigned: ";
    static int id=100000;
    Driver_id=id;
    id++;
    cout << "Driver ID: " <<Driver_id<<endl;
    cin.ignore();
    cout <<"enter driver name :";
    getline(cin,Driver_name);
    cout <<"enter driver capacity(number of passenders) :";
    cin >> Driver_capacity;
    cin.ignore();
    cout <<"enter driver type(sedan,SUV) :";
    cin >> Driver_type;
    cin.ignore();
    cout <<"enter driver rating :";
    cin >> Driver_rating;
    cin.ignore();
    cout <<"enter driver availability(yes/no) :";
    string available;
    cin >> available;
    cin.ignore();
    if(available=="yes")
    {
        Driver_availability=true;
    }
    else
    {
        Driver_availability=false;
    }
    cout <<"enter driver pets(yes/no) :";
    string pets;
    cin >> pets;
    cin.ignore();
    if(pets=="yes")
    {
        Driver_pets=true;
    }
    else
    {
        Driver_pets=false;
    }
    cout <<"enter driver notes :";
    getline(cin,Driver_notes);

    Driver d(Driver_id,Driver_name ,Driver_capacity, Driver_handicapped, Driver_type, Driver_rating, Driver_availability, Driver_pets, Driver_notes);
    drivers.push_back(d);    
}
//search driver function that takes in a vector of drivers and a driver id and searches for the driver
bool Drivers::search_driver(vector<Driver>& drivers, int Driver_id)
{
    for (int i = 0; i < drivers.size(); i++)
    {
        if (drivers[i].get_id() == Driver_id)
        {
            return true;
            cout <<"driver found\n";
            break;
        }
    }
    cout <<" driver not found\n";
    return false;
}
//edit driver function that takes in a vector of drivers and a driver id and edits the driver
void Drivers::edit_driver(vector<Driver>& drivers, int Driver_id)
{
    string Driver_name;
    int Driver_capacity;
    bool Driver_handicapped;
    string Driver_type;
    float Driver_rating;
    bool Driver_availability=false;
    bool Driver_pets;
    string Driver_notes;
    
    if(search_driver(drivers, Driver_id))
    {
        for (int i = 0; i < drivers.size(); i++)
        {
            if (drivers[i].get_id() == Driver_id)
            {
                cout <<"enter driver name :";
                getline(cin,Driver_name);
                drivers[i].set_name(Driver_name);

                cout <<"enter driver capacity :";
                cin >> Driver_capacity;
                cin.ignore();
                cout <<"enter driver type :";
                cin >> Driver_type;
                drivers[i].set_type(Driver_type);
                cin.ignore();
                cout <<"enter driver rating :";
                cin >> Driver_rating;
                drivers[i].set_rating(Driver_rating);
                cin.ignore();
                cout <<"enter driver availability :";
                string available;
                cin >> available;
                cin.ignore();
                if(available=="yes")
                {
                    Driver_availability=true;
                }
                else
                {
                    Driver_availability=false;
                }
                cout <<"enter driver pets :";
                string pets;
                cin >> pets;
                cin.ignore();
                if(pets=="yes")
                {
                    Driver_pets=true;
                }
                else
                {
                    Driver_pets=false;
                }
                cout <<"enter driver notes :";
                getline(cin,Driver_notes);
                drivers[i].set_notes(Driver_notes);
                drivers[i]= Driver(Driver_id,Driver_name ,Driver_capacity, Driver_handicapped, Driver_type, Driver_rating, Driver_availability, Driver_pets, Driver_notes);
            }
        }
    }
}
//delete driver function that takes in a vector of drivers and a driver id and deletes the driver
void Drivers::delete_driver(vector<Driver>& drivers, int Driver_id)
{
    if(search_driver(drivers, Driver_id))
    {
        for (int i = 0; i < drivers.size(); i++)
        {
            if (drivers[i].get_id() == Driver_id)
            {
                drivers.erase(drivers.begin()+i);
            }
        }
    }
}
//print driver function that takes in a vector of drivers and prints the driver
void Drivers::print(vector<Driver>&drivers)
{
    for (int i = 0; i < drivers.size(); i++)
    {
        cout <<"Driver id: "<<drivers[i].get_id()<<endl;
        cout <<"Driver name: "<<drivers[i].get_name()<<endl;
        cout <<"Driver capacity: "<<drivers[i].get_capacity()<<endl;
        cout <<"Driver type: "<<drivers[i].get_type()<<endl;
        cout <<"Driver rating: "<<drivers[i].get_rating()<<endl;
      //cout <<"Driver availability: "<<drivers[i].get_availability()<<endl;
      //cout <<"Driver pets: "<<drivers[i].Driver_pets<<endl;
        cout <<"Driver notes: "<<drivers[i].get_notes()<<endl;
    }

}
// driver menu
void menu()
{
    cout <<"1. Add driver\n";
    cout <<"2. Edit driver\n";
    cout <<"3. Delete driver\n";
    cout <<"4. search driver\n";
    cout <<"5. Print driver\n";
    cout <<"6. Exit\n";
    cout <<"Enter your choice: ";
}
