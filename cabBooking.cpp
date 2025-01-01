/*Rent a Ride”  As a customer to Rent a Ride you book a cab. 
We charge you as per the distance covered. We charge 8rs/km. 
The moment you click the button to RIDE, we search for the nearby drivers 
who will accept your ride. Suppose there are 15 drivers near your location,
 then we send the request to the first driver who is closest to you, then the second, and so on.
  There are a few conditions though, based on which we can not send the request to the nearby driver.
Condition 1: If the driver rating is lower than 4. (out of 5)
Condition 2: If you selected a specific car, 
and that car driver is not the closest one. 
In case there is no driver present as per your request for the car, 
we will ask you to select some other car. A table was given having drivers, 
cars model, their ratings, and distance from the customer, and using this data we have to provide the 
most appropriate car to the customer, with the calculated fare
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

class Driver {
public:
    std::string name;
    std::string carModel;
    double rating; // Driver's rating
    double distance; // Distance from the customer in km

    Driver(std::string name, std::string carModel, double rating, double distance)
        : name(std::move(name)), carModel(std::move(carModel)), rating(rating), distance(distance) {}
};

class Ride {
private:
    const double costPerKm = 8.0;
    std::vector<Driver> drivers;
    std::string selectedCar;
    double distanceToTravel;

public:
    Ride(std::vector<Driver> drivers, const std::string& selectedCar, double distanceToTravel)
        : drivers(std::move(drivers)), selectedCar(selectedCar), distanceToTravel(distanceToTravel) {}

    void findRide() {
        std::vector<Driver> eligibleDrivers;

        // Filter drivers based on conditions
        for (const auto& driver : drivers) {
            if (driver.rating >= 4.0 && (selectedCar.empty() || driver.carModel == selectedCar)) {
                eligibleDrivers.push_back(driver);
            }
        }

        // If no drivers match the selected car
        if (eligibleDrivers.empty()) {
            std::cout << "No drivers available for the selected car: " << selectedCar << "\n";
            std::cout << "Please select another car or modify your search.\n";
            return;
        }

        // Sort eligible drivers by distance (ascending)
        std::sort(eligibleDrivers.begin(), eligibleDrivers.end(),
                  [](const Driver& a, const Driver& b) { return a.distance < b.distance; });

        // Assign the closest eligible driver
        const Driver& assignedDriver = eligibleDrivers.front();
        double fare = distanceToTravel * costPerKm;

        // Output details
        std::cout << "Ride Assigned:\n";
        std::cout << "Driver Name: " << assignedDriver.name << "\n";
        std::cout << "Car Model: " << assignedDriver.carModel << "\n";
        std::cout << "Driver Rating: " << assignedDriver.rating << "\n";
        std::cout << "Driver Distance: " << assignedDriver.distance << " km\n";
        std::cout << "Total Fare: Rs " << std::fixed << std::setprecision(2) << fare << "\n";
    }
};

int main() {
    // List of drivers
    std::vector<Driver> drivers = {
        Driver("John", "Sedan", 4.5, 2.0),
        Driver("Alice", "SUV", 4.2, 1.5),
        Driver("Bob", "Hatchback", 3.8, 1.2),
        Driver("Tom", "SUV", 4.0, 0.5),
        Driver("Lucy", "Sedan", 4.9, 3.0),
    };

    // Inputs
    std::string selectedCar = "SUV"; // User-selected car model
    double distanceToTravel = 15.0;  // Distance to travel in km

    // Create a Ride object and find the most suitable ride
    Ride ride(drivers, selectedCar, distanceToTravel);
    ride.findRide();

    return 0;
}
};