#ifndef IBOOKING_SYSTEM_H
#define IBOOKING_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>

class IBookingSystem
{
  // virtual bool createBooking();
  // virtual bool cancelBooking();
  // virtual bool updateBooking();
  virtual void displayAvailableFlights() = 0;
  virtual void displayFlightDetails() = 0;
  virtual void displayBookingDetails() = 0;
  virtual ~IBookingSystem() {}
};

#endif