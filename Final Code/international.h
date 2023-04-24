#ifndef INTERNATIONAL_H
#define INTERNATIONAL_H

#include "flight.h"
#include <iostream>
#include <string>
#include <vector>

class InternationalFlight : public Flight
{
public:
  InternationalFlight(std::string flightNumber, std::string origin,
                      std::string destination, std::string departureTime,
                      std::string arrivalTime)
      : Flight(flightNumber, origin, destination, departureTime, arrivalTime) {}
  //   ,internationalSurcharge(internationalSurcharge) {}

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
