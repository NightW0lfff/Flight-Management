#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include <iostream>
#include "passenger.h"

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
        std::cout << std::endl;
    }

    bool addPassenger(const Passenger &p)
    {
        passengers.push_back(p);
        return true;
    }

    bool removePassenger(const Passenger &p)
    {
        for (auto it = passengers.begin(); it != passengers.end(); ++it)
        {
            if (it->getName() == p.getName())
            {
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

    std::vector<Passenger> getPassengers() const
    {
        return passengers;
    }

    virtual double calculateTicketCost(const Passenger &p) const = 0;

protected:
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
    DomesticFlight(std::string flightNumber, std::string origin, std::string destination,
                   std::string departureTime, std::string arrivalTime, double domesticDiscount = 0)
        : Flight(flightNumber, origin, destination, departureTime, arrivalTime),
          domesticDiscount(domesticDiscount) {}

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
    InternationalFlight(std::string flightNumber, std::string origin, std::string destination,
                        std::string departureTime, std::string arrivalTime, double internationalSurcharge)
        : Flight(flightNumber, origin, destination, departureTime, arrivalTime), internationalSurcharge(internationalSurcharge) {}

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
