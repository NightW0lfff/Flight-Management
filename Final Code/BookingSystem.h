#ifndef FLIGHT_BOOKING_SYSTEM_H
#define FLIGHT_BOOKING_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>
#include "booking.h"
#include "flight.h"
#include "IBookingSystem.h"

class BookingSystem : public IBookingSystem
{
public:
  BookingSystem(std::vector<Flight *> flights, std::vector<Booking *> bookings)
      : flights(flights), bookings(bookings) {}

  // bool createBooking() override
  // {
  //   booking.createBooking(flight, passenger);
  //   return true;
  // }

  // bool cancelBooking() override
  // {
  //   booking.cancelBooking();
  //   return true;
  // }

  // bool updateBooking() override
  // {
  //   booking.updateBooking(flight);
  //   return true;
  // }

  void displayAvailableFlights() override
  {
    for (Flight *flight : flights)
    {
      flight->displayFlightDetails();
    }
  }

  void displayBookingDetails() override
  {
    for (auto &booking : bookings)
    {
      booking->displayBookingDetails();
    }
  }

  void displayFlightDetails() override
  {
    for (auto &flight : flights)
    {
      flight->displayFlightDetails();
    }
  }

private:
  std::vector<Flight *> flights;
  std::vector<Booking *> bookings;
};

#endif
