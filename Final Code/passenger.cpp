#include <iostream>
#include <vector>
#include <string>
#include "passenger.h"
#include "flight.h"
#include "booking.h"

int main()
{

    std::vector<Flight *> flights;
    flights.push_back(new DomesticFlight("F1", "New York", "Los Angeles", "09:00", "14:00"));
    flights.push_back(new InternationalFlight("F2", "New York", "London", "19:00", "07:00"));

    // Create passengers
    Passenger passenger1("John Doe", 35, "1234567890");
    Passenger passenger2("Jane Doe", 29, "0987654321");
    Passenger passenger3("John Smith", 45, "1234567890");

    // Bookings
    std::vector<Booking *> bookings;
    bookings.emplace_back(new Booking("B1", flights[0], passenger1));
    // Booking booking1("B1", flights[0], passenger1);
    // Booking booking2("B2", flights[1], passenger2);

    // Cancel booking
    // booking1.cancelBooking(flights[0], passenger1);

    // Create Booking
    bookings[0]->createBooking(flights[0], passenger1);

    // Update booking
    bookings[0]->updateBooking(flights, flights[0], passenger1);

    // Display booking details
    // booking1.displayBookingDetails();
    // booking2.displayBookingDetails();

    // booking2.createBooking("B2", &flight2, passenger2);

    // Add passengers to flights
    // flight1.addPassenger(passenger1);
    // flight2.addPassenger(passenger2);
    // flight1.addPassenger(passenger3);
    // flight1.removePassenger(passenger3);

    // Display flight details
    // flights[0]->displayFlightDetails();
    // flights[1].displayFlightDetails();

    flights[0]->displayPassengerDetails();
    // flight2.displayPassengerDetails();

    // Display passenger details
    // std::cout << "Passengers on flight F1:" << std::endl;
    // passenger1.displayPassengerDetails();

    // std::cout << "Passengers on flight F2:" << std::endl;
    // passenger2.displayPassengerDetails();

    return 0;
}