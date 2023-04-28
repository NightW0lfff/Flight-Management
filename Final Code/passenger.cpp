#include <iostream>
#include <vector>
#include <string>
#include "passenger.h"
#include "flight.h"
#include "booking.h"
#include "BookingSystem.h"

int main()
{

    std::vector<Flight *> flights;
    flights.push_back(new DomesticFlight("F1", "New York", "Los Angeles", "09:00", "14:00"));
    flights.push_back(new InternationalFlight("F2", "New York", "London", "19:00", "07:00"));

    // Create passengers
    Passenger passenger1("John Doe", 35, "1234567890", "c123123");
    Passenger passenger2("Jane Doe", 29, "0987654321", "c321321");
    Passenger passenger3("John Smith", 45, "1234567890", "c123123");

    // Bookings
    std::vector<Booking *> bookings;
    bookings.emplace_back(new Booking("B1", flights[0], passenger1));
    bookings.emplace_back(new Booking("B2", flights[1], passenger2));

    BookingSystem *bookingSys = new BookingSystem(flights, bookings);

    // bookingSys->displayAvailableFlights();
    // bookingSys->displayBookingDetails();
    // bookingSys->displayFlightDetails();

    bookingSys->createBooking();
    // bookingSys->displayBookingDetails();
    // bookingSys->cancelBooking();

    bookingSys->updateBooking();

    bookingSys->displayBookingDetails();

    // bookings[0]->createBooking(flights[0], passenger1);
    // bookings[0]->createBooking(flights[0], passenger2);

    // bookings[0]->updateBooking(flights[1]);

    // bookings[0]->displayBookingDetails();
    // std::cout << std::endl;

    return 0;
}