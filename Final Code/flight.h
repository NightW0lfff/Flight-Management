#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include <iostream>
#include "passenger.h"
#include "domestic.h"
#include "international.h"


class Flight {
public:
    Flight(std::string flightNumber, std::string origin, std::string destination,
           std::string departureTime, std::string arrivalTime)
        : flightNumber(flightNumber), origin(origin), destination(destination),
          departureTime(departureTime), arrivalTime(arrivalTime) {}

    void displayFlightDetails() const {
        std::cout << "Flight Number: " << flightNumber << ", Origin: " << origin
                  << ", Destination: " << destination << ", Departure Time: " << departureTime
                  << ", Arrival Time: " << arrivalTime << std::endl;

    }

    bool addPassenger(const Passenger &p) {
        passengers.push_back(p);
        return true;
    }

    bool removePassenger(const Passenger &p) {
        for (auto it = passengers.begin(); it != passengers.end(); ++it) {
            if (it->getName() == p.getName()) {
                passengers.erase(it);
                return true;
            }
        }
        return false;
    }

    void displayPassengerDetails() const {
        for (const auto &p : passengers) {
            p.displayPassengerDetails();
        }
    }

    virtual double calculateTicketCost(const Passenger &p) const = 0;

private:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    std::vector<Passenger> passengers;
};

#endif
