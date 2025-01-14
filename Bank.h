#ifndef BANK_H
#define BANK_H

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
};

#endif