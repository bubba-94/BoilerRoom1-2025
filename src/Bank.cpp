#include <iostream>
#include <map>
#include "BankAccount.h"
#include "Bank.h"
#include "random.h"
#include "User.h"
#include "coutMutex.h"

Bank::Bank()
{
    nextAccountID = 1;
}

void Bank::addUser(int userID, const std::string &name)
{
    Users[userID] = User(userID, name);
}

BankAccount Bank::getBankAccount(int accountID)
{
    auto it = BankAccounts.find(accountID);
    if (it != BankAccounts.end())
    {
        return it->second; // returns the BankAccount Object
    }
    else
    {
        // throw ERROR
        std::cerr << "Account ID " << accountID << " not found!" << std::endl;
        throw std::runtime_error("Account not found"); // error handleing
    }
}

// requires a userID
void Bank::addBankAccount(int userID)
{
    int amount = 0;
    // int amount = randomAmount(); // it was messing with the tast cases thereby has been commentated out
    int id = nextAccountID++; // nextAccountID is just a counter that increases
    BankAccount newAccount(amount, id, userID);
    BankAccounts.insert(std::make_pair(id, newAccount)); // insert a new account
    // just debug message
    printBankAccountCreation(userID, id);
}
void Bank::printBankAccountCreation(int userID, int id)
{
    std::lock_guard<std::mutex> guard(coutMutex);
    std::cout << "created Bank Account with " << "ID " << id << " and User ID " << userID << std::endl;
}

// ID for bank account
void Bank::displayBankAccount(int accountID)
{
    auto it = BankAccounts.find(accountID);
    if (it != BankAccounts.end())
    {
        std::lock_guard<std::mutex> guard(coutMutex);
        std::cout << "balance is " << it->second.getBalance() << " for account " << accountID << std::endl;
    }
}
// ID for User
void Bank::displayUserID(int accountID)
{
    auto it = BankAccounts.find(accountID);
    if (it != BankAccounts.end())
    {
        std::lock_guard<std::mutex> guard(coutMutex);
        std::cout << "The owner of the account " << accountID << " is User ID " << it->second.getUserID() << std::endl;
    }
}
void Bank::depositToAccount(int accountID, int amount)
{
    auto it = BankAccounts.find(accountID);
    it->second.deposit(amount);
    printDeposit(accountID, amount);
}
void Bank::printDeposit(int accountID, int amount)
{
    std::lock_guard<std::mutex> guard(coutMutex);
    std::cout << "deposited " << amount << " to the account " << accountID << std::endl;
}

void Bank::withdrawFromAccount(int accountID, int amount)
{
    auto it = BankAccounts.find(accountID);
    it->second.withdraw(amount);
    printWithdrawal(accountID, amount);
}
void Bank::printWithdrawal(int accountID, int amount)
{
    std::lock_guard<std::mutex> guard(coutMutex);
    std::cout << "Withdrew " << amount << " to the account " << accountID << std::endl;
}

void Bank::viewAccount(int accountID)
{
    auto it = BankAccounts.find(accountID);
    std::lock_guard<std::mutex> guard(coutMutex);
    std::cout << "the amount of balance ID " << accountID << " owns is " << it->second.getBalance() << std::endl;
}