#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <map>
#include <memory>
#include <string>

class Bank {
    private:
        std::map<int, std:: shared_ptr<Account>> accounts;
    
    public:
    void createAccount(int accNum, const std::string &name, std::string &email,
                        const std::string &phone, double initialBalance, const std::string &pin);
    
    void showAllAccounts() const;

    std::shared_ptr<Account> getAccount(int accNum);
};

#endif