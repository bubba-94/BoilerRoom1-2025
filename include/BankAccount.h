#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT

class BankAccount
{
private:
    int balance;
    int accountId;
    int userID;

public:
    // mabye dont want the constructor here but also defined in the cpp file?
    // requires a balance, accountid, userid
    BankAccount(int balance, int accountId, int userID) : balance(balance), accountId(accountId), userID(userID) {}
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance();
    int getUserID();
};

#endif