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

    std::string getFlightNo() const
    {
        return flightNumber;
    }

    std::vector<Passenger *> getPassengers() const
    {
        return passengers;
    }

    bool addPassenger(Passenger *p)
    {
        // check if passenger is in flight
        if (!isInFlight(p))
        {
            std::cout << "Passenger " << p->getName() << " is already in flight "
                      << flightNumber << std::endl;
            return false;
        }

        // if the passenger is going on the international flight, check if the passenger has a passport number
        if (isInternational())
        {
            if (p->getPassportNo().empty())
            {
                std::cout << "Passenger " << p->getName() << " cannot be added to the flight "
                          << flightNumber << " because the passenger does not have a passport number."
                          << std::endl;

                std::cout << "This is an international flight." << std::endl;
                std::cout << std::endl;

                return false;
            }
        }

        passengers.push_back(p);
        // Passenger *passenger = new VIPPassenger(passenger->getName(), passenger->getAge(), passenger->getContactInfo(), passenger->getPassportNo());

        double ticketCost = calculateTicketCost();
        ticketCost -= (ticketCost * p->getDiscountRate());

        std::cout << std::endl;
        std::cout << "Ticket cost after discount: " << ticketCost << std::endl;

        p->addAmountOwed(ticketCost);
        return true;
    }

    bool removePassenger(Passenger *p)
    {
        for (auto it = passengers.begin(); it != passengers.end(); ++it)
        {
            if ((*it)->getName() == p->getName())
            {
                passengers.erase(it);
                double ticketCost = calculateTicketCost();
                ticketCost += (ticketCost * p->getDiscountRate());
                std::cout << std::endl;
                std::cout << "Ticket cost after discount: " << ticketCost << std::endl;
                p->removeAmountOwed(ticketCost);
                return true;
            }
        }
        return false;
    }

    bool isInFlight(Passenger *p) const
    {
        for (const auto *passenger : passengers)
        {
            if (passenger->getName() == p->getName())
            {
                return false;
            }
        }
        return true;
    }

    void displayPassengerDetails() const
    {
        for (const auto *p : passengers)
        {
            p->displayPassengerDetails();
        }
    }

    void displayFlightDetails() const
    {
        std::cout << "Flight Number: " << flightNumber << ", Origin: " << origin
                  << ", Destination: " << destination << ", Departure Time: " << departureTime
                  << ", Arrival Time: " << arrivalTime << std::endl;
        std::cout << std::endl;
    }

    virtual bool isInternational() const = 0;
    virtual double calculateTicketCost() const = 0;

protected:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    std::vector<Passenger *> passengers;
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
        return baseFare - domesticDiscount;
    }

    bool isInternational() const override
    {
        return false;
    }

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

private:
    double internationalSurcharge = 100.0;
    double baseFare;
};

#endif
