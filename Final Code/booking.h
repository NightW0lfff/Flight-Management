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
  Booking(std::string bookingReferenceNumber, Flight *flight, const Passenger &passenger)
      : bookingReferenceNumber(bookingReferenceNumber), flight(flight), passenger(passenger) {}

  bool createBooking(Flight *flight, const Passenger &passenger)
  {
    return flight->addPassenger(passenger);
  }

  bool cancelBooking(Flight *flight, const Passenger &passenger)
  {
    return flight->removePassenger(passenger);
  }

  bool updateBooking(std::vector<Flight *> &flights, Flight *updatedFlight, const Passenger &passenger)
  {
    for (auto &flight : flights)
    {
      if (flight->getFlightNo() == updatedFlight->getFlightNo())
      {
        flight = updatedFlight;
        return true;
      }
    }
    return false;
  }

  void displayBookingDetails() const
  {
    std::cout << "Booking Reference Number: " << bookingReferenceNumber << std::endl;
    flight->displayFlightDetails();
    passenger.displayPassengerDetails();
  }

private:
  std::string bookingReferenceNumber;
  Flight *flight;
  Passenger passenger;
};

#endif