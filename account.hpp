#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>
#include <string>

class Account {
public:
    virtual void displayDetails() noexcept = 0;
    virtual void deposit(double amount) noexcept;
    virtual double withdraw(double amount) noexcept;
    virtual double withdraw_all() noexcept;
protected:
    Account(std::string accountNumber, std::string accountHolder, double balance)
        : _accountNumber(accountNumber), _accountHolder(accountHolder), _balance(balance) {}
protected:
    std::string _accountNumber = "";
    std::string _accountHolder = "";
    double _balance = 0.0;
};

#endif // __ACCOUNT_HPP__