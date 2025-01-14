#include <iostream>
#include <map>
#include "BankAccount.h"
#include "Bank.h"
#include "random.h"

// this function is currently inefficient and can be reworked.
void Bank::addBankAccount()
{
    int amount = randomAmount();
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
    auto it = BankAccounts.find(id);
    if (it != BankAccounts.end())
    {
        std::cout << it->second.getBalance() << std::endl;
    }
}
