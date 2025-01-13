#include <iostream>
#include <map>
#include "BankAccount.h"
#include "Bank.h"

void Bank::addBankAccount(int amount)
{
    int id;
    // Exists so that a new key/id value is always generated for the map whenever inserting a user.
    for (std::map<int, BankAccount>::iterator it = BankAccounts.begin(); it != BankAccounts.end(); ++it)
    {
        // auto last = BankAccounts.end();
        auto last = std::prev(BankAccounts.end());
        // why does this work what does first even imply?
        int lastKey = last->first;
        id = lastKey + 1;
    }
    BankAccounts.insert(std::make_pair(id, BankAccount(amount, id)));
}
void Bank::displayBankAccount(int id)
{
    for (std::map<int, BankAccount>::iterator it = BankAccounts.begin(); it != BankAccounts.end(); ++it)
    {
        int key = it->first;
        if (key == id)
        {
            std::cout << BankAccounts[key].getBalance();
        }
    }
}
