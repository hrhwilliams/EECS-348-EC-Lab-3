#ifndef __SAVINGS_ACCOUNT_HPP__
#define __SAVINGS_ACCOUNT_HPP__

#include "account.hpp"

class SavingsAccount : public Account {
public:
    SavingsAccount(std::string accountNumber, std::string accountHolder, double balance, double interestRate)
        : Account(accountNumber, accountHolder, balance), _interestRate(interestRate) {}
    
    virtual void displayDetails() noexcept override;
    [[nodiscard]] SavingsAccount operator+(Account &rhs);
private:
    friend std::ostream& operator<<(std::ostream &os, const SavingsAccount &a);
private:
    double _interestRate = 0.0;
};

#endif // __SAVINGS_ACCOUNT_HPP__