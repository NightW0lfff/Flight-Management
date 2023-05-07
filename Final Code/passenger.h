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

    std::string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    std::string getContactInfo() const
    {
        return contactInfo;
    }

    std::string getPassportNo() const
    {
        return passportNo;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setContactInfo(std::string contactInfo)
    {
        this->contactInfo = contactInfo;
    }

    void setPassportNo(std::string passportNo)
    {
        this->passportNo = passportNo;
    }

    void addAmountOwed(double amount)
    {
        owedAmount += amount;
    }

    void removeAmountOwed(double amount)
    {
        owedAmount -= amount;
    }

    virtual double getOwedAmount() const = 0;
    virtual std::string getStatus() const = 0;
    virtual double getDiscountRate() = 0;
    virtual void setStatus(std::string status) = 0;

private:
    std::string name;
    int age;
    std::string contactInfo;
    std::string passportNo;
    double owedAmount;
};

class VIPPassenger : public Passenger
{
public:
    VIPPassenger(std::string name, int age, std::string contactInfo, std::string passportNo = "", double owedAmount = 0.0, std::string status = "")
        : Passenger(name, age, contactInfo, passportNo, owedAmount), status(status) {}

    void displayPassengerDetails() const
    {
        Passenger::displayPassengerDetails();
        std::cout << "Status: " << status << std::endl;
        std::cout << std::endl;
    }

    std::string getStatus() const override
    {
        return status;
    }

    double getOwedAmount() const override
    {
        return owedAmount;
    }

    void setStatus(std::string status) override
    {
        this->status = status;
    }

    double getDiscountRate() override
    {
        if (status == "SILVER")
        {
            return 0.05;
        }
        else if (status == "GOLD")
        {
            return 0.1;
        }
        else if (status == "PLATINUM")
        {
            return 0.2;
        }
        return 0.0;
    }

private:
    std::string status;
    double owedAmount;
};

#endif
