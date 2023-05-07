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
  BookingSystem(std::vector<Flight *> flights, std::vector<Booking *> bookings, Passenger *passenger)
      : flights(flights), bookings(bookings), passenger(passenger) {}

  bool createBooking() override
  {
    displayAvailableFlights();

    std::string flightNumber;
    std::cout << std::endl;
    std::cout << "Enter flight number: ";
    std::cin >> flightNumber;

    Flight *flight = nullptr;
    for (Flight *f : flights)
    {
      if (f->getFlightNo() == flightNumber)
      {
        flight = f;
        break;
      }
    }

    std::string bookingRef = "B" + std::to_string(bookings.size() + 1);

    Booking *booking = new Booking(bookingRef);

    if (booking->createBooking(flight, passenger))
    {
      std::cout << "Booking successful!" << std::endl;
      bookings.push_back(booking);
      upgradePassengerStatus();
    }
    else
    {
      std::cout << "Booking failed!" << std::endl;
      return false;
    }
    return true;
  }

  bool cancelBooking() override
  {
    displayBookingDetails();

    std::string bookingRef;
    std::cout << "Enter booking reference number: ";
    std::cin >> bookingRef;

    for (auto booking = bookings.begin(); booking != bookings.end(); ++booking)
    {
      if ((*booking)->getBookingReferenceNumber() == bookingRef)
      {
        (*booking)->cancelBooking();
        bookings.erase(booking);
        return true;
      }
    }
    return false;
  }

  bool updateBooking() override
  {
    displayBookingDetails();

    std::string bookingRef;
    std::cout << std::endl;
    std::cout << "Enter booking reference number: ";
    std::cin >> bookingRef;
    std::cout << std::endl;

    Booking *booking = nullptr;
    for (Booking *b : bookings)
    {
      if (b->getBookingReferenceNumber() == bookingRef)
      {
        booking = b;
        break;
      }
    }

    displayAvailableFlights();

    std::string flightNumber;
    std::cout << std::endl;
    std::cout << "Enter flight number: ";
    std::cin >> flightNumber;
    std::cout << std::endl;

    Flight *flight = nullptr;
    for (Flight *f : flights)
    {
      if (f->getFlightNo() == flightNumber)
      {
        flight = f;
        break;
      }
    }

    return booking->updateBooking(flight);
  }

  void upgradePassengerStatus()
  {
    // check if passenger is eligible for upgrade by checking their bookings
    if (bookings.size() >= 1 && bookings.size() < 2)
    {
      passenger->setStatus("SILVER");
      std::cout << "Passenger upgraded to SILVER status" << std::endl;
    }
    else if (bookings.size() >= 2 && bookings.size() < 3)
    {
      std::cout << "Passenger upgraded to GOLD status" << std::endl;
      passenger->setStatus("GOLD");
    }
    else if (bookings.size() >= 3 && bookings.size() < 4)
    {
      std::cout << "Passenger upgraded to PLATINUM status" << std::endl;
      passenger->setStatus("PLATINUM");
    }
  }

  void displayAvailableFlights() override
  {

    // Display available Domestic flights
    std::cout << "Available Domestic Flights: " << std::endl;
    for (Flight *flight : flights)
    {
      if (typeid(*flight) == typeid(DomesticFlight))
      {
        if (flight->isInFlight(passenger))
        {
          flight->displayFlightDetails();
        }
        else
        {
          continue;
        }
      }
    }

    // Display available International flights
    std::cout << "Available International Flights: " << std::endl;
    for (Flight *flight : flights)
    {
      if (typeid(*flight) == typeid(InternationalFlight))
      {
        if (flight->isInFlight(passenger))
        {
          flight->displayFlightDetails();
        }
        else
        {
          continue;
        }
      }
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
  Passenger *passenger;
};

#endif
