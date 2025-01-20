#include <iostream>
#include "BankAccount.h"
#include <coutMutex.h>

void BankAccount::deposit(int amount)
{
    balance = balance + amount;
}
void BankAccount::withdraw(int amount)
{
    if (amount > balance)
    {
        printWithdraw(amount);
        return;
    }
    balance = balance - amount;
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
int BankAccount::getUserID()
{
    return userID;
}
