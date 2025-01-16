#include <iostream>
#include <map>
#include "BankAccount.h"
#include "Bank.h"
#include "random.h"
#include "User.h"

Bank::Bank()
{
    nextAccountID = 1;
}

void Bank::addUser(int userID, const std::string &name)
{
    Users[userID] = User(userID, name);
}

// requires a userID
void Bank::addBankAccount(int userID)
{
    int amount = randomAmount();
    int id = nextAccountID++; // nextAccountID is just a counter that increases
    BankAccount newAccount(amount, id, userID);
    BankAccounts.insert(std::make_pair(id, newAccount)); // insert a new account
    // just debug message
    std::cout << "created Bank Account with " << "ID " << id << " and User ID " << userID << std::endl;
}
// ID for bank account
void Bank::displayBankAccount(int id)
{
    auto it = BankAccounts.find(id);
    if (it != BankAccounts.end())
    {
        std::cout << "random balance generated is " << it->second.getBalance() << std::endl;
    }
}
// ID for User
void Bank::displayUserID(int ID)
{
    auto it = BankAccounts.find(ID);
    if (it != BankAccounts.end())
    {
        std::cout << "The owner of this account is User ID " << it->second.getUserID() << std::endl;
    }
}
void Bank::depositToAccount(int ID, int amount)
{
    auto it = BankAccounts.find(ID);
    it->second.deposit(amount);
    std::cout << "deposited " << amount << " to the account" << std::endl;
}
void Bank::withdrawFromAccount(int ID, int amount)
{
    auto it = BankAccounts.find(ID);
    it->second.withdraw(amount);
    std::cout << "Withdrew " << amount << " to the account" << std::endl;
}
void Bank::viewAccount(int ID)
{
    auto it = BankAccounts.find(ID);
    std::cout << "the amount of balance ID " << ID << " owns is " << it->second.getBalance() << std::endl;
}