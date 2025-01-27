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

//
void Bank::addUser(int userID, const User &user)
{
    Users[userID] = User(userID);
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
void Bank::addBankAccount(const std::vector<int> &userIDs)
{
    int amount = 0;
    // int amount = randomAmount(); // it was messing with the tast cases thereby has been commentated out
    int AccountID = nextAccountID++; // nextAccountID is just a counter that increases
    // doesnt suit
    BankAccount newAccount(AccountID);
    for (int userID : userIDs)
    {
        // in realtiy it should be bank account that has the adduser class rather then bank
        newAccount.addUser(userID);
    }
    BankAccounts.emplace(AccountID, newAccount);
    // just debug message
    printBankAccountCreation(userIDs, AccountID);
}
void Bank::printBankAccountCreation(const std::vector<int> &userIDs, int AccountID)
{
    std::lock_guard<std::mutex> guard(coutMutex);
    std::cout << "created Bank Account with " << "ID " << AccountID << " and User IDs ";
    for (int userID : userIDs)
    {
        std::cout << userID << " ";
    }
    std::cout << std::endl;
}

// ID for bank account
void Bank::displayUserID(int accountID)
{
    auto it = BankAccounts.find(accountID);
    if (it != BankAccounts.end())
    {
        std::lock_guard<std::mutex> guard(coutMutex);
        std::unordered_set<int> userIDs = it->second.getUserIDs();

        // Print the user's associated with this account
        std::cout << "Associated user(s) for account " << accountID << ": ";
        for (int userID : userIDs) // Iterate through the user IDs
        {
            std::cout << userID << " "; // Print each user ID
        }
        std::cout << std::endl;
    }
}
void Bank::displayBankAccount(int accountID) // currently displays both balance and users associated do we want this?
{
    auto it = BankAccounts.find(accountID); // Find the account by accountID
    if (it != BankAccounts.end())           // Check if the account exists
    {
        std::lock_guard<std::mutex> guard(coutMutex); // Protect console output with mutex

        // Print the balance of the account
        std::cout << "Balance is " << it->second.getBalance() << " for account " << accountID << std::endl;

        // Retrieve the associated user IDs for this account
        std::unordered_set<int> userIDs = it->second.getUserIDs();

        // Print the user's associated with this account
        std::cout << "Associated user(s) for account " << accountID << ": ";
        for (int userID : userIDs) // Iterate through the user IDs
        {
            std::cout << userID << " "; // Print each user ID
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Account with ID " << accountID << " not found!" << std::endl;
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

void Bank::viewAccountBalance(int accountID)
{
    auto it = BankAccounts.find(accountID);
    std::lock_guard<std::mutex> guard(coutMutex);
    std::cout << "the amount of balance ID " << accountID << " owns is " << it->second.getBalance() << std::endl;
}