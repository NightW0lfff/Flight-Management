#ifndef DOMESTIC_H
#define DOMESTIC_H

#include <iostream>
#include <vector>
#include <string>
#include "flight.h"

class DomesticFlight : public Flight {
public:
    DomesticFlight(std::string flightNumber, std::string origin, std::string destination,
                   std::string departureTime, std::string arrivalTime)
        : Flight(flightNumber, origin, destination, departureTime, arrivalTime) {}
        //  , domesticDiscount(domesticDiscount) {}

    void applyDomesticDiscount(double discount) {
        domesticDiscount = discount;
    }

    double calculateTicketCost(const Passenger &p) const override {
        return 1000 - domesticDiscount;
    }

private:
    double domesticDiscount = 100;
};

#endif
