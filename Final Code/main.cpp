#include <iostream>
#include <vector>
#include "BookingSystem.h"
#include "IBookingSystem.h"

int main()
{

  // Create flights
  std::vector<Flight *> flights;
  flights.push_back(new DomesticFlight("F1", "New York", "Los Angeles", "09:00", "14:00", 500));
  flights.push_back(new InternationalFlight("F2", "New York", "London", "19:00", "07:00", 500));

  // Create passengers
  Passenger passenger1("John Doe", 35, "1234567890", "c123123");
  Passenger passenger2("Jane Doe", 29, "0987654321", "c321321");
  Passenger passenger3("John Smith", 45, "1234567890", "c123123");

  // Bookings
  std::vector<Booking *> bookings;
  bookings.emplace_back(new Booking("B1", flights[0], passenger1));
  bookings.emplace_back(new Booking("B2", flights[1], passenger2));

  IBookingSystem *bookingSys = new BookingSystem(flights, bookings);

  bool exit = false;
  while (!exit)
  {
    std::cout << "1. Create Booking" << std::endl;
    std::cout << "2. Cancel Booking" << std::endl;
    std::cout << "3. Update Booking" << std::endl;
    std::cout << "4. Display Booking Details" << std::endl;
    std::cout << "5. Display Flight Details" << std::endl;
    std::cout << "6. Display Available Flights" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice)
    {
    case 1:
      bookingSys->createBooking();
      break;
    case 2:
      bookingSys->cancelBooking();
      break;
    case 3:
      bookingSys->updateBooking();
      break;
    case 4:
      bookingSys->displayBookingDetails();
      break;
    case 5:
      bookingSys->displayFlightDetails();
      break;
    case 6:
      bookingSys->displayAvailableFlights();
      break;
    case 7:
      exit = true;
      break;
    default:
      std::cout << "Invalid choice" << std::endl;
    }
  }

  // bookingSys->displayAvailableFlights();
  // bookingSys->displayBookingDetails();
  // bookingSys->displayFlightDetails();

  // bookingSys->createBooking();
  // bookingSys->displayBookingDetails();
  // bookingSys->cancelBooking();

  // bookingSys->updateBooking();

  // bookingSys->displayBookingDetails();
  return 0;
}
