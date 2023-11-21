#ifndef __CURRENT_ACCOUNT_HPP__
#define __CURRENT_ACCOUNT_HPP__

#include "account.hpp"

class CurrentAccount : public Account {
public:
    CurrentAccount(std::string accountNumber, std::string accountHolder, double balance, double overdraftLimit)
        : Account(accountNumber, accountHolder, balance), _overdraftLimit(overdraftLimit) {}

    virtual void displayDetails() noexcept override;
    virtual double withdraw(double amount) noexcept override;
    [[nodiscard]] CurrentAccount operator+(Account &rhs);
private:
    friend std::ostream& operator<<(std::ostream &os, const CurrentAccount &a);
private:
    double _overdraftLimit = 0.0;
};

#endif // __CURRENT_ACCOUNT_HPP__