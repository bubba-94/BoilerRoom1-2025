#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT

class BankAccount
{
private:
    int balance;
    int accountId;

public:
    // mabye dont want the constructor here but also defined in the cpp file?
    BankAccount(int balance, int accountId) : balance(balance), accountId(accountId) {}
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance();
};

#endif