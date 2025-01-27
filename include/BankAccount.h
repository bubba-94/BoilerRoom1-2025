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
    bool locked;
    int maxAmount;
    std::vector<int> transactions{};
    std::unordered_set<int> userIDs;
    void printWithdraw(); // only exists within this cpp file

public:
    // mabye dont want the constructor here but also defined in the cpp file?
    // requires a balance, accountid, userid
    BankAccount(int balance, int accountId);
    void deposit(int amount);
    void withdraw(int amount);
    void addUser(int userID);
    int getBalance();
    std::unordered_set<int> getUserIDs(); // no defintion right now
    std::vector<int> getTransactions();   // no defintion right now
    int BankAccount::TotalWithdraw();
    int BankAccount::TotalDeposits();
    void transferAmount(BankAccount &accountID, int amount); // might not work because we are looking for ID's rather then objects
    bool maxAmountTransference(int amount);
};

#endif