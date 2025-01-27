#include <iostream>
#include "BankAccount.h"
#include <coutMutex.h>

BankAccount::BankAccount(int balance, int accountId) : balance(balance), accountId(accountId)
{
    locked = false;     // initalize locked as false
    maxAmount = 100000; // initialize max amount as 100000 for the account
}

void BankAccount::deposit(int amount)
{
    balance = balance + amount;
}
void BankAccount::withdraw(int amount)
{
    // checks whether the transaction is valid
    locked = maxAmountTransference(amount);

    if (locked == true)
    {
        return;
    }

    if (amount > balance)
    {
        printWithdraw();
        return;
    }
    balance = balance - amount;
}
void BankAccount::printWithdraw() // only exists within this cpp file
{
    std::lock_guard<std::mutex> guard(coutMutex);
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
    locked = maxAmountTransference(amount);

    if (locked == true)
    {
        return;
    }

    if (amount > this->balance)
    {
        printWithdraw();
        return;
    }

    // may want a comment here what amounts got transfered
    this->balance -= amount; // "this" connects to the current object its on.
    accountID.balance += amount;
}

bool BankAccount::maxAmountTransference(int amount)
{

    if (amount > maxAmount)
    {
        // may want a comment here that the transaction failed
        return true;
    }
    maxAmount -= amount;
    return false;
}
int BankAccount::TotalWithdraw()
{
    int total = 0;
    for (int i = 0; i < this->transactions.size(); i++)
    {
        if (this->transactions[i] < 0)
        {
            total += this->transactions[i];
        }
    }
    return total;
}

int BankAccount::TotalDeposits()
{
    int total = 0;
    for (int i = 0; i < this->transactions.size(); i++)
    {
        if (this->transactions[i] < 0)
        {
            total += this->transactions[i];
        }
    }
    return total;
}