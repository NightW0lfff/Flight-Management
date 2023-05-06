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

    std::string passengerName, passengerContact, passengerAge, passengerPassport;
    std::cout << std::endl;

    std::cout << "Enter passenger name: ";
    std::cin.ignore();
    std::getline(std::cin, passengerName);

    std::cout << "Enter passenger contact number: ";
    std::cin.ignore();
    std::getline(std::cin, passengerContact);

    std::cout << "Enter passenger age: ";
    std::getline(std::cin, passengerAge);

    std::cout << "Enter passenger PassportNumber (press enter to skip): ";
    std::getline(std::cin, passengerPassport);

    std::cout << std::endl;

    if (passengerPassport.empty())
    {
      passengerPassport = "";
    }

    Passenger passenger(passengerName, std::stoi(passengerAge), passengerContact, passengerPassport);

    std::string bookingRef = "B" + std::to_string(bookings.size() + 1);

    Booking *booking = new Booking(bookingRef, flight, passenger);
    bookings.push_back(booking);

    return booking->createBooking(flight, passenger);
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

  void displayAvailableFlights() override
  {

    // Display available Domestic flights
    std::cout << "Available Domestic Flights: " << std::endl;
    for (Flight *flight : flights)
    {
      if (typeid(*flight) == typeid(DomesticFlight))
      {
        flight->displayFlightDetails();
      }
    }

    // Display available International flights
    std::cout << "Available International Flights: " << std::endl;
    for (Flight *flight : flights)
    {
      if (typeid(*flight) == typeid(InternationalFlight))
      {
        flight->displayFlightDetails();
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
};

#endif
