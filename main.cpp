#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include "Driver.h"
#include "Drivers.h"
#include "Passenger.h"
#include "Passengers.h"
#include "Ride.h"
#include "Rides.h"  
#include "functions.h" 

using namespace std;

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to represent a ride


struct Driver_struct{
    int id;
    string name;
    int capacity;
    bool handicapped;
    string type;
    float rating;
    bool available;
    bool pets;
    string notes;

};

struct Passenger_struct{
    string name;
    int id;
    string payment;
    bool handicapped;
    float rating;
    bool pets;

};

// Define a function to load rides from a file

struct Ride_struct {
    int id;
    string location;
    string time;
    string dropoff_location;
    int party_size;
    bool includes_pets;
    string dropoff_time;
    string status;
    float rating;
};

void load_data_rides(vector<Ride_struct>&rides) {
    ifstream input_file("rides.txt");
    if (input_file.is_open()) {
        Ride_struct ride;
        string ride_id_str;
        while (input_file >> ride_id_str >> ride.id >> ride.time >> ride.dropoff_location >> ride.party_size >> ride.includes_pets >> ride.dropoff_time >> ride.status >> ride.rating) {
           
            rides.push_back(ride);
        }
        input_file.close();
    }
}





void store_data_rides(const vector<Ride_struct>& rides) {
    ofstream output_file("rides.txt");
    if (output_file.is_open()) {
        for (const auto& ride : rides) {
            output_file << ride.id << " " << ride.location << " " << ride.time << " " << ride.dropoff_location << " " << ride.party_size << " " << ride.includes_pets << " " << ride.dropoff_time << " " << ride.status << " " << ride.rating << endl;
        }
        output_file.close();
    }
}

void load_data_drivers(vector<Driver_struct>& drivers) {
    ifstream input_file("drivers.txt");
    if (input_file.is_open()) {
        Driver_struct driver;
        while (input_file >> driver.id >> driver.name >> driver.capacity >> driver.handicapped >> driver.type >> driver.rating >> driver.available >> driver.pets >> driver.notes) {
            drivers.push_back(driver);
        }
        input_file.close();
    }
}

void store_data_drivers(const vector<Driver_struct>& drivers) {
    ofstream output_file("drivers.txt");
    if (output_file.is_open()) {
        for (const auto& driver : drivers) {
            output_file << driver.id << " " << driver.name << " " << driver.capacity << " " << driver.handicapped << " " << driver.type << " " << driver.rating << " " << driver.available << " " << driver.pets << " " << driver.notes << endl;
        }
        output_file.close();
    }
}

void load_data_passengers(vector<Passenger_struct>& passengers) {
    ifstream input_file("passengers.txt");
    if (input_file.is_open()) {
        Passenger_struct passenger;
        while (input_file >> passenger.name >> passenger.id >> passenger.payment >> passenger.handicapped >> passenger.rating >> passenger.pets) {
            passengers.push_back(passenger);
        }
        input_file.close();
    }
}

void store_data_passengers(const vector<Passenger_struct>& passengers) {
    ofstream output_file("passengers.txt");
    if (output_file.is_open()) {
        for (const auto& passenger : passengers) {
            output_file << passenger.name << " " << passenger.id << " " << passenger.payment << " " << passenger.handicapped << " " << passenger.rating << " " << passenger.pets << endl;
        }
        output_file.close();
    }
}


int main() {

    //create a file to store the data
    //create a file to load the data

    
    string driver_file="drivers.txt";
    string passenger_file="passengers.txt";
    string ride_file="rides.txt";

   

    ofstream fin,fin2,fin3;
    ifstream fout,fout2,fout3;

    fin.open(driver_file);
    fin2.open(passenger_file);
    fin3.open(ride_file);
    fout.open(driver_file);
    fout2.open(passenger_file);
    fout3.open(ride_file);


    
    if(fin.fail())
    {
        cout <<"error opening driver input file"<<endl;
        exit(1);
    }
    else
    {
        cout <<"driver input file opened successfully"<<endl;
    }
    fin.close();
    



    cout<< " CSCE 1040.002\n";
    cout <<" Caleb Ntende\n";
    cout <<" CalebNtende@my.unt.edu\n";
    cout <<" this program books rides and assigns drivers to passengers\n";
    
    vector<Driver>drivers;
    Drivers Drivers;
    vector<Passenger>passengers;
    Passengers Passengers;
    vector<Ride>rides;
    Rides Rides;
    vector<Ride_struct> ride_structs;
    vector<Driver_struct> driver_structs;
    vector<Passenger_struct> passenger_structs;

   
for (const auto& ride : rides) {
    Ride_struct ride_struct;
    ride_struct.id = ride.get_ride_id();
    ride_struct.location = ride.get_pickup_location();
    ride_struct.time = ride.get_pickup_time();
    ride_struct.dropoff_location = ride.get_dropoff_location();
    ride_struct.party_size = ride.get_party_size();
    ride_struct.includes_pets = ride.get_includes_pets();
    ride_struct.dropoff_time = ride.get_dropoff_time();
    ride_struct.status = ride.get_status();
    ride_struct.rating = ride.get_rating();
    ride_structs.push_back(ride_struct);
}
store_data_rides(ride_structs);

for(const auto& driver : drivers) {
    Driver_struct driver_struct;
    driver_struct.id = driver.get_id();
    driver_struct.name = driver.get_name();
    driver_struct.capacity = driver.get_capacity();
    driver_struct.handicapped = driver.get_handicapped();
    driver_struct.type = driver.get_type();
    driver_struct.rating = driver.get_rating();
    driver_struct.available = driver.get_availability();
    driver_struct.pets = driver.get_pets();
    driver_struct.notes = driver.get_notes();
    driver_structs.push_back(driver_struct);



}
store_data_drivers(driver_structs);

for(const auto& passenger : passengers) {
    Passenger_struct passenger_struct;
    passenger_struct.name = passenger.get_Passenger_name();
    passenger_struct.id = passenger.get_Passenger_id();
    passenger_struct.payment = passenger.get_Passenger_payment();
    passenger_struct.handicapped = passenger.get_Passenger_handicapped();
    passenger_struct.rating = passenger.get_Passenger_rating();
    passenger_struct.pets = passenger.get_Passenger_pets();
    passenger_structs.push_back(passenger_struct);

}
store_data_passengers(passenger_structs);
    
// this nested loop is to load the data from the file

    int choice;
    print_menu();
    do
    {
        //this is the main menu
        cout <<" enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        do{
            //give the user the option to choose from the driver menu
            driver_menu();
            cin >> choice;
            switch(choice)
            {
                case 1:
                
               Drivers.add_driver(drivers);
                cout <<"driver added successfully\n";
                break;
                case 2:
                cout <<"enter driver driver ID that you want to edit:\n";
                int driver_id;
                cin >> driver_id;
                cin.ignore();
                Drivers.edit_driver(drivers,driver_id);
                cout <<"test2";
                cout<<endl;
                break;
                case 3:
                int driver_id_edit;
                cout <<"enter a driver you want to delete:\n";
                cin>>driver_id_edit;
                Drivers.delete_driver(drivers,driver_id_edit);
                cout <<"test3";
                cout<<endl;
                break;
                case 4:
                int driver_id_search;
                cout <<"enter a driver you want to search:\n";
                cin>>driver_id_search;
                Drivers.search_driver(drivers,driver_id_search);
                cout <<"test4";
                cout<<endl;
                break;
                case 5:
                cout <<"test5\n";
                Drivers.print(drivers);
                cout<<endl;
                break;
                case 6:
                cout <<"test6";
                cout<<endl;
                break;
                default:
                break;
            }
        }while(choice!=6);
        cout <<"test1";
        cout<<endl;

            break;
        case 2:
         do{
            //this gives the user the option to choose from the passenger menu
            passenger_menu();
            
            cin >> choice;
            switch(choice)
            {
                case 1:
                cout <<"test1"<<endl;
                Passengers.add_passenger(passengers);
                cout << "passenger added successfully\n";
                break;
                case 2:
                cout << "enter passenger ID that you want to edit:\n";
                int passenger_id;
                cin >> passenger_id;
                cin.ignore();
                Passengers.edit_passenger(passengers,passenger_id);
                cout <<"test2";
                cout<<endl;
                break;
                case 3:
                int passenger_id_delete;
                cout <<"enter a passenger you want to delete:\n";
                cin>>passenger_id_delete;
                Passengers.delete_passenger(passengers,passenger_id_delete);

                cout <<"test3";
                cout<<endl;
                break;
                case 4:
                int passenger_id_search;
                cout <<"enter a passenger you want to search:\n";
                cin>>passenger_id_search;
                Passengers.search_passenger(passengers,passenger_id_search);
                cout <<"test4";
                cout<<endl;
                break;
                case 5:
                cout <<"print passengers\n";
                Passengers.print_passenger(passengers);

                cout <<"test5";
                cout<<endl;
                break;
                case 6:
                cout <<"test6";
                cout<<endl;
                break;
                default:
                break;
            }

        }while(choice!=6);


        
            cout <<endl;
                break;
        case 3:
       do{
            //this gives the user the option to choose from the ride menu
            ride_menu();
            
            cin >> choice;
            switch(choice)
            {
                case 1:
                cout <<"test1"<<endl;
                Rides.add_ride(rides,drivers,passengers);   
                
                break;
                case 2:
                cout<<"enter ride ID you want to search:\n";
                int ride_id;
                cin >> ride_id;
                cin.ignore();
                Rides.search_ride(rides,ride_id);

                cout <<"test2";
                cout<<endl;
                break;
                case 3:
                cout <<"enter ride ID you want to edit:\n";
                int ride_id_edit;
                cin >> ride_id_edit;
                cin.ignore();
                Rides.edit_ride(rides,ride_id_edit);
                cout<<endl;
                break;
                case 4:
                cout <<"enter ride ID you want to delete:\n";
                int ride_id_delete;
                cin >> ride_id_delete;
                cin.ignore();
                Rides.delete_ride(rides,ride_id_delete);
                cout <<"test4";
                cout<<endl;
                break;
                case 5:
                cout <<"enter the ride ID you want to print:\n";
                int ride_id_print;
                cin >> ride_id_print;
                cin.ignore();
                Rides.print_ride_by_id(rides,ride_id_print);
                cout <<"test5";
                cout<<endl;
                break;
                case 6:
                cout <<"print ride for specific passenger\n";
                int passenger_id_print;
                cout <<"enter passenger ID:\n";
                cin >> passenger_id_print;
                cin.ignore();
                Rides.print_rides_for_passenger(rides,passengers,passenger_id_print);
                cout <<"test6";
                cout<<endl;
                break;
                case 7:
                cout <<"test7";
                cout <<"Print ride for specific driver\n";
                int driver_id_print;
                cout <<"enter driver ID:\n";
                cin >> driver_id_print;
                cin.ignore();
                Rides.print_rides_for_driver(rides,drivers,driver_id_print);
                cout<<endl;
                break;
                case 8:
                
                cout <<"print all rides\n";
                Rides.print_all_rides(rides);
                cout<<endl;
                break;
                case 9:
                cout <<"test9";
                default:
                break;
            }

        }while(choice!=9);
        cout <<"test3";
        cout<<endl;

            break;
        
        default:
            break;
        }
        print_menu();
        
    } while (choice != 4);

    load_data_passengers(passenger_structs);
    load_data_drivers(driver_structs);
    load_data_rides(ride_structs);
    return 0;

} 
    