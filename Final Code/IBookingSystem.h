#ifndef IBOOKING_SYSTEM_H
#define IBOOKING_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>

class IBookingSystem
{
public:
  virtual bool createBooking() = 0;
  virtual bool cancelBooking() = 0;
  virtual bool updateBooking() = 0;
  virtual void displayAvailableFlights() = 0;
  virtual void displayFlightDetails() = 0;
  virtual void displayBookingDetails() = 0;
};

#endif