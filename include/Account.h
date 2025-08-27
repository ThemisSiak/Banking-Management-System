#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
    private:
        int accountNumber;
        std::string name;
        std::string email;
        std::string phone;
        double balance;
        std::string pin;
    
    public:
        Account(int accNum, const std::string &accountName, const std::string &accountEmail,
                const std::string &accountPhone, double initialBalance, const std::string &accountPin);

        int getAccountNumber() const;
        std::string getName() const;
        double getBalance() const;

        void deposit(double amount);
        void showDetails() const;
        
        bool withdraw(double amount);
        bool validatePin(const std::string &inputPin) const;

};

#endif