#include <iomanip>

#include "savings_account.hpp"

void SavingsAccount::displayDetails() noexcept {
    std::cout << std::fixed << std::showpoint;
    std::cout << "Account Details for Savings Account (ID: " << _accountNumber << "):\n"
              << "  Holder: " << _accountHolder << "\n"
              << "  Balance: $" << std::setprecision(2) << _balance << "\n"
              << "  Interest Rate: " << _interestRate << "%" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const SavingsAccount &a) {
    return os << std::fixed << std::showpoint
              << "Account Details for Savings Account (ID: " << a._accountNumber << "):\n"
              << "  Holder: " << a._accountHolder << "\n"
              << "  Balance: $" << std::setprecision(2) << a._balance << "\n"
              << "  Interest Rate: " << a._interestRate << "%" << std::endl;
}

SavingsAccount SavingsAccount::operator+(Account &rhs) {
    SavingsAccount new_account = SavingsAccount(_accountNumber, _accountHolder, _balance, _interestRate);
    new_account.deposit(rhs.withdraw_all());
    return new_account;
}
