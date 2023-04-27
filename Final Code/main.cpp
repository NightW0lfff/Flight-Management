#include <iostream>
#include <vector>
#include "BookingSystem.h"

int main()
{

  // Create some flights
  std::vector<Flight *> flights;

  DomesticFlight *flight1 = new DomesticFlight("F1", "New York", "Los Angeles", "09:00", "14:00");
  InternationalFlight *flight2 = new InternationalFlight("F2", "New York", "London", "19:00", "07:00");
  flights.emplace_back(*flight1);
  flights.emplace_back(*flight2);
  // flights.emplace_back("AI206", "DEL", "BLR", "2022-05-02 09:00", "2022-05-02 12:00");

  // Create some bookings
  std::vector<Booking> bookings;
  bookings.emplace_back("BK001", *flights[0], Passenger("John Doe", 35, "1234567890"));
  bookings.emplace_back("BK002", *flights[1], Passenger("Jane Doe", 29, "0987654321"));

  // Create a FlightBookingSystem
  FlightBookingSystem system(flights, bookings);

  // Test createBooking function
  // if (system.createBooking(flights[0], Passenger("Bob Smith", 45, "1234567890")))
  // {
  //   std::cout << "Booking created successfully." << std::endl;
  // }
  // else
  // {
  //   std::cout << "Failed to create booking." << std::endl;
  // }

  // Test cancelBooking function
  // if (system.cancelBooking(flights[0], Passenger("John Doe", 35, "1234567890")))
  // {
  //   std::cout << "Booking canceled successfully." << std::endl;
  // }
  // else
  // {
  //   std::cout << "Failed to cancel booking." << std::endl;
  // }

  // "John Doe", 35, "1234567890"

  // Test updateBooking function
  // Flight *updatedFlight = new Flight("AI202", "DEL", "BOM", "2022-05-01 10:00", "2022-05-01 12:00");
  // updatedFlight->addPassenger(Passenger("Bob Smith", 45, "1234567890"));
  // if (system.updateBooking(updatedFlight, Passenger("John Doe", 35, "1234567890")))
  // {
  //   std::cout << "Booking updated successfully." << std::endl;
  // }
  // else
  // {
  //   std::cout << "Failed to update booking." << std::endl;
  // }
  // delete updatedFlight;

  // Test display functions
  // system.displayFlightDetails();
  // system.displayBookingDetails();
  // system.displayAvailableFlights();

  return 0;
}
