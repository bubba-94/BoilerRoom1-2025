#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT
#include <iostream>

class BankAccount
{
private:
    int balance;
    int accountId;

public:
    BankAccount();
    BankAccount(int balance, int accountId) : balance(balance), accountId(accountId) {}
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance();
    int getAccountID();
};
#endif