#include <iostream>
#include "BankAccount.h"
#include <coutMutex.h>

void BankAccount::deposit(int amount)
{
    balance = balance + amount;
    this->transactions.emplace_back(amount);
}

void BankAccount::withdraw(int amount)
{
    if (amount > balance)
    {
        printWithdraw(amount);
        return;
    }
    balance = balance - amount;
    this->transactions.emplace_back(amount);
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

void BankAccount::printWithdraw(int amount) // only exists within this cpp file
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
