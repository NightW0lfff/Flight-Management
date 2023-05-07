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
  Booking(std::string bookingReferenceNumber)
      : bookingReferenceNumber(bookingReferenceNumber) {}

  bool createBooking(Flight *flight, Passenger *passenger)
  {
    this->flight = flight;
    this->passenger = passenger;

    // check if passenger able to go on international flight
    if (!isAbleToGoOnInternationalFlight(flight, passenger))
    {
      return false;
    }

    return flight->addPassenger(passenger);
  }

  bool cancelBooking()
  {
    return this->flight->removePassenger(this->passenger);
  }

  bool updateBooking(Flight *updatedFlight)
  {
    std::vector<Passenger *> passengers = flight->getPassengers();

    // check if passenger able to go on international flight
    if (!isAbleToGoOnInternationalFlight(updatedFlight, passenger))
    {
      return false;
    }

    std::cout << "Warning" << std::endl;

    for (auto *p : passengers)
    {
      if (p->getName() == passenger->getName())
      {
        flight->removePassenger(p);
      }
    }
    updatedFlight->addPassenger(passenger);
    this->flight = updatedFlight;
    return true;
  }

  // void updatePassenger()
  // {
  //   std::string name;
  //   std::string passportNo;
  //   std::string address;
  //   std::string phoneNumber;
  //   std::string email;

  //   bool exit = false;
  //   while (!exit)
  //   {
  //     std::cout << "1. Name" << std::endl;
  //     std::cout << "2. Contact Number" << std::endl;
  //     std::cout << "3. Age" << std::endl;
  //     std::cout << "4. Passport Number" << std::endl;
  //     std::cout << "5. Exit" << std::endl;
  //     std::cout << std::endl;
  //     std::cout << "Enter your choice: ";
  //     int choice;
  //     std::cin >> choice;

  //     switch (choice)
  //     {
  //     case 1:
  //       std::cout << "Enter new name: ";
  //       std::cin.ignore();
  //       std::getline(std::cin, name);
  //       passenger->setName(name);
  //       break;
  //     case 2:
  //       std::cout << "Enter new contact number: ";
  //       std::cin.ignore();
  //       std::getline(std::cin, phoneNumber);
  //       passenger->setContactInfo(phoneNumber);
  //       break;
  //     case 3:
  //       std::cout << "Enter new age: ";
  //       int age;
  //       std::cin >> age;
  //       passenger->setAge(age);
  //       break;
  //     case 4:
  //       std::cout << "Enter new passport number: ";
  //       std::cin.ignore();
  //       std::getline(std::cin, passportNo);
  //       passenger->setPassportNo(passportNo);
  //       break;
  //     case 5:
  //       exit = true;
  //       break;
  //     default:
  //       std::cout << "Invalid choice." << std::endl;
  //       break;
  //     }
  //   }
  // }

  // check if passenger able to go on international flight
  bool isAbleToGoOnInternationalFlight(Flight *flight, Passenger *passenger)
  {
    if (flight->isInternational())
    {
      if (passenger->getPassportNo().empty())
      {
        std::cout << std::endl;
        std::cout << "Passenger " << passenger->getName() << " cannot be added to the flight "
                  << flight->getFlightNo()
                  << " because the passenger does not have a passport number."
                  << std::endl;

        std::cout << "This is an international flight." << std::endl;
        std::cout << std::endl;

        std::cout << "Do you want to add a passport number? (y/n): ";
        std::string choice;
        std::cin >> choice;

        // add passport number
        if (choice == "y" || choice == "Y")
        {
          std::cout << "Enter passport number: ";
          std::string passportNo;
          std::cin.ignore();
          std::getline(std::cin, passportNo);
          passenger->setPassportNo(passportNo);
        }
        else
        {
          std::cout << "Passenger " << passenger->getName()
                    << " cannot be added to the flight " << flight->getFlightNo()
                    << " because the passenger does not have a passport number."
                    << std::endl;

          std::cout << "This is an international flight." << std::endl;
          std::cout << std::endl;
          return false;
        }
      }
    }
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
    std::cout << std::endl;
  }

  Flight *getFlight() const
  {
    return flight;
  }

private:
  std::string bookingReferenceNumber;
  Flight *flight;
  Passenger *passenger;
};

#endif