#include "Bank.h"
#include <iostream>

void Bank::createAccount(int accNum, const std::string &name, std::string &email,
                        const std::string &phone, double initialBalance, const std::string &pin){
    if (accounts.find(accNum) != accounts.end()) {
        std::cout << "Account number already exists.\n";
        return;
    }
    accounts[accNum] = std::make_shared<Account>(accNum, name, email, phone, initialBalance, pin);
    std::cout << "Account created!! \n";
}

void Bank::showAllAccounts() const {
    if (accounts.empty()) {
        std::cout << "No accounts available.\n";
        return;
    }

    for (const auto &entry : accounts) {
        entry.second->showDetails();
    }
}

std::shared_ptr<Account> Bank::getAccount(int accNum) {
    auto it = accounts.find(accNum);
    if (it == accounts.end()) {
        std::cout << "Account not found.\n";
        return nullptr;
    }
    return it->second;
}