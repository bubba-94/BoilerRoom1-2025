#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <map>
#include <iostream>
#include <unordered_set>
#include <vector>

class User;
class BankAccount
{
private:
    int balance;
    int accountId;
    bool lockAccount;
    int maxAmount;
    std::vector<int> transactions{};
    std::unordered_set<int> userIDs;
    void printInsufficientFundsMessage(); // only exists within this cpp file

public:
    BankAccount(int balance, int accountId);
    void deposit(int amount);
    void withdraw(int amount);
    void addUser(int userID);
    int getBalance();
    std::unordered_set<int> getUserIDs(); // no defintion right now
    std::vector<int> getTransactions();   // no defintion right now
    void logWithdraw(int amount);
    void logDeposits(int amount);
    int getTotalDeposits();
    int getTotalWithdraws();
    void transferAmount(BankAccount &accountID, int amount);
    bool isTransferAllowed(int amount);
};

#endif