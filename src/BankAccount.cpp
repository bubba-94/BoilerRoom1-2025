#include <iostream>
#include "BankAccount.h"

void BankAccount::deposit(int amount)
{
    balance = balance + amount;
}
void BankAccount::withdraw(int amount)
{
    balance = balance - amount;
}
int BankAccount::getBalance()
{
    return balance;
}
int BankAccount::getUserID()
{
    return userID;
}
