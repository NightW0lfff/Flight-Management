#include <iostream>
#include <vector>
#include <string>
#include "passenger.h"
#include "flight.h"

// class Passenger {
// public:
//     Passenger(std::string name, int age, std::string contactInfo, std::string passportNo = "")
//         : name(name), age(age), contactInfo(contactInfo), passportNo(passportNo) {}

//     void displayPassengerDetails() const {
//         std::cout << "Name: " << name << ", Age: " << age << ", Contact Info: " << contactInfo;
//         if (!passportNo.empty()) {
//             std::cout << ", Passport No: " << passportNo;
//         }
//         std::cout << std::endl;
//     }

//     std::string getName() const {
//         return name;
//     }

// private:
//     std::string name;
//     int age;
//     std::string contactInfo;
//     std::string passportNo;
// };

// class Flight {
// public:
//     Flight(std::string flightNumber, std::string origin, std::string destination,
//            std::string departureTime, std::string arrivalTime)
//         : flightNumber(flightNumber), origin(origin), destination(destination),
//           departureTime(departureTime), arrivalTime(arrivalTime) {}

//     void displayFlightDetails() const {
//         std::cout << "Flight Number: " << flightNumber << ", Origin: " << origin
//                   << ", Destination: " << destination << ", Departure Time: " << departureTime
//                   << ", Arrival Time: " << arrivalTime << std::endl;

//     }

//     bool addPassenger(const Passenger &p) {
//         passengers.push_back(p);
//         return true;
//     }

//     bool removePassenger(const Passenger &p) {
//         for (auto it = passengers.begin(); it != passengers.end(); ++it) {
//             if (it->getName() == p.getName()) {
//                 passengers.erase(it);
//                 return true;
//             }
//         }
//         return false;
//     }

//     void displayPassengerDetails() const {
//         for (const auto &p : passengers) {
//             p.displayPassengerDetails();
//         }
//     }

//     virtual double calculateTicketCost(const Passenger &p) const = 0;

// private:
//     std::string flightNumber;
//     std::string origin;
//     std::string destination;
//     std::string departureTime;
//     std::string arrivalTime;
//     std::vector<Passenger> passengers;
// };

// class DomesticFlight : public Flight {
// public:
//     DomesticFlight(std::string flightNumber, std::string origin, std::string destination,
//                    std::string departureTime, std::string arrivalTime)
//         : Flight(flightNumber, origin, destination, departureTime, arrivalTime) {}
//         //  , domesticDiscount(domesticDiscount) {}

//     void applyDomesticDiscount(double discount) {
//         domesticDiscount = discount;
//     }

//     double calculateTicketCost(const Passenger &p) const override {
//         return 1000 - domesticDiscount;
//     }

// private:
//     double domesticDiscount = 100;
// };

// class InternationalFlight : public Flight {
// public:
//     InternationalFlight(std::string flightNumber, std::string origin, std::string destination,
//                         std::string departureTime, std::string arrivalTime)
//         : Flight(flightNumber, origin, destination, departureTime, arrivalTime) {}
//         //   ,internationalSurcharge(internationalSurcharge) {}

//     void applyInternationalSurcharge(double surcharge) {
//         internationalSurcharge = surcharge;
//     }

//     double calculateTicketCost(const Passenger &p) const override {
//         return 1000 + internationalSurcharge;
//     }

// private:
//     double internationalSurcharge;
// };

class Booking
{
public:
    Booking(std::string bookingReferenceNumber, Flight *flight, const Passenger &passenger)
        : bookingReferenceNumber(bookingReferenceNumber), flight(flight), passenger(passenger) {}

    bool createBooking()
    {
        return flight->addPassenger(passenger);
    }

    bool cancelBooking()
    {
        return flight->removePassenger(passenger);
    }

    void updateBooking(Flight *flight)
    {
        this->flight = flight;
    }

    void displayBookingDetails() const
    {
        std::cout << "Booking Reference Number: " << bookingReferenceNumber << std::endl;
        flight->displayFlightDetails();
        passenger.displayPassengerDetails();
    }

private:
    std::string bookingReferenceNumber;
    Flight *flight;
    Passenger passenger;
};

int main()
{
    // Create flights
    DomesticFlight flight1("F1", "New York", "Los Angeles", "09:00", "14:00");
    InternationalFlight flight2("F2", "New York", "London", "19:00", "07:00");

    // Create passengers
    Passenger passenger1("John Doe", 35, "1234567890");
    Passenger passenger2("Jane Doe", 29, "0987654321");
    Passenger passenger3("John Smith", 45, "1234567890");

    // Bookings
    Booking booking1("B1", &flight1, passenger1);
    Booking booking2("B2", &flight1, passenger2);

    // Display booking details
    // booking1.displayBookingDetails();
    // booking2.displayBookingDetails();

    // Add passengers to flights
    flight1.addPassenger(passenger1);
    flight2.addPassenger(passenger2);
    flight2.addPassenger(passenger3);
    // flight2.removePassenger(passenger3);

    // Display flight details
    // flight1.displayFlightDetails();
    // flight2.displayFlightDetails();

    // flight2.displayPassengerDetails();

    // Display passenger details
    // std::cout << "Passengers on flight F1:" << std::endl;
    // passenger1.displayPassengerDetails();

    // std::cout << "Passengers on flight F2:" << std::endl;
    // passenger2.displayPassengerDetails();

    return 0;
}