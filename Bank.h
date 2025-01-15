#ifndef BANK_H
#define BANK_H

#include <map>

class BankAccount;
class User;

class Bank
{
private:
    // key, BankAccount
    std::map<int, BankAccount> BankAccounts;
    std::map<int, User> Users;
    int nextAccountID;

public:
    // Bank(std::map<int, BankAccount> BankAccounts) : BankAccounts(BankAccounts) {}
    Bank();
    void addUser(int userID, const std::string &name);
    void addBankAccount(int userID);
    void displayUserID(int UserID);
    void displayBankAccount(int id);
    void depositToAccount(int accountID, int amount);
    void withdrawFromAccount(int accountID, int amount);
    void viewAccount(int ID);
};

#endif