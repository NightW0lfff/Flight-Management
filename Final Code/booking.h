#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>
#include <iostream>
#include "passenger.h"
#include "flight.h"

class Booking
{
public:
  Booking(std::string bookingReferenceNumber, Flight *flight, Passenger &passenger)
      : bookingReferenceNumber(bookingReferenceNumber), flight(flight), passenger(passenger) {}

  bool createBooking(Flight *flight, Passenger &passenger)
  {
    return flight->addPassenger(passenger);
  }

  bool cancelBooking()
  {
    return this->flight->removePassenger(this->passenger);
  }

  bool updateBooking(Flight *updatedFlight)
  {
    std::vector<Passenger> passengers = this->flight->getPassengers();

    Flight *flight = this->flight;
    Passenger &passenger = this->passenger;

    for (auto &p : passengers)
    {
      if (p.getName() == passenger.getName())
      {
        flight->removePassenger(p);
      }
    }
    updatedFlight->addPassenger(passenger);
    this->flight = updatedFlight;
    return true;
  }

  std::string getBookingReferenceNumber()
  {
    return bookingReferenceNumber;
  }

  void displayBookingDetails() const
  {
    std::cout << "Booking Reference Number: " << bookingReferenceNumber << std::endl;
    flight->displayFlightDetails();
    passenger.displayPassengerDetails();
    std::cout << std::endl;
  }

private:
  std::string bookingReferenceNumber;
  Flight *flight;
  Passenger passenger;
};

#endif