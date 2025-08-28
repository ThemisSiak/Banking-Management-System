#include "../include/Bank.h"
#include <iostream>

void createNewAccount(Bank &bank) {
    int accNum;
    std::string name, email, phone, pin;
    double balance;

    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cin.ignore();

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Email: ";
    std::getline(std::cin, email);

    std::cout << "Enter Phone: ";
    std::getline(std::cin, phone);

    std::cout << "Enter Initial Balance: ";
    std::cin >> balance;

    std::cout << "Set PIN: ";
    std::cin >> pin;

    bank.createAccount(accNum,
    name, email, phone, balance, pin);
}

void depositMoney(Bank &bank) {
    int accNum;
    double amount;

    std::cout << "\n Enter Account Number: ";
    std::cin >> accNum;

    std::shared_ptr<Account> acc = bank.getAccount(accNum);
    if (!acc) return;

    std::cout << "\n Enter Amount to Deposit: ";
    std::cin >> amount;
    acc->deposit(amount);
}

void withdrawMoney(Bank &bank){
    int accNum;
    double amount;
    std::string pin;

    std::cout << "Enter account number";
    std::cin >> accNum;

    std::shared_ptr<Account> acc = bank.getAccount(accNum);
    if (!acc) return;

    std::cout << "\n Enter Amount to Withdraw: ";
    std::cin >> amount;
    acc->withdraw(amount);
}

void showAccountDetails(Bank &bank){
    int accNum;
    std::cout << "Enter account number: ";
    std::cin >> accNum;

    std::shared_ptr<Account> acc = bank.getAccount(accNum);
    if (acc) {
        acc->showDetails();
    }
}

int main() {
    Bank bank;

    int choice;
    do {
        std::cout << "\n=== Banking System ===\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Show Account Details\n";
        std::cout << "5. Show All Accounts\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

    switch (choice){
    case 1:
        createNewAccount(bank);
        break;
    case 2:
        depositMoney(bank);
        break;
    case 3:
        withdrawMoney(bank);
        break;
    case 4:
        showAccountDetails(bank);
        break;
    case 5:
        bank.showAllAccounts();
        break;
    case 0:
        std::cout <<"Exiting.\n";
        break;
    default:
        std::cout << "Invalid choice.\n";
    }
    }while (choice !=0);

    return 0;
}