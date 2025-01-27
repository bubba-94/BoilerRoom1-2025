#ifndef BANK_H
#define BANK_H

#include <map>
#include <iostream>
#include <vector>

class BankAccount;
class User;

class Bank
{
private:
    // key, BankAccount
    std::map<int, User> Users;
    std::map<int, BankAccount> BankAccounts;
    int nextAccountID;

public:
    // Bank(std::map<int, BankAccount> BankAccounts) : BankAccounts(BankAccounts) {}
    Bank();
    BankAccount getBankAccount(int accountID);
    void addBankAccount(const std::vector<int> &userIDs);
    void displayUserID(int UserID);
    void displayBankAccount(int accountID);
    void depositToAccount(int accountID, int amount);
    void withdrawFromAccount(int accountID, int amount);
    void printWithdrawal(int accountID, int amount);
    void printBankAccountCreation(const std::vector<int> &userIDs, int AccountID);
    void viewAccountBalance(int accountID);
    void printDeposit(int accountID, int amount);
    void addUser(int userID, const User &user);
    void transferAmountToBankAccount(int accountID, int accountID2, int amount);
};

#endif