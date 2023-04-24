#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include <iostream>
#include "passenger.h"
#include "domestic.h"
#include "international.h"

class Flight
{
public:
    Flight(std::string flightNumber, std::string origin, std::string destination,
           std::string departureTime, std::string arrivalTime)
        : flightNumber(flightNumber), origin(origin), destination(destination),
          departureTime(departureTime), arrivalTime(arrivalTime) {}

    void displayFlightDetails() const
    {
        std::cout << "Flight Number: " << flightNumber << ", Origin: " << origin
                  << ", Destination: " << destination << ", Departure Time: " << departureTime
                  << ", Arrival Time: " << arrivalTime << std::endl;
    }

    bool addPassenger(const Passenger &p)
    {
        // if (p.getPassportNo() != "")
        // {
        //     std::cout << "Passport number is not empty. This is a domestic flight. Cannot add passenger." << std::endl;
        //     return false;
        // }
        // else
        // {
        //     std::cout << "Passport number is empty. This is an international flight. Cannot add passenger." << std::endl;
        //     return false;
        // }
        std::cout << "Passenger added." << std::endl;
        passengers.push_back(p);
        return true;
    }

    bool removePassenger(const Passenger &p)
    {
        for (auto it = passengers.begin(); it != passengers.end(); ++it)
        {
            if (it->getName() == p.getName())
            {
                std::cout << "Passenger removed." << std::endl;
                passengers.erase(it);
                return true;
            }
        }
        return false;
    }

    void displayPassengerDetails() const
    {
        for (const auto &p : passengers)
        {
            p.displayPassengerDetails();
        }
    }

    std::string getFlightNo() const
    {
        return flightNumber;
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

class DomesticFlight : public Flight
{
public:
    using Flight::Flight;

    void applyDomesticDiscount(double discount)
    {
        domesticDiscount = discount;
    }

    double calculateTicketCost(const Passenger &p) const override
    {
        return 1000 - domesticDiscount;
    }

private:
    double domesticDiscount;
};

class InternationalFlight : public Flight
{
public:
    using Flight::Flight;

    void applyInternationalSurcharge(double surcharge)
    {
        internationalSurcharge = surcharge;
    }

    double calculateTicketCost(const Passenger &p) const override
    {
        return 1000 + internationalSurcharge;
    }

private:
    double internationalSurcharge;
};

#endif
