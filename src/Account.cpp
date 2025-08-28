#include "../include/Account.h"
#include <iostream>

Account::Account(int accNum, const std::string &accountName, const std::string &accountEmail,
                const std::string &accountPhone, double initialBalance, const std::string &accountPin)
            : accountNumber(accNum), name(accountName), email(accountEmail), phone(accountPhone),
            balance(initialBalance), pin(accountPin) {}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getName() const {
    return name;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if(amount<=0) {
        std::cout << "Invalid deposit amount. \n";
        return;
    }
    balance += amount;
    std::cout << "Deposited" << amount << "euros. New balance " << balance << " euros\n";
}

bool Account::withdraw(double amount) {
    if (amount <=0) {
        std::cout << "Invalid withdrawal amount.\n";
        return false;
    }
    if (amount > balance) {
        std::cout << "Insufficient balance.\n";
        return false;
    }
    balance -= amount;
    std::cout << "Withdrawn " << amount << " euros. New balance: " << balance << " euros.\n";
    return true;
}

void Account::showDetails() const {
    std::cout << "\n=== Account Details ===\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Phone: " << phone << "\n";
    std::cout << "Balance: " << balance << " euros.\n";
    std::cout << "========\n";
}

bool Account::validatePin(const std::string &inputPin) const {
    return inputPin == pin;
}