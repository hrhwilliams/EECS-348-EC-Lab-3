#include <iomanip>

#include "current_account.hpp"

void CurrentAccount::displayDetails() noexcept {
    std::cout << std::fixed << std::showpoint;
    std::cout << "Account Details for Current Account (ID: " << _accountNumber << "):\n"
              << "  Holder: " << _accountHolder << "\n"
              << "  Balance: $" << std::setprecision(2) << _balance << "\n"
              << "  Overdraft Limit: $" << _overdraftLimit << std::endl;
}

std::ostream& operator<<(std::ostream &os, const CurrentAccount &a) {
    return os << std::fixed << std::showpoint
              << "Account Details for Savings Account (ID: " << a._accountNumber << "):\n"
              << "  Holder: " << a._accountHolder << "\n"
              << "  Balance: $" << std::setprecision(2) << a._balance << "\n"
              << "  Overdraft Limit: $" << a._overdraftLimit << "%" << std::endl;
}

double CurrentAccount::withdraw(double amount) noexcept {
    if (amount < (_balance + _overdraftLimit)) {
        _balance -= amount;
        return amount;
    }

    return 0.0;
}

CurrentAccount CurrentAccount::operator+(Account &rhs) {
    CurrentAccount new_account = CurrentAccount(_accountNumber, _accountHolder, _balance, _overdraftLimit);
    new_account.deposit(rhs.withdraw_all());
    return new_account;
}
