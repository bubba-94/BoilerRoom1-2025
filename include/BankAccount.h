#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT

#include <map>
#include <iostream>
#include <unordered_set>
#include <vector>

class User;
class BankAccount
{
private:
    int balance{};
    int accountId;
    std::unordered_set<int> userIDs;
    void printWithdraw(int amount);
    std::vector<int> transactions{};

public:
    BankAccount(int accountId) : balance(balance), accountId(accountId) {}
    void deposit(int amount);
    void withdraw(int amount);
    void addUser(int userID);
    int getBalance();
    std::unordered_set<int> getUserIDs();
    std::vector<int> getTransactions();
    int BankAccount::TotalWithdraw(); 
    int BankAccount::TotalDeposits();
};

#endif