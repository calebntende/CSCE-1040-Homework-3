#ifndef DRIVERS_H
#define DRIVERS_H
#include <string>
#include <iostream>
using namespace std;
//drivers class is a collection entity that holds a vector of drivers
class Drivers{
    public:
   void add_driver(vector<Driver>&drivers);
   void edit_driver(vector<Driver>&drivers,int driver_id);
   void delete_driver(vector<Driver>&drivers,int driver_id);
   bool search_driver(vector<Driver>&drivers,int ddriver_id);
   void print(vector<Driver>&drivers);
   void menu();

   
   


    private:
    vector<Driver>drivers;


};


#endif 