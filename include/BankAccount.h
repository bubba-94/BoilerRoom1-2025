#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT

#include <map>
#include <iostream>
#include <unordered_set>

// could need a reference to userIDs within bankaccount use a map instead of the int userid we currently use and define the function addUser

class User;
class BankAccount
{
private:
    int balance;
    int accountId;
    std::unordered_set<int> userIDs;
    void printWithdraw(int amount); // only exists within this cpp file

public:
    // mabye dont want the constructor here but also defined in the cpp file?
    // requires a balance, accountid, userid
    BankAccount(int balance, int accountId) : balance(balance), accountId(accountId) {}
    void deposit(int amount);
    void withdraw(int amount);
    void addUser(int userID);
    int getBalance();
    std::unordered_set<int> getUserIDs();
};

#endif