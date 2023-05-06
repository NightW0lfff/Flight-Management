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

    virtual bool isInternational() const = 0;

    bool addPassenger(const Passenger &p)
    {
        // if the passenger is going on the international flight, check if the passenger has a passport number
        if (isInternational())
        {
            if (p.getPassportNo().empty())
            {
                std::cout << "Passenger " << p.getName() << " cannot be added to the flight "
                          << flightNumber << " because the passenger does not have a passport number."
                          << std::endl;

                std::cout << "This is an international flight." << std::endl;
                std::cout << std::endl;

                return false;
            }
        }

        passengers.push_back(p);
        double tickCost = calculateTicketCost();
        std::cout << tickCost << std::endl;
        // Passenger passengerRef = passengers.back();
        passengers.back().addAmountOwed(tickCost);
        // passengerRef.addAmountOwed(tickCost);
        // p.addAmountOwed(tickCost, passengerRef);
        return true;
    }

    bool removePassenger(const Passenger &p)
    {
        for (auto it = passengers.begin(); it != passengers.end(); ++it)
        {
            if (it->getName() == p.getName())
            {
                passengers.erase(it);
                double tickCost = calculateTicketCost();
                // p.removeAmountOwed(tickCost);
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

    virtual double calculateTicketCost() const = 0;

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
                   std::string departureTime, std::string arrivalTime, double baseFare = 0.0)
        : Flight(flightNumber, origin, destination, departureTime, arrivalTime), baseFare(baseFare) {}

    void applyDomesticDiscount(double discount)
    {
        domesticDiscount = discount;
    }

    double calculateTicketCost() const override
    {
        std::cout << "Base Fare: " << baseFare << std::endl;
        return baseFare - domesticDiscount;
    }

    bool isInternational() const override
    {
        return false;
    }

    // double getBaseFare() const
    // {
    //     std::cout << "Base Fare: " << baseFare << std::endl;
    //     return baseFare;
    // }

private:
    double domesticDiscount = 50.0;
    double baseFare;
};

class InternationalFlight : public Flight
{
public:
    InternationalFlight(std::string flightNumber, std::string origin, std::string destination,
                        std::string departureTime, std::string arrivalTime, double baseFare = 0.0)
        : Flight(flightNumber, origin, destination, departureTime, arrivalTime), baseFare(baseFare) {}

    void applyInternationalSurcharge(double surcharge)
    {
        internationalSurcharge = surcharge;
    }

    double calculateTicketCost() const override
    {
        return baseFare + internationalSurcharge;
    }

    bool isInternational() const override
    {
        return true;
    }

    // double getBaseFare() const
    // {
    //     std::cout << "Base Fare: " << baseFare << std::endl;
    //     return baseFare;
    // }

private:
    double internationalSurcharge = 100.0;
    double baseFare;
};

#endif
