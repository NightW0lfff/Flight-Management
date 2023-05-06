#ifndef PASSANGER_H
#define PASSANGER_H

#include <iostream>
#include <vector>
#include <string>

class Passenger
{
public:
    Passenger(std::string name, int age, std::string contactInfo, std::string passportNo = "", double owedAmount = 0.0)
        : name(name), age(age), contactInfo(contactInfo), passportNo(passportNo), owedAmount(owedAmount) {}

    void displayPassengerDetails() const
    {
        std::cout << "Name: " << name << ", Age: " << age << ", Contact Info: " << contactInfo;
        if (!passportNo.empty())
        {
            std::cout << ", Passport No: " << passportNo;
        }
        std::cout << ", Owed Amount: " << owedAmount << std::endl;
        std::cout << std::endl;
    }

    std::string getPassportNo() const
    {
        return passportNo;
    }

    std::string getName() const
    {
        return name;
    }

    void addAmountOwed(double amount)
    {
        owedAmount += amount;
        // std::cout << "Passenger " << name << " now owes " << owedAmount << std::endl;
    }

    void removeAmountOwed(double amount)
    {
        owedAmount -= amount;
    }

private:
    std::string name;
    int age;
    std::string contactInfo;
    std::string passportNo;
    double owedAmount;
};

#endif
