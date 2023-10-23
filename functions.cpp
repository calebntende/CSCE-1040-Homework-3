#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
//function that prints the menu
void print_menu()
{
    cout  << "1.Access Drivers" << endl;
    cout << "2. Access Passengers" << endl;
    cout << "3. Access Rides" << endl;
    cout << "4. Exit" << endl;

}

void driver_menu()
{
    cout <<"1. Add driver\n";
    cout <<"2. Edit driver\n";
    cout <<"3. Delete driver\n";
    cout <<"4. search driver\n";
    cout <<"5. Print driver\n";
    cout <<"6. Exit\n";
    cout <<"Enter your choice: ";
}

void passenger_menu()
{
    cout <<"1. Add passenger\n";
    cout <<"2. Edit passenger\n";
    cout <<"3. Delete passenger\n";
    cout <<"4. search passenger\n";
    cout <<"5. Print passenger\n";
    cout <<"6. Exit\n";
    cout <<"Enter your choice: ";
}

void ride_menu()
{
    cout <<"1. Add ride\n";
    cout <<"2. Edit ride\n";
    cout <<"3. Delete ride\n";
    cout <<"4. search ride\n";
    cout <<"5. print ride by ID\n";
    cout <<"6. print ride for specific passenger\n";
    cout <<"7. print rides for a driver\n";
    cout <<"8. print all rides\n";
    cout <<"9. Exit\n"; 
}

void check_file_opened(const string& filename, const  std::ios_base::openmode& mode) {
    fstream file(filename, mode);
    if (file.is_open()) {
        cout << "File " << filename << " opened successfully" << endl;
        file.close();
    }
    else {
        cout << "Error opening file " << filename << endl;
    }
}

