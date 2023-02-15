// Question: Create a structure VehicleProduction containing fields:

struct VehicleProduction
{
   string manufacturer;
   string country;
   int vehicles;
};




// Question 2. Write a function print_vehicle_production matching the below usage. The structure has beed defined by your teacher - do not redefine it.
void print_vehicle_production(const VehicleProduction &vehicle_production){
  cout<<"Manufacturer: "<<vehicle_production.manufacturer<<endl;
  cout<<"Country: "<<vehicle_production.country<<endl;
  cout<<"Vehicles: "<<vehicle_production.vehicles<<endl;
}


//Question 3.Write a function which will initialise VehicleProduction matching the below output. The structure and printing function has beed defined by your teacher - do not redefine it.
VehicleProduction initialise_vehicle_production(){
    VehicleProduction p1;
    cout<<"Enter manufacturer:"<<endl;
    cin>>p1.manufacturer;
    cout<<"Enter country:"<<endl;
    cin>>p1.country;
    cout<<"Enter number of vehicles:"<<endl;
    cin>>p1.vehicles;
    return p1;
}


//Question 4.  Here your task is to write a program with main() function. Use given load_vehicle_productions function to read the data from given file. Store it in a std::vector of VehicleProduction objects.
//Filename is uploaded on server under name: cars_manufacturers.csv
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

struct VehicleProduction
{
    std::string manufacturer;
    std::string country;
    int vehicles;
};

std::vector<VehicleProduction> load_vehicle_productions(std::string filename, char separator = ';'){
    std::vector<VehicleProduction> vehicle_productions;
    std::fstream file(filename,std::ios::in);
    if(file.is_open()){
        std::string line;
        while (getline(file,line)) {
            std::stringstream ss(line); // to parse line in getline
            VehicleProduction vehicle_production;
            std::string reading_string;
            getline(ss,reading_string,separator);
            vehicle_production.manufacturer = reading_string;
            getline(ss,reading_string,separator);
            vehicle_production.country = reading_string;
            getline(ss,reading_string,separator);
            vehicle_production.vehicles = std::stoi(reading_string);
            vehicle_productions.emplace_back(vehicle_production);
        }

        file.close();
    }
    return vehicle_productions;
}



//Question 5.


int main(){
    
    std::vector<VehicleProduction> vehicle_productions = load_vehicle_productions("cars_manufacturers.csv");// Use function load_vehicle_productions here
    std::cout << "Number of readings: " << vehicle_productions.size() << std::endl;
    return 0;
}


void print_vector_vehicle_productions(const std::vector<VehicleProduction> &value){
   for(auto i :value){
       print_vehicle_production(i);
   }
}


//Question 6.Using std::max_element find a manufacturer with the largest producted vehicles. Print the number of produced vehicles and the company name.
bool compare_cars_produced(const VehicleProduction &a1,const VehicleProduction &a2){
    return a1.vehicles<a2.vehicles;
} 
    
void print_largest_production(const std::vector<VehicleProduction>& vehicle_productions){
    auto max_el = std::max_element(vehicle_productions.begin(),vehicle_productions.end(),compare_cars_produced);
    std::cout << "Largest production company: " << max_el->manufacturer << " : " << max_el->vehicles << std::endl;
}



//Question: 7.Using std::min_element find a manufacturer with the smallest amount of producted vehicles. Print the number of produced vehicles and the company name.
bool compare_cars_produced(const VehicleProduction &a1,const VehicleProduction &a2){
     return a1.vehicles<a2.vehicles;
} 


void print_smallest_production(const std::vector<VehicleProduction>& vehicle_productions){
    auto min_el =  std::min_element(vehicle_productions.begin(),vehicle_productions.end(),compare_cars_produced);//Code here...
    std::cout << "Smallest production company: " << min_el->manufacturer << " : " << min_el->vehicles << std::endl;
}




