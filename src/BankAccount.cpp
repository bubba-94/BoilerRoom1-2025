#include <iostream>
#include "BankAccount.h"
#include <coutMutex.h>

BankAccount::BankAccount(int balance, int accountId) : balance(balance), accountId(accountId)
{
    lockAccount = false; // initalize locked as false
    maxAmount = 100000;  // initialize max amount as 100000 for the account
}

void BankAccount::deposit(int amount)
{
    balance = balance + amount;
}
void BankAccount::withdraw(int amount)
{
    // checks whether the transaction is valid
    lockAccount = isTransferAllowed(amount);

    if (lockAccount == true)
    {
        return;
    }

    if (amount > balance)
    {
        printInsufficientFundsMessage();
        return;
    }
    balance = balance - amount;
}
void BankAccount::printInsufficientFundsMessage() // only exists within this cpp file
{
    std::lock_guard<std::mutex> guard(coutMutex); // guards the std::cout from race conditions
    std::cout << "insufficient amount detected for withdrawal, returning" << std::endl;
}

int BankAccount::getBalance()
{
    return balance;
}
std::unordered_set<int> BankAccount::getUserIDs()
{
    return userIDs;
}
void BankAccount::addUser(int userID)
{
    userIDs.insert(userID);
}
// transfers an amount between two bank accounts (possibly may need to be reworked to accept an ID rather then an object)
// it might be fairly bad pratice making a new function called transfer amount rather then using the preexisting functions
void BankAccount::transferAmount(BankAccount &accountID, int amount)
{
    // checks whether the transaction is valid
    lockAccount = isTransferAllowed(amount);

    if (lockAccount == true)
    {
        return;
    }

    if (amount > this->balance)
    {
        printInsufficientFundsMessage();
        return;
    }

    // Withdraw from the current account
    this->withdraw(amount);

    // Deposit into the target account
    accountID.deposit(amount);
}

bool BankAccount::isTransferAllowed(int amount)
{

    if (amount > maxAmount)
    {
        // may want a comment here that the transaction failed
        return true;
    }
    maxAmount -= amount;
    return false;
}

// added the parameter int amount to increase the clarity in what the function does
int BankAccount::logWithdraw(int amount)
{
    if (amount > 0) // error handleing
    {
        transactions.push_back(-amount);
    }
}

// added the parameter int amount to increase the clarity in what the function does
// removed majority of the code, refactorizing it
int BankAccount::logDeposits(int amount)
{
    if (amount > 0) // error handleing
    {
        transactions.push_back(amount);
    }
}

// Returns the total amount of all deposits
int BankAccount::getTotalDeposits()
{
    int total = 0;
    for (int amount : transactions)
    {
        if (amount > 0)
        { // sums up deposits
            total += amount;
        }
    }
    return total;
}

// Returns the total amount of all withdraws
int BankAccount::getTotalWithdraws()
{
    int total = 0;
    for (int amount : transactions)
    {
        if (amount < 0)
        { // sums up deposits with a negative value
            total += -amount;
        }
    }
    return total;
}