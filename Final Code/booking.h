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

  bool createBooking()
  {
    return flight->addPassenger(passenger);
  }

  bool cancelBooking()
  {
    return flight->removePassenger(passenger);
  }

  void updateBooking(Flight *flight)
  {
    this->flight = flight;
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