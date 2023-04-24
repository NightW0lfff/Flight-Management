#ifndef FLIGHT_BOOKING_SYSTEM_H
#define FLIGHT_BOOKING_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>
#include "booking.h"
#include "flight.h"

class FlightBookingSystem
{
public:
  FlightBookingSystem(std::vector<Flight> &flights, std::vector<Booking> &bookings)
      : flights(flights), bookings(bookings) {}

  // bool createBooking(Flight &flight, const Passenger &passenger)
  // {
  //   return flight.addPassenger(passenger);
  // }

  // bool cancelBooking(Flight &flight, const Passenger &passenger)
  // {
  //   return flight.removePassenger(passenger);
  // }

  // bool updateBooking(Flight *flight, const Passenger &passenger)
  // {
  //   for (auto &flight : flights)
  //   {
  //     if (flight.getFlightNumber() == flight->getFlightNumber())
  //     {
  //       flight = *flight;
  //       return true;
  //     }
  //   }
  //   return false;
  // }

  void displayBookingDetails() const
  {
    for (const auto &booking : bookings)
    {
      booking.displayBookingDetails();
    }
  }

  void displayFlightDetails() const
  {
    for (const auto &flight : flights)
    {
      flight.displayFlightDetails();
    }
  }

  void displayAvailableFlights() const
  {
    for (const auto &flight : flights)
    {
      flight.displayFlightDetails();
    }
  }

private:
  std::vector<Flight> &flights;
  std::vector<Booking> &bookings;
};

#endif
