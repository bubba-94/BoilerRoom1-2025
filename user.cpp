#include <iostream>
#include <vector>
#include <BankAccount.h>
#include "User.h"

int User::getID()
{
    return userID;
}
std::string User::getName()
{
    return name;
}

void User::addAccount(BankAccount *bankAccount)
{
    ownedBankAccounts.push_back(bankAccount);
}

std::vector<BankAccount *> &User::getBankAccounts()
{
    return ownedBankAccounts;
}
