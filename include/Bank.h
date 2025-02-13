#ifndef BANK_H
#define BANK_H

#include <map>
#include <iostream>
#include <vector>
#include <unordered_set>

class BankAccount;
class User;

class Bank
{
private:
    // key, BankAccount
    static Bank bankInstance; // a single instance of the bank class, for the singleton design pattern
    std::map<int, User> registeredUsers;
    std::map<int, BankAccount> activeBankAccounts;
    int nextAccountID = 1;

public:
    // delete copy constructors to prevent copies of the singleton existing
    Bank();
    Bank(const Bank &) = delete;
    Bank &operator=(const Bank &) = delete;

    // method to get the instance that exists of the bank
    static Bank &getBankInstance();

    // gets or adds values
    BankAccount getBankAccount(int accountID);
    void addBankAccount(const std::vector<int> &userIDs);
    void depositToAccount(int accountID, int amount);
    void withdrawFromAccount(int accountID, int amount);
    void addUser(int userID, const User &user);
    void transferAmountToBankAccount(int accountID, int accountID2, int amount);

    // Exclusively used to print out values
    void viewAccountBalance(int accountID);
    void displayUserID(int UserID);
    void displayBankAccount(int accountID);
    void printDeposit(int accountID, int amount);
    void printWithdrawal(int accountID, int amount);
    void printBankAccountCreation(const std::vector<int> &userIDs, int AccountID);
};

#endif