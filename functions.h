#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void print_menu();
void driver_menu();
void passenger_menu();
void ride_menu();


void check_file_opened(const string& filename, const std::ios_base::openmode& mode);


#endif